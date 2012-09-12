#include "CApp.h"
#include <Windows.h>

CApp::CApp() {
	gameOver = false;

	surf_grid = NULL;
	surf_X = NULL;
	surf_O = NULL;

	surf_display = NULL;

	_running = true;
}
 
int CApp::OnExecute() {
    if(OnInit() == false) {
		return -1;
	}

	SDL_Event Event;

	while(_running){
		while(SDL_PollEvent(&Event)){
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

void CApp::Reset(){
	for(int i=0; i<9; i++){
		grid[i] = GRID_TYPE_NONE;
	}

	freeCells = 9;
	currentPlayer = 0;
	gameOver = false;
}

 void CApp::SetCell(int id, int type){
	 if(id < 0 || id >=9) return;
	 if(type < 0 || type > GRID_TYPE_O) return;

	 grid[id] = type;
	 freeCells--;
 }

void CApp::CheckGameOver() {
	// check rows
	for(int i=0; i<9; i+=3){
		if( (grid[i] != GRID_TYPE_NONE) && (grid[i] == grid[i+1]) && (grid[i] == grid[i+2]) ){
		gameOver = true;
		}
	}

	if(!gameOver){
		// check columns
		for(int i=0; i<3; i++) {
			if ( (grid[i] != GRID_TYPE_NONE) && (grid[i] == grid[i+3]) && (grid[i] == grid[i+6]) ){
				gameOver = true;
			}
		}
	}

	if(!gameOver){
		// check diagonals
		if( (grid[4] != GRID_TYPE_NONE) && ((grid[4] == grid[8]) && (grid[4] == grid[0])
										|| ((grid[4] == grid[2]) && (grid[4] == grid[6])))
			){
				gameOver = true;
		}
	}

	if(freeCells == 0 || gameOver) {
		OnRender();
		SDL_Delay(1000);
		Reset();
	}
}

 

//int main(int argc, char* argv[]) {
// using WinMain instead of main to hide console window.
int WINAPI WinMain( HINSTANCE hInstance, 
					HINSTANCE hPrevInstance, 
					LPSTR lpCmdLine, 
					int nCmdShow) 
{ 
	CApp theApp;
 
    return theApp.OnExecute();
}