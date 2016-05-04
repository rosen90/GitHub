/*
 * Bird.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: Rosen
 */

#include "Bird.h"
#include "../Interfaces/Constants.h"

Bird::Bird(int x, int y, int width, int height) : PhisicalObject(x, y, width, height,
		b2_dynamicBody, 1, 180, 45)
{
	m_Shape = &m_birdShape;
}

void Bird::SetDimentions(int width, int height) {
	DrawableObject::SetDimentions(width, height);
	m_birdShape.SetAsBox(GetWidth() / XPIX_RATIO / 2, GetHeight() / YPIX_RATIO / 2);
}

Bird::~Bird() {
	Free();
}

void Bird::Free() {
	PhisicalObject::Free();
}
