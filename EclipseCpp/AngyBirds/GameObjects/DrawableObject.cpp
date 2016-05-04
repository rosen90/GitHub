/*
 * DrawableObject.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: Rosen
 */

#include "DrawableObject.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_image.h"
#include "../Interfaces/Constants.h"

DrawableObject::DrawableObject(int width, int height) {
	m_Texture = NULL;
	SetDimentions(width, height);
}

void DrawableObject::Draw(SDL_Renderer* g_Renderer) {
	if(m_Texture){
		SDL_Rect rect = {
			GetX(),
			GetY(),
			GetWidth(),
			GetHeight()
		};
		SDL_RenderCopy(g_Renderer, m_Texture, NULL, &rect);
	}
}

void DrawableObject::LoadFromFile(SDL_Renderer* g_Renderer,const char* path) {
	SDL_Surface* loadedSurface = IMG_Load(path);
	m_Texture = SDL_CreateTextureFromSurface(g_Renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
}

int DrawableObject::GetWidth() {
	return m_PixWidth;
}

int DrawableObject::GetHeight() {
	return m_PixHeight;
}

void DrawableObject::SetDimentions(int width, int height) {
	m_PixHeight = height;
	m_PixWidth = width;
}

void DrawableObject::Free() {
	if(m_Texture){
		SDL_DestroyTexture(m_Texture);
		m_Texture = NULL;
	}
}

DrawableObject::~DrawableObject() {
	Free();
}

