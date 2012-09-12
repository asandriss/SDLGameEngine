#include "CApp.h"
 
void CApp::OnCleanup() {
	SDL_FreeSurface(_surf_test);
	SDL_FreeSurface(_surf_Display);
	SDL_Quit();
}