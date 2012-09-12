#include "CApp.h"
 
void CApp::OnEvent(SDL_Event* Event) {
	CEvent::OnEvent(Event);
}

void CApp::OnExit(){
	_running = false;
}

void CApp::OnLButtonDown(int mX, int mY){
	int id = mX / 200;
	id = id + ((mY / 200) * 3);

	if(grid[id] != GRID_TYPE_NONE){
		return;
	}

	if(currentPlayer == 0){
		SetCell(id, GRID_TYPE_X);
		currentPlayer = 1;
	} else {
		SetCell(id, GRID_TYPE_O);
		currentPlayer = 0;
	}

	CheckGameOver();
}