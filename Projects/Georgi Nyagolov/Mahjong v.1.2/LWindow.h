#ifndef LWINDOW_H
#define LWINDOW_H
#include <SDL.h>
#include "Global.h"

class LWindow
{
	public:
		//Intializes internals
		LWindow();
		//Creates window
		bool init();
		//Creates renderer from internal window
		SDL_Renderer* createRenderer();
		//Handles window events
		void handleEvent( SDL_Event& e );
		//Deallocates internals
		void free();
		//Window dimensions
		int getWidth();
		int getHeight();
		//Window focii
		bool hasMouseFocus();
		bool hasKeyboardFocus();
		bool isMinimized();
	private:
		//Window data
		SDL_Window* mWindow;
		//Window dimensions
		int mWidth;
		int mHeight;
		//Window focus
		bool mMouseFocus;
		bool mKeyboardFocus;
		bool mFullScreen;
		bool mMinimized;
		//Screen dimension constants
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;
};


#endif // LWINDOW_H
