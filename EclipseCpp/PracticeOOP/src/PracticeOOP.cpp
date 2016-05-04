#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <sstream>
#include <stdio.h>
#include <string>
#include "Tile.h"
#include <vector>
#include "Texture.h"

using namespace std;

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 640;

bool init();
bool loadMedia();
void loadTiles();

SDL_Texture* loadTexture(std::string path);
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* background = NULL;

Tile gameBoard(0, 20, 180, 440, 440);
const int row = 4;
const int col = 4;
Tile tiles[row][col];

SDL_Color emptyTile = { 205, 193, 181, 0 };
SDL_Color gameBoardColor = { 200, 184, 148, 0 };
SDL_Color tile2 = { 238, 228, 218, 0 };
SDL_Color tile4 = { 236, 224, 102, 0 };
SDL_Color tile8 = { 245, 149, 99, 0 };
SDL_Color tile16 = { 245, 149, 99, 0 };
SDL_Color tile32 = { 246, 124, 99, 0 };
SDL_Color tile64 = { 246, 94, 59, 0 };
SDL_Color tile128 = { 237, 207, 114, 0 };
SDL_Color tile256 = { 237, 204, 97, 0 };
SDL_Color tile512 = { 237, 204, 97, 0 };
SDL_Color tile1024 = { 238, 194, 46, 0 };
SDL_Color tile2048 = { 246, 175, 64, 0 };

SDL_Color fontColor = { 0, 0, 0, 0 };

TTF_Font *infoFont = NULL;
Texture gText;

int main(int args, char* argc[]) {

	srand(time(0));

	if (!init()) {
		printf("Failed to initialize!\n");
	} else {
		//Load media
		if (!loadMedia()) {
			printf("Failed to load media!\n");
		} else {
			loadTiles();
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit) {

				while (SDL_PollEvent(&e) != 0) {
					//User requests quit

					switch (e.type) {
					case SDL_QUIT:
						quit = true;
						break;

					case SDLK_DOWN:

						break;

					case SDLK_UP:

						break;

					case SDLK_RIGHT:

						break;

					case SDLK_LEFT:

						break;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				SDL_RenderClear(gRenderer);

				SDL_RenderCopy(gRenderer, background, NULL, NULL);

				gameBoard.Draw(gRenderer);
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						tiles[i][j].Draw(gRenderer);
						if (tiles[i][j].GetNumber() != 0) {
							stringstream ss;
							ss << tiles[i][j].GetNumber();
							gText.loadFromRenderedText(gRenderer, infoFont,
									ss.str(), fontColor);
							gText.renderText(gRenderer, 68 + (j * 104),
									228 + (i * 104));
							ss << "";
							ss.clear();
						}
					}
				}

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}
	return 0;
}

bool init() {

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("TEAM KENO", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			success = false;
		} else {
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 251, 248, 241, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf(
							"SDL_image could not initialize! SDL_image Error: %s\n",
							IMG_GetError());
					success = false;
				}

				if (TTF_Init() == -1) {
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
					TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

//Load all images, sounds and, fonts
bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load PNG background texture
	background = loadTexture("Images/background.png");
	if (background == NULL) {
		printf("Failed to load background texture image!\n");
		success = false;
	}

	infoFont = TTF_OpenFont("Fonts/Days.otf", 25);
	if (infoFont == NULL) {
		printf("Failed to load Days font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	} else {
		//Render text
		SDL_Color textColor = { 0, 0, 0 };
		if (!gText.loadFromRenderedText(gRenderer, infoFont,
				"The quick brown fox jumps over the lazy dog", textColor)) {
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	return success;
}

SDL_Texture* loadTexture(std::string path) {
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
		IMG_GetError());
	} else {
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n",
					path.c_str(), SDL_GetError());
		}

		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

void loadTiles() {
	gameBoard.SetColor(gameBoardColor);
	int value = 0;
	int tileX = 28;
	int tileY = 188;

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			tiles[row][col].SetNumber(value);
			tiles[row][col].setNX(tileX);
			tiles[row][col].setNY(tileY);
			tiles[row][col].setNWidth(100);
			tiles[row][col].setNHeight(100);
			tiles[row][col].SetColor(emptyTile);
			tileX += 108;
		}
		tileX = 28;
		tileY += 108;
	}

	for (int row = 0; row < 2; row++) {
		int randRow = 0 + rand() % 4;
		int randCol = 0 + rand() % 4;
		if (1 + rand() % 100 < 70) {
			value = 2;
			if (tiles[randRow][randCol].GetNumber() == 0) {
				tiles[randRow][randCol].SetNumber(value);
				tiles[randRow][randCol].SetColor(tile2);
			} else {
				row--;
			}
		} else {
			value = 4;
			if (tiles[randRow][randCol].GetNumber() == 0) {
				tiles[randRow][randCol].SetNumber(value);
				tiles[randRow][randCol].SetColor(tile4);
			} else {
				row--;
			}
		}

	}
}

