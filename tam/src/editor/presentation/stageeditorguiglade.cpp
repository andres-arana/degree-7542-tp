#include "stageeditorguiglade.h"
#include "design/elements/ball.h"
#include "design/elements/exitarea.h"
#include "design/elements/fixedpoint.h"
#include "design/elements/obstacle.h"
#include "utils/stringutils.h"
#include "controllers/ballcreatorinputhandler.h"
#include "controllers/exitareacreatorinputhandler.h"
#include "controllers/fixedpointcreatorinputhandler.h"
#include "controllers/obstaclecreatorinputhandler.h"
#include "controllers/moveinputhandler.h"
#include "controllers/deleteinputhandler.h"
#include "views/blueprintrenderer.h"
#include "core/vector2d.h"
#include "views/design/elementcontainerdesignrenderer.h"
#include "views/move/movepointsrenderer.h"

using editor::presentation::StageEditorGuiGlade;
using common::utils::StringUtils;
using ui::controllers::BallCreatorInputHandler;
using ui::controllers::ExitAreaCreatorInputHandler;
using ui::controllers::FixedPointCreatorInputHandler;
using ui::controllers::ObstacleCreatorInputHandler;
using ui::controllers::MoveInputHandler;
using ui::controllers::DeleteInputHandler;
using ui::views::GameRenderArea;
using ui::views::BlueprintRenderer;
using ui::views::design::ElementContainerDesignRenderer;

using namespace game::core;
using namespace game::design;
using namespace game::design::elements;
using namespace ui::views::design;
using namespace ui::views::move;

#define EDITOR_TITLE "Editor de Escenarios"
#define BALL_RADIO_NAME "ballRadio"
#define EXIT_AREA_RADIO_NAME "exitAreaRadio"
#define FIXED_POINT_RADIO_NAME "fixedPointRadio"
#define OBSTACLE_RADIO_NAME "obstacleRadio"
#define MOVE_RADIO_NAME "moveRadio"
#define DELETE_RADIO_NAME "deleteRadio"

StageEditorGuiGlade::StageEditorGuiGlade(Gtk::Main &kit): m_StageEditorHandler(*this), mainWindow(NULL), gameAreaController(gameRenderArea) {
	m_RefXml = Gnome::Glade::Xml::create("view/editor.glade");
	m_RefXml->get_widget("editorWindow", mainWindow);
	this->initWidgets();
	this->bindSignals();
	kit.run(*mainWindow);
}

StageEditorGuiGlade::~StageEditorGuiGlade() {
	delete mainWindow;
}

void StageEditorGuiGlade::initWidgets() {
	Gtk::Button* pButton;
	// Inicializacion de newButton
	pButton = NULL;
	m_RefXml->get_widget("newButton", pButton);
	if (pButton) pButton->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &StageEditorGuiGlade::onNewStageAction), "newButton"));
	// Inicializacion de openButton
	pButton = NULL;
	m_RefXml->get_widget("openButton", pButton);
	if (pButton) pButton->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &StageEditorGuiGlade::onOpenStageAction), "openButton"));
	// Inicializacion de saveAsButton
	pButton = NULL;
	m_RefXml->get_widget("saveAsButton", pButton);
	if (pButton) pButton->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &StageEditorGuiGlade::onSaveStageAsAction), "saveAsButton"));
	// Inicializacion de saveButton
	pButton = NULL;
	m_RefXml->get_widget("saveButton", pButton);
	if (pButton) pButton->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this, &StageEditorGuiGlade::onSaveStageAction), "saveButton"));

	this->m_RefXml->get_widget(BALL_RADIO_NAME, this->ballRadio);
	this->ballRadio->set_mode(false);
	Gtk::RadioButton::Group group = this->ballRadio->get_group();

	this->m_RefXml->get_widget(EXIT_AREA_RADIO_NAME, this->exitAreaRadio);
	this->exitAreaRadio->set_mode(false);
	this->exitAreaRadio->set_group(group);

	this->m_RefXml->get_widget(FIXED_POINT_RADIO_NAME, this->fixedPointRadio);
	this->fixedPointRadio->set_mode(false);
	this->fixedPointRadio->set_group(group);

	this->m_RefXml->get_widget(OBSTACLE_RADIO_NAME, this->obstacleRadio);
	this->obstacleRadio->set_mode(false);
	this->obstacleRadio->set_group(group);

	this->m_RefXml->get_widget(MOVE_RADIO_NAME, this->moveRadio);
	this->moveRadio->set_mode(false);
	this->moveRadio->set_group(group);

	this->m_RefXml->get_widget(DELETE_RADIO_NAME, this->deleteRadio);
	this->deleteRadio->set_mode(false);
	this->deleteRadio->set_group(group);

	Gtk::Alignment* gamePanelAlignment = NULL;
	m_RefXml->get_widget("gamePanelAlignment", gamePanelAlignment);
	gamePanelAlignment->add(this->gameRenderArea);
	gamePanelAlignment->show_all();

	gameRenderArea.addRendererToLayer(GameRenderArea::BackgroundLayer, new BlueprintRenderer());
	gameRenderArea.addRendererToLayer(GameRenderArea::ElementDesignLayer, new ElementContainerDesignRenderer(m_StageEditorHandler.getElementContainer()));
	gameRenderArea.addRendererToLayer(GameRenderArea::MovePointLayer, new MovePointsRenderer(m_StageEditorHandler.getElementContainer()));

	// Inicializacion de fileChooserButton
	Gtk::FileChooserButton* pFileChooserButton = NULL;
	m_RefXml->get_widget("filechooserbutton", pFileChooserButton);
	if (pFileChooserButton) {
		Gtk::FileFilter imageFilter;
		imageFilter.set_name("Imagenes");
		imageFilter.add_mime_type("image/*");
		pFileChooserButton->add_filter(imageFilter);
	}

	m_StageEditorHandler.getElementContainer().designModified().connect(sigc::mem_fun(gameRenderArea, &GameRenderArea::redraw));

	fillEntryNameCollection();
}

void StageEditorGuiGlade::bindSignals() {
	ballRadio->signal_toggled().connect(sigc::mem_fun(*this, &StageEditorGuiGlade::onBallRadioToggled));
	exitAreaRadio->signal_toggled().connect(sigc::mem_fun(*this, &StageEditorGuiGlade::onExitAreaRadioToggled));
	fixedPointRadio->signal_toggled().connect(sigc::mem_fun(*this, &StageEditorGuiGlade::onFixedPointRadioToggled));
	obstacleRadio->signal_toggled().connect(sigc::mem_fun(*this, &StageEditorGuiGlade::onObstacleRadioToggled));
	moveRadio->signal_toggled().connect(sigc::mem_fun(*this, &StageEditorGuiGlade::onMoveRadioToggled));
	moveRadio->set_active();
	deleteRadio->signal_toggled().connect(sigc::mem_fun(*this, &StageEditorGuiGlade::onDeleteRadioToggled));
}


void StageEditorGuiGlade::onBallRadioToggled() {
	if (ballRadio->get_active()) {
		gameAreaController.configureCurrentHandler(new BallCreatorInputHandler(m_StageEditorHandler.getElementFactory(), m_StageEditorHandler.getElementContainer()));
	}
}


void StageEditorGuiGlade::onExitAreaRadioToggled() {
	if (exitAreaRadio->get_active()) {
		gameAreaController.configureCurrentHandler(new ExitAreaCreatorInputHandler(m_StageEditorHandler.getElementFactory(), m_StageEditorHandler.getElementContainer()));
	}
}


void StageEditorGuiGlade::onFixedPointRadioToggled() {
	if (fixedPointRadio->get_active()) {
		gameAreaController.configureCurrentHandler(new FixedPointCreatorInputHandler(m_StageEditorHandler.getElementFactory(), m_StageEditorHandler.getElementContainer()));
	}
}


void StageEditorGuiGlade::onObstacleRadioToggled() {
	if (obstacleRadio->get_active()) {
		gameAreaController.configureCurrentHandler(new ObstacleCreatorInputHandler(m_StageEditorHandler.getElementFactory(), m_StageEditorHandler.getElementContainer()));
	}
}


void StageEditorGuiGlade::onMoveRadioToggled() {
	if (moveRadio->get_active()) {
		gameAreaController.configureCurrentHandler(new MoveInputHandler(gameRenderArea, m_StageEditorHandler.getElementContainer()));
	}
}


void StageEditorGuiGlade::onDeleteRadioToggled() {
	if (deleteRadio->get_active()) {
		gameAreaController.configureCurrentHandler(new DeleteInputHandler(m_StageEditorHandler.getElementContainer()));
	}
}


void StageEditorGuiGlade::showStageName(const std::string& name) {
	std::string title = EDITOR_TITLE;
	mainWindow->set_title(title + " - " + name);
}


void StageEditorGuiGlade::showMessageError(const std::string& message) {
	if (mainWindow) {
		Gtk::MessageDialog dialog(*mainWindow, message);
		dialog.run();
	}
}


bool StageEditorGuiGlade::showFolderChooserDialog(std::string& folder, bool saveMode) {
	Gtk::FileChooserDialog dialog("Seleccione la carpeta de destino", saveMode ? Gtk::FILE_CHOOSER_ACTION_CREATE_FOLDER : Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
	if (mainWindow) dialog.set_transient_for(*mainWindow);
	dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
	dialog.add_button(saveMode ? Gtk::Stock::SAVE : Gtk::Stock::OPEN, Gtk::RESPONSE_OK);
	bool aux = dialog.run() == Gtk::RESPONSE_OK;
	if (aux) folder = dialog.get_filename();
	return aux;
}


void StageEditorGuiGlade::fillEntryNameCollection() {
	m_NumericEntryNameCollection.push_back("maxTimeEntry");
	m_NumericEntryNameCollection.push_back("gravityEntry");
	m_NumericEntryNameCollection.push_back("aEntry");
	m_NumericEntryNameCollection.push_back("bEntry");
	m_NumericEntryNameCollection.push_back("cEntry");
	m_NumericEntryNameCollection.push_back("dEntry");
	m_NumericEntryNameCollection.push_back("maxTimeEntry");
	m_NumericEntryNameCollection.push_back("metalBarCountEntry");
	m_NumericEntryNameCollection.push_back("metalBarPriceEntry");
	m_NumericEntryNameCollection.push_back("plataformCountEntry");
	m_NumericEntryNameCollection.push_back("plataformPriceEntry");
	m_NumericEntryNameCollection.push_back("ropeCountEntry");
	m_NumericEntryNameCollection.push_back("ropePriceEntry");
	m_NumericEntryNameCollection.push_back("canvasTapeCountEntry");
	m_NumericEntryNameCollection.push_back("canvasTapePriceEntry");
	m_NumericEntryNameCollection.push_back("wheelCountEntry");
	m_NumericEntryNameCollection.push_back("wheelPriceEntry");
	m_NumericEntryNameCollection.push_back("wheelTorkeEntry");
	m_NumericEntryNameCollection.push_back("wheelDecayTimeEntry");
	m_NumericEntryNameCollection.push_back("massCountEntry");
	m_NumericEntryNameCollection.push_back("massPriceEntry");
	m_NumericEntryNameCollection.push_back("massEntry");
	m_NumericEntryNameCollection.push_back("rocketCountEntry");
	m_NumericEntryNameCollection.push_back("rocketPriceEntry");
	m_NumericEntryNameCollection.push_back("rocketStrengthEntry");
	m_NumericEntryNameCollection.push_back("rocketDecayTimeEntry");
	m_NumericEntryNameCollection.push_back("fixedPointCountEntry");
	m_NumericEntryNameCollection.push_back("fixedPointPriceEntry");

	m_SizeEntryNameCollection.push_back("metalBarMinSizeEntry");
	m_SizeEntryNameCollection.push_back("metalBarMaxSizeEntry");
	m_SizeEntryNameCollection.push_back("plataformMinSizeEntry");
	m_SizeEntryNameCollection.push_back("plataformMaxSizeEntry");
	m_SizeEntryNameCollection.push_back("ropeMinSizeEntry");
	m_SizeEntryNameCollection.push_back("ropeMaxSizeEntry");
	m_SizeEntryNameCollection.push_back("wheelMinSizeEntry");
	m_SizeEntryNameCollection.push_back("wheelMaxSizeEntry");
	m_SizeEntryNameCollection.push_back("canvasTapeMinSizeEntry");
	m_SizeEntryNameCollection.push_back("canvasTapeMaxSizeEntry");
	m_SizeEntryNameCollection.push_back("massMinSizeEntry");
	m_SizeEntryNameCollection.push_back("massMaxSizeEntry");
	m_SizeEntryNameCollection.push_back("fixedPointMinSizeEntry");
	m_SizeEntryNameCollection.push_back("fixedPointMaxSizeEntry");
}


bool StageEditorGuiGlade::validate() {
	std::string messageError = validateElementContainer();
	messageError += validateIsNumericEntries();
	messageError += validateSizeEntries();
	if (!messageError.empty()) showMessageError(messageError);
	return messageError.empty();
}


std::string StageEditorGuiGlade::validateElementContainer() {
	std::string messageError;

	const Ball* ball = m_StageEditorHandler.getElementContainer().getBall();
	if (!ball || ball->isErased()) messageError += "Debe incluir una pelota en el escenario.\n";

	bool hasExitArea = false;
	const ElementContainer::ExitAreaCollection &exitAreas = m_StageEditorHandler.getElementContainer().getExitAreaCollection();
	for (ElementContainer::ExitAreaIterator it = exitAreas.begin(); !hasExitArea && it != exitAreas.end(); ++it) {
		hasExitArea = !(*it)->isErased();
	}
	if (!hasExitArea) messageError += "Debe incluir al menos un area de salida en el escenario.\n";

	return messageError;
}


std::string StageEditorGuiGlade::validateIsNumericEntries() {
	std::string messageError;
	std::string entryValue;
	std::vector<std::string>::iterator it;
	for (it = m_NumericEntryNameCollection.begin(); it != m_NumericEntryNameCollection.end(); it++) {
		entryValue = getEntryValue(*it);
		if (!entryValue.empty() && !StringUtils::isNumeric(entryValue)) {
			messageError += "El campo \'" + getEntryTooltipText(*it) + "\' tiene un valor incorrecto.\n";
		}
	}
	return messageError;
}


std::string StageEditorGuiGlade::validateSizeEntries() {
	unsigned minsize = 10;
	std::string messageError;
	std::string entryValue;
	for (unsigned i = 0; i<m_SizeEntryNameCollection.size(); i++) {
		entryValue = getEntryValue(m_SizeEntryNameCollection[i]);
		if (!entryValue.empty()) {
			unsigned value = getEntryValue<unsigned>(m_SizeEntryNameCollection[i]);
			if (!StringUtils::isNumeric(entryValue)) {
				messageError += "El campo \'" + getEntryTooltipText(m_SizeEntryNameCollection[i]) + "\' tiene un valor incorrecto.\n";
			} else if (value < minsize) {
				messageError += "El campo \'" + getEntryTooltipText(m_SizeEntryNameCollection[i]) + "\' debe ser mayor o igual a " + StringUtils::numberToString<unsigned>(minsize) + ".\n";
			} else if (i % 2 && value < getEntryValue<unsigned>(m_SizeEntryNameCollection[i-1])) {
				messageError += "El campo \'" + getEntryTooltipText(m_SizeEntryNameCollection[i]) + "\' debe ser mayor o igual a '" + getEntryTooltipText(m_SizeEntryNameCollection[i-1]) + "\'.\n";
			}
		}
	}
	return messageError;
}


void StageEditorGuiGlade::clear() {
	mainWindow->set_title(EDITOR_TITLE);

	std::vector<std::string>::iterator it;
	for (it = m_NumericEntryNameCollection.begin(); it != m_NumericEntryNameCollection.end(); it++) {
		setEntryValue(*it, "");
	}
	for (it = m_SizeEntryNameCollection.begin(); it != m_SizeEntryNameCollection.end(); it++) {
		setEntryValue(*it, "");
	}

	Gtk::FileChooserButton* pFileChooserButton = NULL;
	m_RefXml->get_widget("filechooserbutton", pFileChooserButton);
	if (pFileChooserButton) pFileChooserButton->unselect_all();

	m_StageEditorHandler.getElementFactory().restore();
}


void StageEditorGuiGlade::onSaveStageAction(const Glib::ustring& text) {
	m_StageEditorHandler.saveStage();
}


void StageEditorGuiGlade::onSaveStageAsAction(const Glib::ustring& text) {
	m_StageEditorHandler.saveAsStage();
}


void StageEditorGuiGlade::onNewStageAction(const Glib::ustring& text) {
	m_StageEditorHandler.newStage();
}


void StageEditorGuiGlade::onOpenStageAction(const Glib::ustring& text) {
	m_StageEditorHandler.loadStage();
}


void StageEditorGuiGlade::setEntryValue(const std::string& name, std::string value) {
	Gtk::Entry* pEntry = NULL;
	m_RefXml->get_widget(name, pEntry);
	if (pEntry) pEntry->set_text(value);
}


template <typename T>
void StageEditorGuiGlade::setEntryValue(const std::string& name, T value) {
	Gtk::Entry* pEntry = NULL;
	m_RefXml->get_widget(name, pEntry);
	if (pEntry) pEntry->set_text(StringUtils::numberToString<T>(value));
}


std::string StageEditorGuiGlade::getEntryValue(const std::string& name) {
	Gtk::Entry* pEntry = NULL;
	m_RefXml->get_widget(name, pEntry);
	return pEntry ? pEntry->get_text() : "";
}


std::string StageEditorGuiGlade::getEntryTooltipText(const std::string& name) {
	Gtk::Entry* pEntry = NULL;
	m_RefXml->get_widget(name, pEntry);
	return pEntry ? pEntry->get_tooltip_text() : "";
}


template <typename T>
T StageEditorGuiGlade::getEntryValue(const std::string& name) {
	return StringUtils::stringToNumber<T>(getEntryValue(name));
}


unsigned StageEditorGuiGlade::getMaxTime() {
	return getEntryValue<unsigned>("maxTimeEntry");
}


std::string StageEditorGuiGlade::getBackground() {
	Gtk::FileChooserButton* pFileChooserButton = NULL;
	m_RefXml->get_widget("filechooserbutton", pFileChooserButton);
	std::string background;
	if (pFileChooserButton) background = pFileChooserButton->get_filename();
	return background;
}


int StageEditorGuiGlade::getGravity() {
	return getEntryValue<int>("gravityEntry");
}


int StageEditorGuiGlade::getA() {
	return getEntryValue<int>("aEntry");
}


int StageEditorGuiGlade::getB() {
	return getEntryValue<int>("bEntry");
}


int StageEditorGuiGlade::getC() {
	return getEntryValue<int>("cEntry");
}


int StageEditorGuiGlade::getD() {
	return getEntryValue<int>("dEntry");
}


void StageEditorGuiGlade::setMaxTime(unsigned maxTime) {
	setEntryValue<unsigned>("maxTimeEntry", maxTime);
}


void StageEditorGuiGlade::setBackground(const std::string& background) {
	Gtk::FileChooserButton* pFileChooserButton = NULL;
	m_RefXml->get_widget("filechooserbutton", pFileChooserButton);
	if (pFileChooserButton) {
		if (background.empty()) pFileChooserButton->unselect_all();
		else pFileChooserButton->set_filename(background);
	}
}


void StageEditorGuiGlade::setGravity(int gravity) {
	setEntryValue<int>("gravityEntry", gravity);
}


void StageEditorGuiGlade::setA(int a) {
	setEntryValue<int>("aEntry", a);
}


void StageEditorGuiGlade::setB(int b) {
	setEntryValue<int>("bEntry", b);
}


void StageEditorGuiGlade::setC(int c) {
	setEntryValue<int>("cEntry", c);
}


void StageEditorGuiGlade::setD(int d) {
	setEntryValue<int>("dEntry", d);
}


void StageEditorGuiGlade::setMetalBarCount(unsigned u) {
	setEntryValue<unsigned>("metalBarCountEntry", u);
}


unsigned StageEditorGuiGlade::getMetalBarCount() {
	return getEntryValue<unsigned>("metalBarCountEntry");
}


void StageEditorGuiGlade::setMetalBarPrice(unsigned u) {
	setEntryValue<unsigned>("metalBarPriceEntry", u);
}


unsigned StageEditorGuiGlade::getMetalBarPrice() {
	return getEntryValue<unsigned>("metalBarPriceEntry");
}


void StageEditorGuiGlade::setMetalBarMinSize(unsigned u) {
	setEntryValue<unsigned>("metalBarMinSizeEntry", u);
}


unsigned StageEditorGuiGlade::getMetalBarMinSize() {
	return getEntryValue<unsigned>("metalBarMinSizeEntry");
}


void StageEditorGuiGlade::setMetalBarMaxSize(unsigned u) {
	setEntryValue<unsigned>("metalBarMaxSizeEntry", u);
}


unsigned StageEditorGuiGlade::getMetalBarMaxSize() {
	return getEntryValue<unsigned>("metalBarMaxSizeEntry");
}


void StageEditorGuiGlade::setPlataformCount(unsigned u) {
	setEntryValue<unsigned>("plataformCountEntry", u);
}


unsigned StageEditorGuiGlade::getPlataformCount() {
	return getEntryValue<unsigned>("plataformCountEntry");
}


void StageEditorGuiGlade::setPlataformPrice(unsigned u) {
	setEntryValue<unsigned>("plataformPriceEntry", u);
}


unsigned StageEditorGuiGlade::getPlataformPrice() {
	return getEntryValue<unsigned>("plataformPriceEntry");
}


void StageEditorGuiGlade::setPlataformMinSize(unsigned u) {
	setEntryValue<unsigned>("plataformMinSizeEntry", u);
}


unsigned StageEditorGuiGlade::getPlataformMinSize() {
	return getEntryValue<unsigned>("plataformMinSizeEntry");
}


void StageEditorGuiGlade::setPlataformMaxSize(unsigned u) {
	setEntryValue<unsigned>("plataformMaxSizeEntry", u);
}


unsigned StageEditorGuiGlade::getPlataformMaxSize() {
	return getEntryValue<unsigned>("plataformMaxSizeEntry");
}


void StageEditorGuiGlade::setRopeCount(unsigned u) {
	setEntryValue<unsigned>("ropeCountEntry", u);
}


unsigned StageEditorGuiGlade::getRopeCount() {
	return getEntryValue<unsigned>("ropeCountEntry");
}


void StageEditorGuiGlade::setRopePrice(unsigned u) {
	setEntryValue<unsigned>("ropePriceEntry", u);
}


unsigned StageEditorGuiGlade::getRopePrice() {
	return getEntryValue<unsigned>("ropePriceEntry");
}


void StageEditorGuiGlade::setRopeMinSize(unsigned u) {
	setEntryValue<unsigned>("ropeMinSizeEntry", u);
}


unsigned StageEditorGuiGlade::getRopeMinSize() {
	return getEntryValue<unsigned>("ropeMinSizeEntry");
}


void StageEditorGuiGlade::setRopeMaxSize(unsigned u) {
	setEntryValue<unsigned>("ropeMaxSizeEntry", u);
}


unsigned StageEditorGuiGlade::getRopeMaxSize() {
	return getEntryValue<unsigned>("ropeMaxSizeEntry");
}


void StageEditorGuiGlade::setCanvasTapeCount(unsigned u) {
	setEntryValue<unsigned>("canvasTapeCountEntry", u);
}


unsigned StageEditorGuiGlade::getCanvasTapeCount() {
	return getEntryValue<unsigned>("canvasTapeCountEntry");
}


void StageEditorGuiGlade::setCanvasTapePrice(unsigned u) {
	setEntryValue<unsigned>("canvasTapePriceEntry", u);
}


unsigned StageEditorGuiGlade::getCanvasTapePrice() {
	return getEntryValue<unsigned>("canvasTapePriceEntry");
}


void StageEditorGuiGlade::setCanvasTapeMinSize(unsigned u) {
	setEntryValue<unsigned>("canvasTapeMinSizeEntry", u);
}


unsigned StageEditorGuiGlade::getCanvasTapeMinSize() {
	return getEntryValue<unsigned>("canvasTapeMinSizeEntry");
}


void StageEditorGuiGlade::setCanvasTapeMaxSize(unsigned u) {
	setEntryValue<unsigned>("canvasTapeMaxSizeEntry", u);
}


unsigned StageEditorGuiGlade::getCanvasTapeMaxSize() {
	return getEntryValue<unsigned>("canvasTapeMaxSizeEntry");
}


void StageEditorGuiGlade::setWheelCount(unsigned u) {
	setEntryValue<unsigned>("wheelCountEntry", u);
}


unsigned StageEditorGuiGlade::getWheelCount() {
	return getEntryValue<unsigned>("wheelCountEntry");
}


void StageEditorGuiGlade::setWheelPrice(unsigned u) {
	setEntryValue<unsigned>("wheelPriceEntry", u);
}


unsigned StageEditorGuiGlade::getWheelPrice() {
	return getEntryValue<unsigned>("wheelPriceEntry");
}


void StageEditorGuiGlade::setWheelMinSize(unsigned u) {
	setEntryValue<unsigned>("wheelMinSizeEntry", u);
}


unsigned StageEditorGuiGlade::getWheelMinSize() {
	return getEntryValue<unsigned>("wheelMinSizeEntry");
}


void StageEditorGuiGlade::setWheelMaxSize(unsigned u) {
	setEntryValue<unsigned>("wheelMaxSizeEntry", u);
}


unsigned StageEditorGuiGlade::getWheelMaxSize() {
	return getEntryValue<unsigned>("wheelMaxSizeEntry");
}


void StageEditorGuiGlade::setWheelTorke(unsigned u) {
	setEntryValue<unsigned>("wheelTorkeEntry", u);
}


unsigned StageEditorGuiGlade::getWheelTorke() {
	return getEntryValue<unsigned>("wheelTorkeEntry");
}


void StageEditorGuiGlade::setWheelDecayTime(unsigned u) {
	setEntryValue<unsigned>("wheelDecayTimeEntry", u);
}



unsigned StageEditorGuiGlade::getWheelDecayTime() {
	return getEntryValue<unsigned>("wheelDecayTimeEntry");
}


void StageEditorGuiGlade::setMassCount(unsigned u) {
	setEntryValue<unsigned>("massCountEntry", u);
}


unsigned StageEditorGuiGlade::getMassCount() {
	return getEntryValue<unsigned>("massCountEntry");
}


void StageEditorGuiGlade::setMassPrice(unsigned u) {
	setEntryValue<unsigned>("massPriceEntry", u);
}


unsigned StageEditorGuiGlade::getMassPrice() {
	return getEntryValue<unsigned>("massPriceEntry");
}


void StageEditorGuiGlade::setMass(unsigned u) {
	setEntryValue<unsigned>("massEntry", u);
}


unsigned StageEditorGuiGlade::getMass() {
	return getEntryValue<unsigned>("massEntry");
}


void StageEditorGuiGlade::setMassMinSize(unsigned u) {
	setEntryValue<unsigned>("massMinSizeEntry", u);
}


unsigned StageEditorGuiGlade::getMassMinSize() {
	return getEntryValue<unsigned>("massMinSizeEntry");
}


void StageEditorGuiGlade::setMassMaxSize(unsigned u) {
	setEntryValue<unsigned>("massMaxSizeEntry", u);
}


unsigned StageEditorGuiGlade::getMassMaxSize() {
	return getEntryValue<unsigned>("massMaxSizeEntry");
}


void StageEditorGuiGlade::setRocketCount(unsigned u) {
	setEntryValue<unsigned>("rocketCountEntry", u);
}


unsigned StageEditorGuiGlade::getRocketCount() {
	return getEntryValue<unsigned>("rocketCountEntry");
}


void StageEditorGuiGlade::setRocketPrice(unsigned u) {
	setEntryValue<unsigned>("rocketPriceEntry", u);
}


unsigned StageEditorGuiGlade::getRocketPrice() {
	return getEntryValue<unsigned>("rocketPriceEntry");
}


void StageEditorGuiGlade::setRocketStrength(unsigned u) {
	setEntryValue<unsigned>("rocketStrengthEntry", u);
}


unsigned StageEditorGuiGlade::getRocketStrength() {
	return getEntryValue<unsigned>("rocketStrengthEntry");
}


void StageEditorGuiGlade::setRocketDecayTime(unsigned u) {
	setEntryValue<unsigned>("rocketDecayTimeEntry", u);
}


unsigned StageEditorGuiGlade::getRocketDecayTime() {
	return getEntryValue<unsigned>("rocketDecayTimeEntry");
}


void StageEditorGuiGlade::setFixedPointCount(unsigned u) {
	setEntryValue<unsigned>("fixedPointCountEntry", u);
}


unsigned StageEditorGuiGlade::getFixedPointCount() {
	return getEntryValue<unsigned>("fixedPointCountEntry");
}


void StageEditorGuiGlade::setFixedPointPrice(unsigned u) {
	setEntryValue<unsigned>("fixedPointPriceEntry", u);
}


unsigned StageEditorGuiGlade::getFixedPointPrice() {
	return getEntryValue<unsigned>("fixedPointPriceEntry");
}


void StageEditorGuiGlade::setFixedPointMinSize(unsigned u) {
	setEntryValue<unsigned>("fixedPointMinSizeEntry", u);
}


unsigned StageEditorGuiGlade::getFixedPointMinSize() {
	return getEntryValue<unsigned>("fixedPointMinSizeEntry");
}


void StageEditorGuiGlade::setFixedPointMaxSize(unsigned u) {
	setEntryValue<unsigned>("fixedPointMaxSizeEntry", u);
}


unsigned StageEditorGuiGlade::getFixedPointMaxSize() {
	return getEntryValue<unsigned>("fixedPointMaxSizeEntry");
}

