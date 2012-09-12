#include "Surface.h"


CSurface::CSurface(void)
{
}


// Load BMP image file and create a surface from it
SDL_Surface* CSurface::OnLoad(char* file) {
	SDL_Surface* surf_temp = NULL;
	SDL_Surface* surf_return = NULL;

	surf_temp = SDL_LoadBMP(file);

	if(surf_temp == NULL)
		return NULL;

	// Take existing surface and convert it to the same format as the display
	surf_return = SDL_DisplayFormat(surf_temp);

	// Unload temp surface
	SDL_FreeSurface(surf_temp);

	return surf_return;
}

// Draw a (full) surface on another surface at specified position
bool CSurface::OnDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y) {
	if(surf_dest == NULL || surf_src == NULL) {
		return false;
	}

	SDL_Rect destR;

	destR.x = x;
	destR.y = y;

	SDL_BlitSurface(surf_src, NULL, surf_dest, &destR);

	return true;
}
