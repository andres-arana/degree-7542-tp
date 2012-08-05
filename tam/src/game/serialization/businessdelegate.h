#ifndef EDITOR_DOMAIN_BUSINESSDELEGATE_H_
#define EDITOR_DOMAIN_BUSINESSDELEGATE_H_

#include <string>
#include "model/stage.h"
#include "service/servicelocator.h"
#include "../design/elementcontainer.h"

using game::serialization::model::Stage;
using game::serialization::service::ServiceLocator;

namespace game {
	namespace serialization {
		/**
		 * Facade para acceder al modelo del editor de escenarios
		 * @version 1.0
		 * @created 23-Oct-2008 04:36:35 a.m.
		 */
		class BusinessDelegate {
			ServiceLocator m_ServiceLocator;
		public:
			/**
			 * Persiste un escenario
			 * @param folder    Nombre de la carpeta donde se persistira el escenario.
			 * @param stage    Escenario a persistir
			 * @param background    Path de la imagen que el escenario tendra de fondo
			 *
			 */
			void saveStage(const std::string& folder, const game::serialization::model::Stage& stage, const std::string& background);
			/**
			 * Recupera un escenario a partir de un archivo xml
			 * @param folder    Nombre de la carpeta donde se encuentra el escenario.
			 * @param stage    Escenario recuperado
			 * @param background    Path de la imagen de fondo del escenario
			 * @return true si se pudo cargar el escenario y false en caso de error.
			 */
			bool loadStage(const std::string& folder, game::serialization::model::Stage& stage, std::string& background);
			/** @return Un string con la informacion de todos los elementos del elementContainer */
			std::string serialize(const game::design::ElementContainer& elementContainer);
			/**
			 * Llena el elementContainer con los elementos generados a partir del stageStr,
			 * generado previamente por el metodo serialize
			 */
			void unserialize(const std::string& stageStr, game::design::ElementContainer& elementContainer);
		};
	}
}
#endif // EDITOR_DOMAIN_BUSINESSDELEGATE_H_
