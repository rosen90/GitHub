/*
 * PhisicalObject.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: Rosen
 */

#include "PhisicalObject.h"
#include "../Interfaces/Constants.h"
#include "Box2D/Dynamics/b2World.h"

PhisicalObject::PhisicalObject(int x, int y, int width, int height, b2BodyType type,
		float baseVelocity, float angVelDeg,
		float launchAngleDeg, float spinAnlgeDeg) : DrawableObject(width, height) {
	m_Body = NULL;
	m_Shape = NULL;
	SetPosition(x, y);
	SetLaunchAngle(launchAngleDeg);
	ChangeBaseVelocity(baseVelocity);
	ChangeType(type);
	ChangeSpinAngle(spinAnlgeDeg);
	ChangeAngularVelocity(angVelDeg);
}

PhisicalObject::~PhisicalObject() {
	Free();
}

void PhisicalObject::SetPosition(int x, int y) {
	if (!m_Body) {
		m_BodyDef.position.x = x / XPIX_RATIO;
		m_BodyDef.position.y = y / YPIX_RATIO;
	} else {
		m_Body->SetTransform(b2Vec2(x / XPIX_RATIO, y / YPIX_RATIO), m_Body->GetAngle());
	}
}

int PhisicalObject::GetX() {
	if (!m_Body) {
		return m_BodyDef.position.x * XPIX_RATIO;
	} else {
		return m_Body->GetPosition().x * XPIX_RATIO;
	}
}

int PhisicalObject::GetY() {
	if (!m_Body) {
		return m_BodyDef.position.y * YPIX_RATIO;
	} else {
		return m_Body->GetPosition().y * YPIX_RATIO;
	}
}

void PhisicalObject::ChangeType(b2BodyType type) {
	if(!m_Body){
		m_BodyDef.type = type;
	} else{
		m_Body->SetType(type);
	}
}

void PhisicalObject::SetLinearVelosity() {
	if (!m_Body) {
		m_BodyDef.linearVelocity.x =  m_fBaseVelocity * cos(m_fLaunchAngle);
		m_BodyDef.linearVelocity.y = -(m_fBaseVelocity * sin(m_fLaunchAngle));
	} else {
		m_Body->SetLinearVelocity(b2Vec2(m_fBaseVelocity * cos(m_fLaunchAngle),
				-(m_fBaseVelocity * sin(m_fLaunchAngle))));
	}
}

void PhisicalObject::ChangeAngularVelocity(float angVelDeg) {
	if (!m_Body) {
		m_BodyDef.angularVelocity = angVelDeg * DEG_TO_RAD;
	} else {
		m_Body->SetAngularVelocity(angVelDeg * DEG_TO_RAD);
	}
}

void PhisicalObject::ChangeBaseVelocity(float baseVelocity) {
	m_fBaseVelocity = baseVelocity;
	SetLinearVelosity();
}

void PhisicalObject::ChangeSpinAngle(float spinAngleDeg) {
	if (!m_Body) {
		m_BodyDef.angle = spinAngleDeg * DEG_TO_RAD;
	} else {
		m_Body->SetTransform(m_Body->GetPosition(), spinAngleDeg * DEG_TO_RAD);
	}
}

void PhisicalObject::SetLaunchAngle(float launchAngle) {
	m_fLaunchAngle = launchAngle * DEG_TO_RAD;
	SetLinearVelosity();
}

void PhisicalObject::Free() {
	if (m_Shape) {
		delete m_Shape;
		m_Shape = NULL;
	}
	if(m_Body){
		m_Body->DestroyFixture(this->m_fixture);
	}
	DrawableObject::Free();
}

void PhisicalObject::ApplyPhisics(b2World* world) {
	this->m_Body = world->CreateBody(&(this->m_BodyDef));
	this->m_fixture = m_Body->CreateFixture(this->m_Shape, 1.0f);
}
