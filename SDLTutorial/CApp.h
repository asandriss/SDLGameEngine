#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL.h>
#include "Surface.h"

class CApp {
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
	void OnLoop();
	void OnRender();
	void OnCleanup();
};
 
#endif