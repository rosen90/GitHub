/*
 * DrawableObject.h
 *
 *  Created on: Nov 11, 2014
 *      Author: Rosen
 */

#ifndef DRAWABLEOBJECT_H_
#define DRAWABLEOBJECT_H_

#include "../Interfaces/IDrawableObject.h"

#include <SDl2/SDL_rect.h>

struct SDL_Texture;

class DrawableObject : public IDrawableObject{
public:
	DrawableObject(int width, int height);
	virtual void Draw(SDL_Renderer*);
	virtual void Free();
	virtual void LoadFromFile(SDL_Renderer*,const char*);
	virtual int GetWidth();
	virtual int GetHeight();
	virtual void SetDimentions(int width, int height);
	virtual ~DrawableObject();
protected:
	SDL_Texture* m_Texture;
	int m_PixWidth, m_PixHeight;
};

#endif /* DRAWABLEOBJECT_H_ */
