/*
 * LButton.h
 *
 *  Created on: Sep 18, 2014
 *      Author: Todor
 */

#ifndef LBUTTON_H_
#define LBUTTON_H_
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "StateManager.h"
#include "Timer.h"
using namespace std;
//The mouse button
class Button
{
	public:
		//Initializes internal variables
		Button();

		//Sets top left position
		void Init(SDL_Renderer*);
		void Draw(SDL_Renderer*);
		void Update(SDL_Event);
//		void setPosition( int x, int y, int w, int h );
		void setSource(int, int, int, int );
		void setDestination(int,int,int,int);
        bool isInRect();

		bool isIsClicked() const;
		void setIsClicked(bool isClicked);

	private:
		//Top left position
		int m_X;
		int m_Y;
		int m_W;
		int m_H;
		bool isIn;
		SDL_Renderer* m_r;
		SDL_Texture* m_t;
		SDL_Rect m_source;
		SDL_Rect m_destination;
		bool m_IsClicked;


};

#endif /* LBUTTON_H_ */
