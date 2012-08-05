#include "elementcontainerruntimerenderer.h"
#include "../design/exitareadesignrendererhelper.h"
#include "springmassrendererhelper.h"

using namespace Cairo;
using namespace ui::views;
using namespace ui::views::design;
using namespace ui::views::runtime;
using namespace game::design;

ElementContainerRuntimeRenderer::ElementContainerRuntimeRenderer(const ElementContainer &container) :
	container(container) {

}

void ElementContainerRuntimeRenderer::render(RefPtr<Context> drawingContext) const {
	// Pelotas
	if (container.getBall()) {
		SpringMassRendererHelper ballRenderer(Color::GOLD, drawingContext);
		ballRenderer.renderElement(*container.getBall());
	}

	// Cintas de lona
	SpringMassRendererHelper canvasTapeRenderer(Color::WHITE, drawingContext);
	const ElementContainer::CanvasTapeCollection &canvasTapes = container.getCanvasTapeCollection();
	for (ElementContainer::CanvasTapeIterator it = canvasTapes.begin(); it != canvasTapes.end(); ++it) {
		canvasTapeRenderer.renderElement(**it);
	}

	// Areas de salida
	ExitAreaDesignRendererHelper exitAreaRenderer(drawingContext);
	const ElementContainer::ExitAreaCollection &exitAreas = container.getExitAreaCollection();
	for (ElementContainer::ExitAreaIterator it = exitAreas.begin(); it != exitAreas.end(); ++it) {
		exitAreaRenderer.renderExitArea(**it);
	}

	// Puntos fijos
	SpringMassRendererHelper fixedPointRenderer(Color::ALPHA_DARK_GREEN, drawingContext);
	const ElementContainer::FixedPointCollection &fixedPoints = container.getFixedPointCollection();
	for (ElementContainer::FixedPointIterator it = fixedPoints.begin(); it != fixedPoints.end(); ++it) {
		fixedPointRenderer.renderElement(**it);
	}

	// Masas
	SpringMassRendererHelper massRenderer(Color::WHITE, drawingContext);
	const ElementContainer::MassCollection &masses = container.getMassCollection();
	for (ElementContainer::MassIterator it = masses.begin(); it != masses.end(); ++it) {
		massRenderer.renderElement(**it);
	}

	// Barras metálicas
	SpringMassRendererHelper metalBarRenderer(Color::ALPHA_WHITE, drawingContext);
	const ElementContainer::MetalBarCollection &metalBars = container.getMetalBarCollection();
	for (ElementContainer::MetalBarIterator it = metalBars.begin(); it != metalBars.end(); ++it) {
		metalBarRenderer.renderElement(**it);
	}

	// Plataformas metálicas
	SpringMassRendererHelper metalPlatformRenderer(Color::WHITE, drawingContext);
	const ElementContainer::MetalPlatformCollection &metalPlatforms = container.getMetalPlatformCollection();
	for (ElementContainer::MetalPlatformIterator it = metalPlatforms.begin(); it != metalPlatforms.end(); ++it) {
		metalPlatformRenderer.renderElement(**it);
	}

	// Obstáculos
	SpringMassRendererHelper obstacleRenderer(Color::ORANGE, drawingContext);
	const ElementContainer::ObstacleCollection &obstacles = container.getObstacleCollection();
	for (ElementContainer::ObstacleIterator it = obstacles.begin(); it != obstacles.end(); ++it) {
		obstacleRenderer.renderElement(**it);
	}

	// Cohetes
	SpringMassRendererHelper rocketRenderer(Color::RED, drawingContext);
	const ElementContainer::RocketCollection rockets = container.getRocketCollection();
	for (ElementContainer::RocketIterator it = rockets.begin(); it != rockets.end(); ++it) {
		rocketRenderer.renderElement(**it);
	}

	// Cuerdas
	SpringMassRendererHelper ropeRenderer(Color::ALPHA_WHITE, drawingContext);
	const ElementContainer::RopeCollection &ropes = container.getRopeCollection();
	for (ElementContainer::RopeIterator it = ropes.begin(); it != ropes.end(); ++it) {
		ropeRenderer.renderElement(**it);
	}

	// Ruedas
	SpringMassRendererHelper wheelRenderer(Color::GREY, drawingContext);
	const ElementContainer::WheelCollection wheels = container.getWheelCollection();
	for (ElementContainer::WheelIterator it = wheels.begin(); it != wheels.end(); ++it) {
		wheelRenderer.renderElement(**it);
	}
}

