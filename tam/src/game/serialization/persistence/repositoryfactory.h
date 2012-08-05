#ifndef EDITOR_PERSISTENCE_REPOSITORYFACTORY_H_
#define EDITOR_PERSISTENCE_REPOSITORYFACTORY_H_

#include "stagexmlrepository.h"
#include "stagexmlrepositorytinyxml.h"

namespace game {
	namespace serialization {
		namespace persistence {
			/**
			 * @version 1.0
			 * @created 23-Oct-2008 04:36:47 a.m.
			 */
			class RepositoryFactory	{
				StageXmlRepositoryTinyXml m_StageXmlRepository;
			public:
				/**
				 * Crea, administra y retorna un repositorio de escenarios en formato xml.
				 */
				StageXmlRepository& getStageXmlRepository() {return m_StageXmlRepository;}
			};
		}
	}
}
#endif // EDITOR_PERSISTENCE_REPOSITORYFACTORY_H_
