#pragma once

#include <SDL.h>

class CSurface
{
public:
	CSurface(void);
	
public:
	// Load BMP image file and create a surface from it
	static SDL_Surface* OnLoad(char* file);

	// Draw a (full) surface on another surface at specified position
	static bool OnDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y);

	// Draw part of a surface on another surface at specified position and from specified location and size
	static bool OnDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y, int x2, int y2, int w, int h);
};

