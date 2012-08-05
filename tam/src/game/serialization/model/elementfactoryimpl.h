#ifndef EDITOR_DOMAIN_MODEL_ELEMENTFACTORYIMPL_H_
#define EDITOR_DOMAIN_MODEL_ELEMENTFACTORYIMPL_H_

#include "../../design/elements/ball.h"
#include "../../design/elements/exitarea.h"
#include "../../design/elements/fixedpoint.h"
#include "../../design/elements/obstacle.h"
#include "../../design/elementfactory.h"

namespace game {
	namespace serialization {
		namespace model {
			class ElementFactoryImpl: public game::design::ElementFactory {
				bool ballCreated;
				bool editableMode;
				void restoreBall();
			public:
				ElementFactoryImpl(bool editableMode= true);
				virtual ~ElementFactoryImpl();
				virtual game::design::elements::Ball *createBall();
				virtual game::design::elements::ExitArea *createExitArea();
				virtual game::design::elements::FixedPoint *createFixedPoint();
				virtual game::design::elements::Obstacle *createObstacle(const core::Vector2d &startPosition);
				/** Restaura el estado original de la factory */
				void restore();
				void setEditableMode(bool editableMode);
			};
		}
	}
}

#endif /*EDITOR_DOMAIN_MODEL_ELEMENTFACTORYIMPL_H_*/
