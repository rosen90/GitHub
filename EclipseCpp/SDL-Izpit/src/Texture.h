#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <iostream>
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
using namespace std;
class Texture
{

public:
	Texture();
	virtual ~Texture();
	bool loadFromFile(SDL_Renderer* gRender, string path);
	void free();
	void render(SDL_Renderer* gRender, int srcX, int srcY, int destX,
			int destY);
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

#endif
