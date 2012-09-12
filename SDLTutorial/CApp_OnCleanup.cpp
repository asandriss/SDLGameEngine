#include "CApp.h"
 
void CApp::OnCleanup() {
	SDL_FreeSurface(surf_grid);
	SDL_FreeSurface(surf_X);
	SDL_FreeSurface(surf_O);

	SDL_FreeSurface(surf_display);
	
	SDL_Quit();
}