#pragma once

#include <SDL.h>

class CSurface
{
public:
	CSurface(void);
	
public:
	static SDL_Surface* OnLoad(char* file);

	static bool OnDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y);
};

