#ifndef EDITOR_PRESENTATION_STAGEEDITORHANDLER_H_
#define EDITOR_PRESENTATION_STAGEEDITORHANDLER_H_

#include "stageeditorgui.h"
#include "serialization/businessdelegate.h"
#include <string>
#include "serialization/model/elementfactoryimpl.h"
#include "serialization/model/stage.h"
#include "design/elementcontainer.h"

namespace editor {namespace presentation {
	/**
	 * Controller de la ventana principal del editor de escenarios
	 * @version 1.0
	 * @created 23-Oct-2008 04:36:31 a.m.
	 */
	class StageEditorHandler {
		// Referencia a la vista
		StageEditorGui& m_StageEditorGui;
		// Referencia al modelo
		game::serialization::BusinessDelegate m_BusinessDelegate;
		// Nombre del escenario
		std::string m_StageName;
		// Modelo del escenario
		game::serialization::model::Stage stage;
		// Contenedor de elementos
		game::design::ElementContainer m_ElementContainer;
	public:
		StageEditorHandler(StageEditorGui& stageEditorGui): m_StageEditorGui(stageEditorGui), stage(m_ElementContainer, true) {}
		~StageEditorHandler() {stage.clean();}
		/** Envia la orden de persistir un escenario. */
		void saveStage();
		/**
		 * Persiste un escenario con un nombre dado.
		 * @return true Si el escenario se persisitio con exito y false si el escenario no se persisitio.
		 */
		bool saveStage(const std::string& stageName);
		/** Envia la orden de persistir un escenario pidiendo un nombre por pantalla. */
		void saveAsStage();
		/** Recupera un escenario */
		void loadStage();
		/** Inicializa la vista para un nuevo escenario */
		void newStage();
		/** @return El contenedor de los elementos del escenario */
		game::design::ElementContainer& getElementContainer();
		/** @return La fabrica para los elementos del escenario */
		game::serialization::model::ElementFactoryImpl& getElementFactory();
	};
}}
#endif // EDITOR_PRESENTATION_STAGEEDITORHANDLER_H_
