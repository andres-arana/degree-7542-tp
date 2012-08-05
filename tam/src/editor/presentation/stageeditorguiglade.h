#ifndef EDITOR_PRESENTATION_STAGEEDITORGUIGTKMM_H_
#define EDITOR_PRESENTATION_STAGEEDITORGUIGTKMM_H_

#include "stageeditorgui.h"
#include "stageeditorhandler.h"
#include "views/gamerenderarea.h"
#include "controllers/configurablerenderareacontroller.h"

#include <libglademm.h>
#include <libglademm/xml.h>
#include <gtkmm.h>
#include <vector>
#include <string>


namespace editor {namespace presentation {
	/**
	 * @version 1.0
	 * @created 23-Oct-2008 04:36:33 a.m.
	 */
	class StageEditorGuiGlade: public Gtk::Window, virtual public StageEditorGui {
		// Controlador
		StageEditorHandler m_StageEditorHandler;
		Glib::RefPtr<Gnome::Glade::Xml> m_RefXml;
		Gtk::Window* mainWindow;
		Gtk::RadioButton* metalBarRadio;
		Gtk::RadioButton* ballRadio;
		Gtk::RadioButton* exitAreaRadio;
		Gtk::RadioButton* fixedPointRadio;
		Gtk::RadioButton* obstacleRadio;
		Gtk::RadioButton* moveRadio;
		Gtk::RadioButton* deleteRadio;
		ui::views::GameRenderArea gameRenderArea;
		ui::controllers::ConfigurableRenderAreaController gameAreaController;

		std::vector<std::string> m_NumericEntryNameCollection;
		std::vector<std::string> m_SizeEntryNameCollection;

		void initWidgets();
		void bindSignals();

		// Events
		void onBallRadioToggled();
		void onExitAreaRadioToggled();
		void onFixedPointRadioToggled();
		void onObstacleRadioToggled();
		void onMoveRadioToggled();
		void onDeleteRadioToggled();

		// Metodo que se cuando se quiere grabar el escenario
		void onSaveStageAction(const Glib::ustring& text);
		// Metodo que se cuando se quiere grabar el escenario con otro nombre
		void onSaveStageAsAction(const Glib::ustring& text);
		// Metodo que se cuando se quiere crear un nuevo escenario
		void onNewStageAction(const Glib::ustring& text);
		// Metodo que se cuando se quiere abrir un escenario
		void onOpenStageAction(const Glib::ustring& text);
		/**
		 * Asigna un valor a una caja de texto
		 * @param name Nombre de la caja de texto
		 * @param value Valor que se quiere asignar
		 */
		void setEntryValue(const std::string& name, std::string value);
		/**
		 * Asigna un valor a una caja de texto
		 * @param name Nombre de la caja de texto
		 * @param value Valor que se quiere asignar
		 */
		template <typename T>
		void setEntryValue(const std::string& name, T value);
		/**
		 * @param name Nombre de la caja de texto
		 * @return El valor de la caja de texto
		 */
		template <typename T>
		T getEntryValue(const std::string& name);
		/**
		 * @param name Nombre de la caja de texto
		 * @return El valor de la caja de texto
		 */
		std::string getEntryValue(const std::string& name);
		/**
		 * @param name Nombre de la caja de texto
		 * @return El valor del tooltip de la caja de texto
		 */
		std::string getEntryTooltipText(const std::string& name);

		void fillEntryNameCollection();
		std::string validateIsNumericEntries();
		std::string validateSizeEntries();
		std::string validateElementContainer();
	public:
		StageEditorGuiGlade(Gtk::Main &kit);
		virtual ~StageEditorGuiGlade();

		/** Muestra el nombre del escenario */
		virtual void showStageName(const std::string& name);
		/** @return El tiempo maximo ingresado */
		virtual unsigned getMaxTime();
		/** Asigna el tiempo maximo */
		virtual void setMaxTime(unsigned maxTime);
		/** @return El nombre de la imagen seleccionada comofondo de escenario */
		virtual std::string getBackground();
		/** Asigna el nombre de la imagen de fondo del escenario */
		virtual void setBackground(const std::string& background);
		/** @return La gravedad ingresada */
		virtual int getGravity();
		/** Asigna la gravedad */
		virtual void setGravity(int gravity);
		/** @return El valor ingresado para la constante A */
		virtual int getA();
		/** Asigna el valor para la constante A */
		virtual void setA(int a);
		/** @return El valor ingresado para la constante B */
		virtual int getB();
		/** Asigna el valor para la constante B */
		virtual void setB(int b);
		/** @return El valor ingresado para la constante C */
		virtual int getC();
		/** Asigna el valor para la constante C */
		virtual void setC(int c);
		/** @return El valor ingresado para la constante D */
		virtual int getD();
		/** Asigna el valor para la constante D */
		virtual void setD(int d);
		/** Asigna la cantidad de barras metalicas */
		virtual void setMetalBarCount(unsigned u);
		/* @return La cantidad de barras metalicas */
		virtual unsigned getMetalBarCount();
		/** Asigna el precio de las barras metalicas */
		virtual void setMetalBarPrice(unsigned u);
		/* @return El precio de las barras metalicas */
		virtual unsigned getMetalBarPrice();
		/** Asigna la longitud minima de las barras metalicas */
		virtual void setMetalBarMinSize(unsigned u);
		/* @return La longitud minima de las barras metalicas */
		virtual unsigned getMetalBarMinSize();
		/** Asigna la longitud maxima de las barras metalicas */
		virtual void setMetalBarMaxSize(unsigned u);
		/* @return La longitud maxima de las barras metalicas */
		virtual unsigned getMetalBarMaxSize();
		/** Asigna la cantidad de plataformas */
		virtual void setPlataformCount(unsigned u);
		/* @return La cantidad de plataformas */
		virtual unsigned getPlataformCount();
		/** Asigna el precio de las plataformas */
		virtual void setPlataformPrice(unsigned u);
		/* @return El precio de las plataformas */
		virtual unsigned getPlataformPrice();
		/** Asigna la longitud minima de las plataformas */
		virtual void setPlataformMinSize(unsigned u);
		/* @return La longitud minima de las plataformas */
		virtual unsigned getPlataformMinSize();
		/** Asigna la longitud maxima de las plataformas */
		virtual void setPlataformMaxSize(unsigned u);
		/* @return La longitud maxima de las plataformas */
		virtual unsigned getPlataformMaxSize();
		/** Asigna la cantidad de sogas */
		virtual void setRopeCount(unsigned u);
		/* @return La cantidad de sogas */
		virtual unsigned getRopeCount();
		/** Asigna el precio de las sogas */
		virtual void setRopePrice(unsigned u);
		/* @return El precio de las sogas */
		virtual unsigned getRopePrice();
		/** Asigna la longitud minima de las sogas */
		virtual void setRopeMinSize(unsigned u);
		/* @return La longitud minima de las sogas */
		virtual unsigned getRopeMinSize();
		/** Asigna la longitud maxima de las sogas */
		virtual void setRopeMaxSize(unsigned u);
		/* @return La longitud maxima de las sogas */
		virtual unsigned getRopeMaxSize();
		/** Asigna la cantidad de cintas de lona */
		virtual void setCanvasTapeCount(unsigned u);
		/* @return La cantidad de cintas de lona */
		virtual unsigned getCanvasTapeCount();
		/** Asigna el precio de las cintas de lona */
		virtual void setCanvasTapePrice(unsigned u);
		/* @return El precio de las cintas de lona */
		virtual unsigned getCanvasTapePrice();
		/** Asigna la longitud minima de las cintas de lona */
		virtual void setCanvasTapeMinSize(unsigned u);
		/* @return La longitud minima de las cintas de lona */
		virtual unsigned getCanvasTapeMinSize();
		/** Asigna la longitud maxima de las cintas de lona */
		virtual void setCanvasTapeMaxSize(unsigned u);
		/* @return La longitud maxima de las cintas de lona */
		virtual unsigned getCanvasTapeMaxSize();
		/** Asigna la cantidad de ruedas */
		virtual void setWheelCount(unsigned u);
		/* @return La cantidad de ruedas */
		virtual unsigned getWheelCount();
		/** Asigna el precio de las ruedas */
		virtual void setWheelPrice(unsigned u);
		/* @return El precio de las ruedas */
		virtual unsigned getWheelPrice();
		/** Asigna la longitud minima de las ruedas */
		virtual void setWheelMinSize(unsigned u);
		/* @return La longitud minima de las ruedas */
		virtual unsigned getWheelMinSize();
		/** Asigna la longitud maxima de las ruedas */
		virtual void setWheelMaxSize(unsigned u);
		/* @return La longitud maxima de las ruedas */
		virtual unsigned getWheelMaxSize();
		/** Asigna el torque de las ruedas */
		virtual void setWheelTorke(unsigned u);
		/* @return El torque de las ruedas */
		virtual unsigned getWheelTorke();
		/** Asigna el tiempo de accion de las ruedas */
		virtual void setWheelDecayTime(unsigned u);
		/* @return El tiempo de accion de las ruedas */
		virtual unsigned getWheelDecayTime();
		/** Asigna la cantidad de masas */
		virtual void setMassCount(unsigned u);
		/* @return La cantidad de masas */
		virtual unsigned getMassCount();
		/** Asigna el precio de las masas */
		virtual void setMassPrice(unsigned u);
		/* @return El precio de las masas */
		virtual unsigned getMassPrice();
		/** Asigna la masa */
		virtual void setMass(unsigned u);
		/* @return La masa */
		virtual unsigned getMass();
		/** Asigna la longitud minima de las masas */
		virtual void setMassMinSize(unsigned u);
		/* @return La longitud minima de las masas */
		virtual unsigned getMassMinSize();
		/** Asigna la longitud maxima de las masas */
		virtual void setMassMaxSize(unsigned u);
		/* @return La longitud maxima de las masas */
		virtual unsigned getMassMaxSize();
		/** Asigna la cantidad de cohetes */
		virtual void setRocketCount(unsigned u);
		/* @return La cantidad de cohetes */
		virtual unsigned getRocketCount();
		/** Asigna el precio de los cohetes */
		virtual void setRocketPrice(unsigned u);
		/* @return El precio de los cohetes */
		virtual unsigned getRocketPrice();
		/** Asigna la fuerza de los cohetes */
		virtual void setRocketStrength(unsigned u);
		/* @return La fuerza de los cohetes */
		virtual unsigned getRocketStrength();
		/** Asigna el tiempo de accion de los cohetes */
		virtual void setRocketDecayTime(unsigned u);
		/* @return El tiempo de accion de los cohetes */
		virtual unsigned getRocketDecayTime();
		/** Asigna la cantidad de puntos fijos */
		virtual void setFixedPointCount(unsigned u);
		/* @return La cantidad de puntos fijos */
		virtual unsigned getFixedPointCount();
		/** Asigna el precio de los puntos fijos */
		virtual void setFixedPointPrice(unsigned u);
		/* @return El precio de los puntos fijos */
		virtual unsigned getFixedPointPrice();
		/** Asigna la longitud minima de los puntos fijos */
		virtual void setFixedPointMinSize(unsigned u);
		/* @return La longitud minima de los puntos fijos */
		virtual unsigned getFixedPointMinSize();
		/** Asigna la longitud maxima de los puntos fijos */
		virtual void setFixedPointMaxSize(unsigned u);
		/* @return La longitud maxima de los puntos fijos */
		virtual unsigned getFixedPointMaxSize();
		/** Muestra un mensaje de error por pantalla */
		virtual void showMessageError(const std::string& message);
		/**
		 * Muestra una ventana para seleccionar una carpeta
		 * @param folder Carpeta seleccionada
		 * @param saveMode true si se quiere usar el dialogo para grabar, false si se quiere usar el dialogo para cargar.
		 * @return true si se selecciono una carpeta y false si se cerro la ventana sin seleccionar
		 */
		virtual bool showFolderChooserDialog(std::string& folder, bool saveMode);
		/** Elimina de la pantalla los datos del escenario */
		virtual void clear();
		/**
		 * Valida los valores ingresados en todos los campos.
		 * @return true si se paso la validacion y false en otro caso
		 */
		virtual bool validate();
	};
}}
#endif // EDITOR_PRESENTATION_STAGEEDITORGUIGTKMM_H_

