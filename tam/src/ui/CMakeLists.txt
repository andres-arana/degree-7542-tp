# Creamos la libreria estatica physics especificando los fuentes que contiene.
# Cada vez que se agregue uno, debera agregarse aqui tambien.
add_library (ui
	controllers/ballcreatorinputhandler.cpp
	controllers/configurablerenderareacontroller.cpp
	controllers/connectinputhandler.cpp
	controllers/canvastapecreatorinputhandler.cpp
	controllers/deleteinputhandler.cpp
	controllers/exitareacreatorinputhandler.cpp
	controllers/fixedpointcreatorinputhandler.cpp
	controllers/masscreatorinputhandler.cpp
	controllers/metalbarcreatorinputhandler.cpp
	controllers/metalplatformcreatorinputhandler.cpp
	controllers/moveinputhandler.cpp
	controllers/obstaclecreatorinputhandler.cpp
	controllers/rocketcreatorinputhandler.cpp
	controllers/ropecreatorinputhandler.cpp
	controllers/wheelcreatorinputhandler.cpp
	views/connect/connectionpointrendererhelper.cpp
	views/connect/connectionpointsrenderer.cpp
	views/design/balldesignrendererhelper.cpp
	views/design/canvastapedesignrendererhelper.cpp
	views/design/connectiondesignrendererhelper.cpp
	views/design/elementcontainerdesignrenderer.cpp
	views/design/exitareadesignrendererhelper.cpp
	views/design/fixedpointdesignrendererhelper.cpp
	views/design/massdesignrendererhelper.cpp
	views/design/metalbardesignrendererhelper.cpp
	views/design/metalplatformdesignrendererhelper.cpp
	views/design/obstacledesignrendererhelper.cpp
	views/design/rocketdesignrendererhelper.cpp
	views/design/ropedesignrendererhelper.cpp
	views/design/wheeldesignrendererhelper.cpp
	views/move/movepointrendererhelper.cpp
	views/move/movepointsrenderer.cpp
	views/runtime/elementcontainerruntimerenderer.cpp
	views/runtime/springmassrendererhelper.cpp
	views/backgroundrenderer.cpp
	views/blueprintrenderer.cpp
	views/color.cpp
	views/gamerenderarea.cpp

)
