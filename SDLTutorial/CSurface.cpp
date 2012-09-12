#include "CSurface.h"


CSurface::CSurface(void) {}


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

// Draw part of a surface on another surface at specified position and from specified location and size
bool CSurface::OnDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int x, int y, int x2, int y2, int w, int h){
	if(surf_dest == NULL || surf_src == NULL) {
		return false;
	}

	SDL_Rect destR;

	destR.x = x;
	destR.y = y;

	SDL_Rect srcR;

	srcR.x = x2;
	srcR.y = y2;
	srcR.w = w;
	srcR.h = h;

	SDL_BlitSurface(surf_src, &srcR, surf_dest, &destR);

	return true;
}


bool CSurface::Transparent(SDL_Surface* surf_dest, int r, int g, int b) {
	if(surf_dest == NULL){
		return false;
	}

	SDL_SetColorKey(surf_dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(surf_dest->format, r, g, b));

	return true;
}