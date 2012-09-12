#include "CApp.h"
#include <Windows.h>

CApp::CApp() {
	currentPlayer = 0;

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
}

 void CApp::SetCell(int id, int type){
	 if(id < 0 || id >=9) return;
	 if(type < 0 || type > GRID_TYPE_O) return;

	 grid[id] = type;
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