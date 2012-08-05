#include "elementcontainerdesignrenderer.h"
#include "balldesignrendererhelper.h"
#include "canvastapedesignrendererhelper.h"
#include "connectiondesignrendererhelper.h"
#include "exitareadesignrendererhelper.h"
#include "fixedpointdesignrendererhelper.h"
#include "massdesignrendererhelper.h"
#include "metalbardesignrendererhelper.h"
#include "metalplatformdesignrendererhelper.h"
#include "obstacledesignrendererhelper.h"
#include "rocketdesignrendererhelper.h"
#include "ropedesignrendererhelper.h"
#include "wheeldesignrendererhelper.h"

using namespace Cairo;
using namespace ui::views;
using namespace ui::views::design;
using namespace game::design;

ElementContainerDesignRenderer::ElementContainerDesignRenderer(const ElementContainer &container) :
	container(container) {

}

void ElementContainerDesignRenderer::render(RefPtr<Context> drawingContext) const {
	// Pelotas
	if (container.getBall()) {
		BallDesignRendererHelper ballRenderer(drawingContext);
		ballRenderer.renderBall(*container.getBall());
	}

	// Cintas de lona
	CanvasTapeDesignRendererHelper canvasTapeRenderer(drawingContext);
	const ElementContainer::CanvasTapeCollection &canvasTapes = container.getCanvasTapeCollection();
	for (ElementContainer::CanvasTapeIterator it = canvasTapes.begin(); it != canvasTapes.end(); ++it) {
		canvasTapeRenderer.renderCanvasTape(**it);
	}

	// Conexiones
	ConnectionDesignRendererHelper connectionRenderer(drawingContext);
	const ElementContainer::ConnectionCollection &connections = container.getConnectionCollection();
	for (ElementContainer::ConnectionIterator it = connections.begin(); it != connections.end(); ++it) {
		connectionRenderer.renderConnection(**it);
	}

	// Areas de salida
	ExitAreaDesignRendererHelper exitAreaRenderer(drawingContext);
	const ElementContainer::ExitAreaCollection &exitAreas = container.getExitAreaCollection();
	for (ElementContainer::ExitAreaIterator it = exitAreas.begin(); it != exitAreas.end(); ++it) {
		exitAreaRenderer.renderExitArea(**it);
	}

	// Puntos fijos
	FixedPointDesignRendererHelper fixedPointRenderer(drawingContext);
	const ElementContainer::FixedPointCollection &fixedPoints = container.getFixedPointCollection();
	for (ElementContainer::FixedPointIterator it = fixedPoints.begin(); it != fixedPoints.end(); ++it) {
		fixedPointRenderer.renderFixedPoint(**it);
	}

	// Masas
	MassDesignRendererHelper massRenderer(drawingContext);
	const ElementContainer::MassCollection &masses = container.getMassCollection();
	for (ElementContainer::MassIterator it = masses.begin(); it != masses.end(); ++it) {
		massRenderer.renderMass(**it);
	}

	// Barras metálicas
	MetalBarDesignRendererHelper metalBarRenderer(drawingContext);
	const ElementContainer::MetalBarCollection &metalBars = container.getMetalBarCollection();
	for (ElementContainer::MetalBarIterator it = metalBars.begin(); it != metalBars.end(); ++it) {
		metalBarRenderer.renderMetalBar(**it);
	}

	// Plataformas metálicas
	MetalPlatformDesignRendererHelper metalPlatformRenderer(drawingContext);
	const ElementContainer::MetalPlatformCollection &metalPlatforms = container.getMetalPlatformCollection();
	for (ElementContainer::MetalPlatformIterator it = metalPlatforms.begin(); it != metalPlatforms.end(); ++it) {
		metalPlatformRenderer.renderMetalPlatform(**it);
	}

	// Obstáculos
	ObstacleDesignRendererHelper obstacleRenderer(drawingContext);
	const ElementContainer::ObstacleCollection &obstacles = container.getObstacleCollection();
	for (ElementContainer::ObstacleIterator it = obstacles.begin(); it != obstacles.end(); ++it) {
		obstacleRenderer.renderObstacle(**it);
	}

	// Cohetes
	RocketDesignRendererHelper rocketRenderer(drawingContext);
	const ElementContainer::RocketCollection rockets = container.getRocketCollection();
	for (ElementContainer::RocketIterator it = rockets.begin(); it != rockets.end(); ++it) {
		rocketRenderer.renderRocket(**it);
	}

	// Cuerdas
	RopeDesignRendererHelper ropeRenderer(drawingContext);
	const ElementContainer::RopeCollection &ropes = container.getRopeCollection();
	for (ElementContainer::RopeIterator it = ropes.begin(); it != ropes.end(); ++it) {
		ropeRenderer.renderRope(**it);
	}

	// Ruedas
	WheelDesignRendererHelper wheelRenderer(drawingContext);
	const ElementContainer::WheelCollection wheels = container.getWheelCollection();
	for (ElementContainer::WheelIterator it = wheels.begin(); it != wheels.end(); ++it) {
		wheelRenderer.renderWheel(**it);
	}
}

