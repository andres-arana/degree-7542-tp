#include "color.h"

using namespace ui::views;

Color::Color(double red, double green, double blue, double alpha) :
	red(red),
	green(green),
	blue(blue),
	alpha(alpha) {
		
} 

double Color::getRed() const {
	return this->red;
}

double Color::getGreen() const {
	return this->green;
}

double Color::getBlue() const {
	return this->blue;
}

double Color::getAlpha() const {
	return this->alpha;
}

const Color Color::ALPHA_DARK_GREEN(0.0, 0.2, 0.0, 0.6);

const Color Color::ALPHA_BLUE(0.0, 0.0, 0.8, 0.5);

const Color Color::ALPHA_GREEN(0.0, 0.8, 0.0, 0.5);

const Color Color::ALPHA_GREY(0.3, 0.3, 0.3, 0.6);

const Color Color::ALPHA_LIGHT_BLUE(0.219607843, 0.674509804, 0.925490196, 0.5);

const Color Color::ALPHA_RED(0.8, 0.0, 0.0, 0.5);

const Color Color::ALPHA_WHITE(1.0, 1.0, 1.0, 0.5);

const Color Color::GOLD(1.0, 0.909803922, 0.48627451);

const Color Color::GREY(0.196078431373, 0.196078431373, 0.196078431373); 

const Color Color::ORANGE(0.992156, 0.815686, 0.090196);

const Color Color::RED(1.0, 0.0, 0.0);

const Color Color::WHITE(1.0, 1.0, 1.0);
