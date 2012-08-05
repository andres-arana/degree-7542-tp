#include "video.h"
#include <SDL.h>
#include <SDL_opengl.h>

Video::Video(const Config& config)
{
	int w = config.read<int>("Video.Width");
	int h = config.read<int>("Video.Height");
	int depth = config.read<int>("Video.Depth");
	
	SDL_InitSubSystem(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_SetVideoMode(w, h, depth, SDL_OPENGL);

	SDL_WM_SetCaption("Spring System Demo", 0);

	glMatrixMode(GL_PROJECTION);
	double ar = static_cast<double>(w) / h;
	glOrtho(-ar, ar, -1.0, 1.0, -1.0, 1.0);
}

Video::~Video()
{
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
}
