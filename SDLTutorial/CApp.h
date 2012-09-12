#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include "CEvent.h"
#include "CSurface.h"

class CApp : public CEvent {
private:
	bool _running;

	SDL_Surface* surf_display;

private:
	SDL_Surface* surf_grid;
	SDL_Surface* surf_X;
	SDL_Surface* surf_O;
 
public:
	CApp();
	int OnExecute(); 

public:
	bool OnInit();
	void OnEvent(SDL_Event* Event);
	void OnExit();	// method in OnEvent file
	void OnLoop();
	void OnRender();
	void OnCleanup();
};
 
#endif