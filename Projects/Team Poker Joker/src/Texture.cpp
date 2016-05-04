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
bool Texture::loadFromRenderedText(SDL_Renderer* gRenderer, TTF_Font* gFont,
		string textureText, SDL_Color textColor)
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(),
			textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n",
		TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL)
		{
			printf(
					"Unable to create texture from rendered text! SDL Error: %s\n",
					SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	//Return success
	return mTexture != NULL;
}

void Texture::render(SDL_Renderer* gRenderer, int x, int y)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad =
	{ x, y, mWidth, mHeight };

	//Render to screen
	SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
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
int Texture::getWidth()
{
	return mWidth;
}

int Texture::getHeight()
{
	return mHeight;
}

SDL_Texture* Texture::getTexture()
{
	return mTexture;
}
