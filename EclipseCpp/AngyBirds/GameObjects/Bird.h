/*
 * Bird.h
 *
 *  Created on: Nov 11, 2014
 *      Author: Rosen
 */

#ifndef BIRD_H_
#define BIRD_H_

#include "PhisicalObject.h"
#include <Box2D/Collision/Shapes/b2PolygonShape.h>


class Bird: public PhisicalObject {
public:
	Bird(int x, int y, int width, int height);
	virtual void SetDimentions(int width, int height);
	virtual void Free();
	virtual ~Bird();
public:
	b2PolygonShape m_birdShape;
};

#endif /* BIRD_H_ */
