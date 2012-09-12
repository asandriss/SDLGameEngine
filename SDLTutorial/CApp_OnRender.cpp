#include "CApp.h"
 
void CApp::OnRender() {
	CSurface::OnDraw(surf_display, surf_grid, 0, 0);

	// refresh the buffer and show background surface
	SDL_Flip(surf_display);
}