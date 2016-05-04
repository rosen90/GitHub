/*
 * IDrawableObject.h
 *
 *  Created on: Nov 11, 2014
 *      Author: Rosen
 */

#ifndef IDRAWABLEOBJECT_H_
#define IDRAWABLEOBJECT_H_

struct SDL_Renderer;

class IDrawableObject {
public:
	virtual void Draw(SDL_Renderer*) = 0;
	virtual void LoadFromFile(SDL_Renderer*,const char*) = 0;
	virtual void Free() = 0;
	virtual int GetX() = 0;
	virtual int GetY() = 0;
	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
	virtual void SetDimentions(int width, int height) = 0;
	virtual ~IDrawableObject(){};
};

#endif /* IDRAWABLEOBJECT_H_ */
