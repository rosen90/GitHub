#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "Texture.h"

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

SDL_Texture* gback;

Texture gWinter;
Texture gSummer;
Texture gDonkey;
Texture gAutumn;
Texture gSpring;
Texture gButton;

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
			int counter = 1;
			SDL_Event e;

			while (!quit)
			{
					while( SDL_PollEvent( &e ) != 0 )
					{
						switch (e.type)
						{
						case SDL_QUIT:
							quit = true;
							break;
						case SDL_MOUSEBUTTONDOWN:
							if (e.button.x > 550 && e.button.x < 590
									&& e.button.y > 400 && e.button.y < 440)
							{
								counter++;
							}
							break;
						}
					}

				switch(counter)
				{
				 case 1: SDL_RenderCopy(gRenderer, gDonkey.getTexture(), &rect, NULL);
				    	break;
				 case 2: SDL_RenderCopy(gRenderer, gSummer.getTexture(), &rect, NULL);
					    break;
				 case 3: SDL_RenderCopy(gRenderer, gAutumn.getTexture(), &rect, NULL);
					    break;
				 case 4: SDL_RenderCopy(gRenderer, gSpring.getTexture(), &rect, NULL);
						break;
				 case 5: SDL_RenderCopy(gRenderer, gWinter.getTexture(), &rect, NULL);
				 	    break;
				 default: counter = 0;

				}

				gButton.button(gRenderer, 550, 400, 50, 50);

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

		gWindow = SDL_CreateWindow("Rosen Button", SDL_WINDOWPOS_UNDEFINED,
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

	if (!gAutumn.loadFromFile(gRenderer, "Images/Autumn.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!gDonkey.loadFromFile(gRenderer, "Images/Donkey.png"))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}


	if (!gSpring.loadFromFile(gRenderer, "Images/Spring.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!gSummer.loadFromFile(gRenderer, "Images/Summer.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	if (!gWinter.loadFromFile(gRenderer, "Images/Winter.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	if (!gButton.loadFromFile(gRenderer, "Images/Button.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}


	return success;
}

void close()
{
	gAutumn.free();
	gDonkey.free();
	gSpring.free();
	gSummer.free();
	gWinter.free();
	gButton.free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
