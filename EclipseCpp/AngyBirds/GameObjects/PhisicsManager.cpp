/*
 * PhisicsManager.cpp
 *
 *  Created on: Nov 12, 2014
 *      Author: Rosen
 */

#include "PhisicsManager.h"
#include "PhisicalObject.h"
#include <Box2D/Dynamics/b2World.h>
#include "../Interfaces/Constants.h"


PhisicsManager::PhisicsManager() {
	m_PhisicsWorld = new b2World(b2Vec2(0, GRAVITY_CONST));
}

void PhisicsManager::RegisterAnObject(PhisicalObject* obj) {
	m_AllObjects.insert(obj);
	obj->ApplyPhisics(m_PhisicsWorld);
}

void PhisicsManager::SimulateStep() {
	m_PhisicsWorld->Step(TIME_STEP, VEL_ITERATIONS, POS_ITERATIONS);
}

PhisicsManager::~PhisicsManager() {
	for (set<PhisicalObject*>::iterator it = m_AllObjects.begin();
			it != m_AllObjects.end(); ++it) {
		(*it)->Free();
	}
	delete m_PhisicsWorld;
}

