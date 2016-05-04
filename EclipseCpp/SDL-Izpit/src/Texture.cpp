#include "Texture.h"

Texture::Texture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Texture::~Texture()
{
	free();
}

bool Texture::loadFromFile(SDL_Renderer* gRender, string path)
{
	free();

	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	SDL_Surface* optimizedSuraface = NULL;
	if (loadedSurface == NULL)
	{
		cout << "Could not load the Texture	" << SDL_GetError();
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 0, 0, 0));
		optimizedSuraface = SDL_ConvertSurface(loadedSurface,
				loadedSurface->format, 0);
		newTexture = SDL_CreateTextureFromSurface(gRender, optimizedSuraface);
		if (newTexture == NULL)
		{
			cout << "Texture could not be created !!! " << SDL_GetError();
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	mTexture = newTexture;
	return mTexture != NULL;
}

void Texture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Texture::render(SDL_Renderer* gRender, int srcX, int srcY, int destX,
		int destY)
{

	SDL_Rect src =
	{ srcX, srcY, 180, 180 };
	SDL_Rect dest =
	{ destX, destY,33, 35 };
	SDL_RenderCopy(gRender, mTexture, &src, &dest);
}
void Texture::button(SDL_Renderer* gRender, int destX, int destY, int srcW,
		int srcH)
{
	SDL_Rect src =
	{ 0, 0, 480, 480 };
	SDL_Rect dest =
	{ destX, destY, srcW, srcH };
	SDL_RenderCopy(gRender, mTexture, &src, &dest);
}


int Texture::getWidth()
{
	return mWidth;
}

int Texture::getHeight()
{
	return mHeight;
}

SDL_Texture*& Texture::getTexture()
{
	return mTexture;
}
