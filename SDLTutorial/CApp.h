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
 
private:
	int grid[9];
	int currentPlayer;
	
	int freeCells;
	bool gameOver;

	enum {
		GRID_TYPE_NONE = 0,
		GRID_TYPE_X,
		GRID_TYPE_O
	};


public:
	CApp();
	int OnExecute(); 

public:
	bool OnInit();
	
	void OnEvent(SDL_Event* Event);
	void OnExit();	// exit event
	void OnLButtonDown(int mX, int mY);	// LeftMouseDown event

	void OnLoop();
	void OnRender();
	void OnCleanup();

public:
	void Reset();
	void SetCell(int id, int type);
	void CheckGameOver();
};
 
#endif