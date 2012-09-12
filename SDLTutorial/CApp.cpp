#include "CApp.h"
#include <Windows.h>

CApp::CApp() {
	_surf_Display = NULL;
	_surf_test = NULL;

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