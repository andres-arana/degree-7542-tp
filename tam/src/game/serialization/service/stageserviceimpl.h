#ifndef EDITOR_DOMAIN_SERVICE_STAGESERVICEIMPL_H_
#define EDITOR_DOMAIN_SERVICE_STAGESERVICEIMPL_H_

#include "stageservice.h"
#include <string>
#include "../model/stage.h"
#include "../persistence/repositoryfactory.h"
#include "../../design/elementcontainer.h"

using game::serialization::model::Stage;
using game::serialization::persistence::RepositoryFactory;

namespace game {
	namespace serialization {
		namespace service {
			/**
			 * @version 1.0
			 * @created 23-Oct-2008 04:36:41 a.m.
			 */
			class StageServiceImpl: public StageService {
				RepositoryFactory m_RepositoryFactory;
			public:
				virtual ~StageServiceImpl() {}
				/**
				 * Persiste un escenario en un archivo xml
				 * @param folder    Nombre de la carpeta donde se persistira el escenario.
				 *
				 * @param stage    Escenario que se quiere persistir.
				 * @param background    Nombre y ruta de la imagen que se usara como fondo de
				 * escenario.
				 *
				 */
				virtual void saveStage(const std::string& folder,
						const game::serialization::model::Stage& stage,
						const std::string& background);
				/**
				 * Carga en memoria un escenario persistido.
				 * @param folder    Nombre de la carpeta donde se encuentra el escenario.
				 * @param stage    Lugar donde se dejara el escenario.
				 * @param background    Path de la imagen de fondo del escenario
				 * @return true si se pudo cargar el escenario y false en caso de error.
				 */
				virtual bool loadStage(const std::string& folder,
						game::serialization::model::Stage& stage, std::string& background);

				/** @return Un string con la informacion de todos los elementos del elementContainer */
				virtual std::string serialize(const game::design::ElementContainer& elementContainer);
				/**
				 * Llena el elementContainer con los elementos generados a partir del stageStr,
				 * generado previamente por el metodo serialize
				 */
				virtual void unserialize(const std::string& stageStr, game::design::ElementContainer& elementContainer);
			};
		}
	}
}
#endif // EDITOR_DOMAIN_SERVICE_STAGESERVICEIMPL_H_
