# Creamos la libreria estatica physics especificando los fuentes que contiene.
# Cada vez que se agregue uno, debera agregarse aqui tambien.
add_library (game
	core/affectors/constantforceaffector.cpp
	core/affectors/dampingforceaffector.cpp
	core/affectors/decayingforceaffector.cpp
	core/affectors/gravityforceaffector.cpp
	core/affectors/springforceaffector.cpp
	core/affectors/torqueforceaffector.cpp
	core/particle.cpp
	core/physicsengine.cpp
	core/spring.cpp
	design/connect/centerconnectionpoint.cpp
	design/connect/connectionpoint.cpp
	design/connect/toconnectionpoint.cpp
	design/connect/fromconnectionpoint.cpp
	design/connect/radiusconnectionpoint.cpp
	design/connect/rocketposconnectionpoint.cpp
	design/move/movepoint.cpp
	design/move/centermovepoint.cpp
	design/move/frommovepoint.cpp
	design/move/fromtomovepoint.cpp
	design/move/radiusmovepoint.cpp
	design/move/rocketposmovepoint.cpp
	design/move/rockettargetmovepoint.cpp
	design/move/tomovepoint.cpp
	design/elements/ball.cpp
	design/elements/canvastape.cpp
	design/elements/centerradiuselement.cpp
	design/elements/connection.cpp
	design/elements/element.cpp
	design/elements/exitarea.cpp
	design/elements/fixedpoint.cpp
	design/elements/fromtoelement.cpp
	design/elements/mass.cpp
	design/elements/metalbar.cpp
	design/elements/metalplatform.cpp
	design/elements/obstacle.cpp
	design/elements/rectangularelement.cpp
	design/elements/rocket.cpp
	design/elements/rope.cpp
	design/elements/stringelement.cpp
	design/elements/wheel.cpp
	design/elementcontainer.cpp
	logic/gameengine.cpp
	logic/designtoolbox.cpp
	logic/properties/stageproperties.cpp
	logic/properties/centerradiuselementproperties.cpp
	logic/properties/elementproperties.cpp
	logic/properties/fromtoelementproperties.cpp
	logic/properties/massproperties.cpp
	logic/properties/rocketproperties.cpp
	logic/properties/wheelproperties.cpp
	serialization/service/stageserviceimpl.cpp
	serialization/businessdelegate.cpp
	serialization/model/elementfactoryimpl.cpp
	serialization/persistence/stagexmlrepositorytinyxml.cpp
	serialization/persistence/tinystr.cpp
	serialization/persistence/tinyxml.cpp
	serialization/persistence/tinyxmlerror.cpp
	serialization/persistence/tinyxmlparser.cpp
)
