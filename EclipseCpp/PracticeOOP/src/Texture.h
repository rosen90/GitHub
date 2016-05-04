#include <stdio.h>
#include <string>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

#ifndef TEXTURE_H_
#define TEXTURE_H_

class Texture {
public:
	Texture();

	void free();
	bool loadFromRenderedText(SDL_Renderer*, TTF_Font*, string, SDL_Color);
	void renderText(SDL_Renderer*, int x, int y);

	virtual ~Texture();

private:
private:
	SDL_Texture* mTexture;

	int mWidth;
	int mHeight;
};

#endif /* TEXTURE_H_ */
