/*
 * PhisicalObject.h
 *
 *  Created on: Nov 11, 2014
 *      Author: Rosen
 */

#ifndef PHISICALOBJECT_H_
#define PHISICALOBJECT_H_

#include "DrawableObject.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "Box2D/Collision/Shapes/b2Shape.h"

class PhisicalObject: public DrawableObject {

	friend class PhisicsManager;

public:
	PhisicalObject(int x, int y, int width, int height, b2BodyType type = b2_staticBody,
			float baseVelocity = 0, float angVelDeg = 0,
			float launchAngleDeg = 0, float spinAnlgeDeg = 0);
	virtual int GetX();
	virtual int GetY();
	virtual void Free();
	void ChangeBaseVelocity(float baseVelocity);
	void ChangeSpinAngle(float spinAngleDeg);
	void SetLaunchAngle(float launchAngleDeg);
	void SetPosition(int x, int y);
	void ChangeType(b2BodyType type);
	void ChangeAngularVelocity(float angVelDeg);
	virtual ~PhisicalObject();

protected:
	b2Shape* m_Shape;

private:
	b2BodyDef m_BodyDef;
	b2Body* m_Body;
	b2Fixture* m_fixture;
	float m_fLaunchAngle;
	float m_fBaseVelocity;

	void SetLinearVelosity();
	void ApplyPhisics(b2World* world);
};

#endif /* PHISICALOBJECT_H_ */
