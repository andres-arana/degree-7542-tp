#include "sms_app.h"
#include "test_sms.h"
#include <cmath>
#include <fstream>
#include <SDL.h>
#include <SDL_opengl.h>
#include <sstream>

namespace
{
	const double MASS_SIZE = 0.02;
	const int POLY_SIDES = 10;

	const double MAX_DT = 0.007;

	const std::string CONFIG_FILENAME = "config.txt";

	const double PI = 3.1415926535897932384626433832795;
}

SMSApp::SMSApp(int argc, char* argv[]) :
config_(CONFIG_FILENAME),
sms_(config_),
video_(config_),
ticks_(0)
{
	if (argc == 1)
		loadRandomDemo(sms_);
	else
		loadDemo(sms_, argv[1]);

	acf_.load(config_.read<std::string>("App.Font").c_str());
}

SMSApp::~SMSApp()
{
	SDL_Quit();
}

int SMSApp::run()
{
	bool exit_now = false;

	ticks_ = SDL_GetTicks();

	SDL_Event ev;
	while (!exit_now)
	{
		while (SDL_PollEvent(&ev))
			if (ev.type == SDL_QUIT)
				exit_now = true;

		uint32_t newTicks = SDL_GetTicks();
		double dt = static_cast<double>(newTicks - ticks_) / 1000.0;
		if (dt > MAX_DT) // Clamps dt
			dt = MAX_DT;
		sms_.rk4Step(dt);
		ticks_ = newTicks;

		drawFrame();
	}
	return 0;
}

void SMSApp::drawFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// draws all springs
	glBegin(GL_LINES);
	for (size_t i = 0; i < sms_.getNumSprings(); i++)
	{
		SpringProxy sp = sms_.getSpringProxy(i);

		Vector2<> startPos = sp.getStartPos();
		Vector2<> endPos = sp.getEndPos();

		double relElong =  sp.getRelElongation();
		double k = sp.getK();

		if (k == 0.0)
			continue;

		double color = relElong * k / 10.0;
		if (color < -1.0)
			color = -1.0;
		else if (color > 1.0)
			color = 1.0;

		if (color < 0.0)
		{
			glColor3d(-color / 2.0 + 0.5, 0.5 + color / 2.0, 
				0.5 + color / 2.0);
		}
		else
		{
			double green = 1.0 - 1.0 / (2.0 + 2.0 * color);
			glColor3d(1.0 - green, green, 1.0 - green);
		}

		glVertex2d(startPos.x, startPos.y);
		glVertex2d(endPos.x, endPos.y);
	}
	glEnd();

	// draws all masses
	for (size_t i = 0; i < sms_.getNumMasses(); i++)
	{
		MassProxy mp = sms_.getMassProxy(i);
		Vector2<> massPos = mp.getPos();
		double invMass = mp.getInvMass();
		double massSize;
		if (invMass == 0.0)
			massSize = MASS_SIZE;
		else
			massSize = MASS_SIZE / sqrt(invMass);
		glBegin(GL_TRIANGLE_FAN);
			if (invMass != 0.0)
				glColor3f(1.0, 1.0, 0.5);
			else
				glColor3f(0.5, 1.0, 0.5);
			glVertex2d(massPos.x, massPos.y);
			for (int j = 0; j <= POLY_SIDES; j++)
				glVertex2d(
					massPos.x + massSize * cos(j * (2.0 * PI / POLY_SIDES)),
					massPos.y + massSize * sin(j * (2.0 * PI / POLY_SIDES)));
		glEnd();
	}

	// draws some text
	std::ostringstream oss;
	oss << "Energy: " << sms_.getEnergy();
	acf_.drawstring(oss.str().c_str(), -0.9f, 0.9f, 0xdddddd, 0.05f);
	oss.str("");
	oss << "Potential energy: " << sms_.getPotentialEnergy();
	acf_.drawstring(oss.str().c_str(), -0.9f, 0.8f, 0xdddddd, 0.05f);
	oss.str("");
	oss << "Kinetic energy: " << sms_.getKineticEnergy();
	acf_.drawstring(oss.str().c_str(), -0.9f, 0.7f, 0xdddddd, 0.05f);

	SDL_GL_SwapBuffers();
}
