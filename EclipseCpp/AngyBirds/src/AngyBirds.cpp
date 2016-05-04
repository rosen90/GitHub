//============================================================================
// Name        : AngyBirds.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <Box2D/Box2D.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../GameObjects/Bird.h"
#include "../Interfaces/Constants.h"
#include "../GameObjects/PhisicsManager.h"

using namespace std;


SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;


bool init() {

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0)
	{
		success = false;
	}
	else
	{

		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			success = false;
		}
		else
		{
			//Create window
			gWindow = SDL_CreateWindow("TEAM KENO", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (gWindow == NULL) {
				success = false;
			}
			else
			{
				//Create renderer for window
				gRenderer = SDL_CreateRenderer(gWindow, -1,
						SDL_RENDERER_PRESENTVSYNC);
				if (gRenderer == NULL) {
					success = false;
				}
				else
				{
					//Initialize renderer color
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				}
			}
		}
	}
	return success;
}

int main(int args, char* argc[]) {

	init();
	PhisicsManager mngr;
	Bird bird(100,500,30,30);
	bird.LoadFromFile(gRenderer, "Img/bird.png");
	mngr.RegisterAnObject(&bird);
	bird.ChangeBaseVelocity(10);
	bool quit = false;
	SDL_Event e;
	while(!quit){
		while(SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
		SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
		SDL_RenderClear(gRenderer);
		bird.Draw(gRenderer);
		mngr.SimulateStep();
		cout<<bird.GetX()<<endl;
		SDL_RenderPresent(gRenderer);
	}
	return 0;
}
