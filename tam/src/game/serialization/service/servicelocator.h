#ifndef EDITOR_DOMAIN_SERVICE_SERVICELOCATOR_H_
#define EDITOR_DOMAIN_SERVICE_SERVICELOCATOR_H_

#include "stageservice.h"
#include "stageserviceimpl.h"

namespace game {
	namespace serialization {
		namespace service {
			/**
			 * Clase que fabrica y destruye a los servicios del modulo.
			 * @version 1.0
			 * @created 23-Oct-2008 04:36:38 a.m.
			 */
			class ServiceLocator {
				StageServiceImpl m_StageService;
			public:
				/**
				 * @return Un puntero al servicio EscenarioService
				 */
				StageService& getStageService() {return m_StageService;}
			};
		}
	}
}
#endif // EDITOR_DOMAIN_SERVICE_SERVICELOCATOR_H_
