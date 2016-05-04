//============================================================================
// Name        : FlippingCards.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "Texture.h"
#include "Game.h"

using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 683;

int posX = 0;
int posY = 0;

int ofSetX = 1;
int ofSetY = 1;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

SDL_Texture* gback;

Texture gBackground;
Texture gCard;
Texture gDeal;
Texture gAutoHold;
Texture gDraw;
Texture gInfo;
Texture gHelp;

Mix_Music *gMusic = NULL;
Mix_Chunk *gBeat = NULL;

void update()
{

	posY += ofSetY;
	posX += ofSetX;

	if (posY >= 480 - 120)
	{
		ofSetY *= -1;
	}
	if (posY <= 0)
	{
		ofSetY *= -1;
	}

	if (posX >= 640 - 90)
	{
		ofSetX *= -1;
	}
	if (posX <= 0)
	{
		ofSetX *= -1;
	}
}
int main(int args, char* argc[])
{
	SDL_RenderClear(gRenderer);
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = SCREEN_WIDTH;
	rect.h = SCREEN_HEIGHT;

	Game game;

	int holdX = 100;
	int holdY = 400;

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
			Mix_PlayMusic(gMusic, -1);
			bool quit = false;
			SDL_Event e;
			bool key = false;
			bool deal = false;
			bool info = false;
			int x, y;
			while (!quit)
			{

				while (SDL_PollEvent(&e) != 0)
				{
					switch (e.type)
					{
					case SDL_QUIT:
						quit = true;
						break;
					case SDL_MOUSEBUTTONDOWN:
						SDL_GetMouseState(&x, &y);

						if (x > 700 && x < 800 && y > 620 && y < 670)
						{
							game.dealCards();
							game.autoHold();

							deal = !deal;
						}
						if (x > 830 && x < 930 && y > 620 && y < 670)
						{
							game.secondDealCards();
						}
						if (x > 137 && x < 887 && y > 400 && y < 590)
						{
							if (game.hand[(x - 137) / 150].isHold())
							{
								game.hand[(x - 137) / 150].Unhold();
							}
							else
							{
								game.hand[(x - 137) / 150].Hold();
							}

						}

						if (e.button.x > 10 && e.button.x < 60
								&& e.button.y > 620 && e.button.y < 670)
						{
							info = !info;

						}
						break;

					}
					if (e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
						case SDLK_1:
							key = !key;
							break;
						}
					}
				}
				SDL_RenderCopy(gRenderer, gBackground.getTexture(), &rect,
				NULL);
				gDeal.button(gRenderer, 700, 620, 100, 50);
				gInfo.button(gRenderer, 10, 620, 50, 50);
				gDraw.button(gRenderer, 830, 620, 100, 50);

				if (deal == false)
				{
					gCard.card(gRenderer, 158, 492, 137, 400);
					gCard.card(gRenderer, 158, 492, 287, 400);
					gCard.card(gRenderer, 158, 492, 437, 400);
					gCard.card(gRenderer, 158, 492, 587, 400);
					gCard.card(gRenderer, 158, 492, 737, 400);
				}
				else
				{
					int y = game.hand[0].getSuit() * 123;
					int x = game.hand[0].getFace() * 79;
					gCard.card(gRenderer, x, y, 137, 400);

					y = game.hand[1].getSuit() * 123;
					x = game.hand[1].getFace() * 79;
					gCard.card(gRenderer, x, y, 287, 400);

					y = game.hand[2].getSuit() * 123;
					x = game.hand[2].getFace() * 79;
					gCard.card(gRenderer, x, y, 437, 400);

					y = game.hand[3].getSuit() * 123;
					x = game.hand[3].getFace() * 79;
					gCard.card(gRenderer, x, y, 587, 400);

					y = game.hand[4].getSuit() * 123;
					x = game.hand[4].getFace() * 79;
					gCard.card(gRenderer, x, y, 737, 400);

					for (unsigned i = 0; i < 5; i++)
					{
						if (game.hand[i].isHold())
						{
							gAutoHold.button(gRenderer, holdX + 30, holdY + 77, 90, 35);
						}

						holdX += 150;

					}
					holdX = 137;
				}

				if (info == true)
				{
					SDL_RenderCopy(gRenderer, gHelp.getTexture(), &rect,
					NULL);
					gInfo.button(gRenderer, 10, 620, 50, 50);
				}
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

		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
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
				Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;
	gMusic = Mix_LoadMUS("Modest Intentions - Cold Autumn.mp3");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
		Mix_GetError());
		success = false;
	}

	if (!gBackground.loadFromFile(gRenderer, "background.jpg"))
	{
		printf("Failed to load Foo' texture image!\n");
		success = false;
	}

	if (!gCard.loadFromFile(gRenderer, "Cards.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!gHelp.loadFromFile(gRenderer, "info.jpg"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	if (!gDeal.loadFromFile(gRenderer, "deal.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	if (!gInfo.loadFromFile(gRenderer, "i.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	if (!gAutoHold.loadFromFile(gRenderer, "hold.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!gDraw.loadFromFile(gRenderer, "draw.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}
	return success;
}

void close()
{
	gBackground.free();
	gCard.free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
