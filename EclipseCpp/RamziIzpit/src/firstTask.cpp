/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 440;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* gTexture = NULL;
SDL_Texture* gWheel = NULL;
SDL_Texture* gChip = NULL;
SDL_Texture* gBall = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Ramzi Roulette", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load texture
	gTexture = loadTexture( "roulette.png" );
	if( gTexture == NULL )
	{
		printf( "Failed to load texture image!\n" );
		success = false;
	}

	gWheel = loadTexture( "wheel2.png" );
		if( gTexture == NULL )
		{
			printf( "Failed to load texture image!\n" );
			success = false;
		}

		gChip = loadTexture( "chip.png" );
				if( gTexture == NULL )
				{
					printf( "Failed to load texture image!\n" );
					success = false;
				}


	gBall = loadTexture("ball.png");
	if (gTexture == NULL) {
		printf("Failed to load texture image!\n");
		success = false;
	}


	//Nothing to load
	return success;
}

void close()
{
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	SDL_DestroyTexture(gWheel);
	gWheel = NULL;

	SDL_DestroyTexture(gChip);
	gChip = NULL;

	SDL_DestroyTexture(gBall);
	gBall = NULL;

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer,11,110,10, 0xFF );
				SDL_RenderClear( gRenderer );

				SDL_Rect topLeftViewport;
				topLeftViewport.x = 300;
				topLeftViewport.y = 60;
				topLeftViewport.w = SCREEN_WIDTH-300;
				topLeftViewport.h = SCREEN_HEIGHT-140;
				SDL_RenderSetViewport( gRenderer, &topLeftViewport );
				
				//Render texture to screen
				SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );



				SDL_Rect topRightViewport;
				topRightViewport.x = 0;
				topRightViewport.y =65;
				topRightViewport.w = 325;
				topRightViewport.h = 300;
				SDL_RenderSetViewport( gRenderer, &topRightViewport );

				//Render texture to screen
				SDL_RenderCopy( gRenderer, gWheel, NULL, NULL );


//
				SDL_Rect bottomViewport;
				bottomViewport.x =375;
				bottomViewport.y = 150;
				bottomViewport.w = 80;
				bottomViewport.h = 64;
				SDL_RenderSetViewport( gRenderer, &bottomViewport );


				//Render texture to screen
				SDL_RenderCopy( gRenderer, gChip, NULL, NULL );


				SDL_Rect bottomViewport2;
				bottomViewport2.x = 810;
				bottomViewport2.y = 200;
				bottomViewport2.w = 80;
				bottomViewport2.h = 64;
				SDL_RenderSetViewport(gRenderer, &bottomViewport2);

				//Render texture to screen
				SDL_RenderCopy( gRenderer, gChip, NULL, NULL );

				SDL_Rect bottomViewport3;
				bottomViewport3.x = 600;
				bottomViewport3.y = SCREEN_HEIGHT - 64;
				bottomViewport3.w = 80;
				bottomViewport3.h = 64;
				SDL_RenderSetViewport(gRenderer, &bottomViewport3);

				//Render texture to screen
				SDL_RenderCopy( gRenderer, gChip, NULL, NULL );


				SDL_Rect bottomViewportball;
				bottomViewportball.x =244;
				bottomViewportball.y = 209;
				bottomViewportball.w = 30;
				bottomViewportball.h = 20;
				SDL_RenderSetViewport(gRenderer, &bottomViewportball);

				//Render texture to screen
				SDL_RenderCopy( gRenderer, gBall, NULL, NULL );


				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
