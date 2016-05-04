/*
 * Texture.h
 *
 *  Created on: Sep 24, 2014
 *      Author: vasko
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <iostream>
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
using namespace std;
#include "Game.h"
class Texture
{

public:
	Texture();
	virtual ~Texture();
	bool loadFromFile(SDL_Renderer* gRender, string path);
	void free();
	void card(SDL_Renderer* gRender, int srcX, int srcY, int destX, int destY);
	void button(SDL_Renderer* gRender, int destX, int destY, int srcW,
			int srcH);

	int getWidth();
	int getHeight();
	SDL_Texture*& getTexture();

private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
};

#endif /* TEXTURE_H_ */
