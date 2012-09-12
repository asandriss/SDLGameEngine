#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include "CEvent.h"
#include "CSurface.h"

class CApp : public CEvent {
private:
	bool _running;

	SDL_Surface* _surf_Display;
	SDL_Surface* _surf_test;
 
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