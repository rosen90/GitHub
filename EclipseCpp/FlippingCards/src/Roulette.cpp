#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "Texture.h"

using namespace std;

const int SCREEN_WIDTH = 686;
const int SCREEN_HEIGHT = 210;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

SDL_Texture* gback;

Texture gBoard;
Texture gWheel;

SDL_Rect gSpriteChips[ 4 ];
Texture gChip;

SDL_Surface* gscreenSurface = NULL;


int main(int args, char* argc[])
{
	SDL_RenderClear(gRenderer);
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = SCREEN_WIDTH;
	rect.h = SCREEN_HEIGHT;

	if (!init())
	{
		cout << "failed to initialize ";
	}
	else
	{
		if (!loadMedia())
		{
			cout << "Error media ";
		}
		else
		{
			bool quit = false;
			SDL_Event e;

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					while( SDL_PollEvent( &e ) != 0 )
					{
						//User requests quit
						if( e.type == SDL_QUIT )
						{
							quit = true;
						}
					}

				}

				SDL_RenderCopy(gRenderer, gBoard.getTexture(), &rect,
				NULL);

				gWheel.wheel(gRenderer, 0,-5 , 216, 216);

				gChip.render(gRenderer, 0, 0, 393, 51);
				gChip.render(gRenderer, 180, 0, 302, 88);
				gChip.render(gRenderer, 360, 0, 406, 154);
				gChip.render(gRenderer, 180, 0, 580, 51);

				SDL_RenderPresent(gRenderer);

			}
		}
	}
	return 0;
}

bool init()
{
	bool success = true;

	if (SDL_Init( SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		gWindow = SDL_CreateWindow("Rosen Roulette", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf(
							"SDL_image could not initialize! SDL_image Error: %s\n",
							IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	if (!gBoard.loadFromFile(gRenderer, "rouletteBoard.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!gWheel.loadFromFile(gRenderer, "RouletteWheel.png"))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}


	if (!gChip.loadFromFile(gRenderer, "chips.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	return success;
}

void close()
{
	gWheel.free();
	gBoard.free();
	gChip.free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
