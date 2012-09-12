#include "CApp.h"
 
bool CApp::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		return false;
	}

	surf_display = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(surf_display == NULL)
		return false;

	// todo: move images to gfx folder!

	// load surfaces
	surf_grid = CSurface::OnLoad("grid.bmp");
	if (surf_grid == NULL)
		return false;

	surf_X = CSurface::OnLoad("x.bmp");
	if (surf_X == NULL)
		return false;

	surf_O = CSurface::OnLoad("o.bmp");
	if (surf_O == NULL)
		return false;

	// Set transparecy colors for X and O images
	CSurface::Transparent(surf_X, 255, 0, 255);
	CSurface::Transparent(surf_O, 255, 0, 255);
		
	return true;
}