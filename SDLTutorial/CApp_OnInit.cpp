#include "CApp.h"
 
bool CApp::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		return false;
	}

	_surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(_surf_Display == NULL)
		return false;

	_surf_test = CSurface::OnLoad("Splash.bmp");
	if(_surf_test == NULL)
		return false;

	return true;
}