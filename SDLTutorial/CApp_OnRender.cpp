#include "CApp.h"
 
void CApp::OnRender() {
	CSurface::OnDraw(_surf_Display, _surf_test, 0, 0);

	// refresh the buffer and show background surface
	SDL_Flip(_surf_Display);
}