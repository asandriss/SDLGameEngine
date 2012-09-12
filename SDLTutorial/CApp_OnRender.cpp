#include "CApp.h"
 
void CApp::OnRender() {
	CSurface::OnDraw(surf_display, surf_grid, 0, 0);

	// draw Xs and Os on appropriate locations
	for(int i=0; i<9; i++){
		// calculate the location as 0, 1 or 2 times the cell size depending on the array index
		
		//To find X, we take the remainder of i to 3. This will give us 0 when i is 0, 1 when i is 1, 2 when i is 2, 0 when i is 3, and so on.
		int x = (i % 3) * 200;
		//To find Y, we divide by 3, this causes Y to be 0 when i is 0, 1, 2, Y to be 1 when i is 3, 4, 5, and so on.
		int y = (i / 3) * 200;

		// draw the appropriate sprites if needed
		if(grid[i] == GRID_TYPE_X){
			CSurface::OnDraw(surf_display, surf_X, x, y);
		}
		else if(grid[i] == GRID_TYPE_O){
			CSurface::OnDraw(surf_display, surf_O, x, y);
		}
	}

	// refresh the buffer and show background surface
	SDL_Flip(surf_display);
}