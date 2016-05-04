/*
 * PhisicsManager.h
 *
 *  Created on: Nov 12, 2014
 *      Author: Rosen
 */

#ifndef PHISICSMANAGER_H_
#define PHISICSMANAGER_H_
#include <set>
using std::set;

class PhisicalObject;
class b2Fixture;
class b2World;
class b2Body;

class PhisicsManager {
public:
	PhisicsManager();
	void RegisterAnObject(PhisicalObject*);
	void SimulateStep();
	virtual ~PhisicsManager();
private:
	b2World* m_PhisicsWorld;
	set<PhisicalObject*> m_AllObjects;
};

#endif /* PHISICSMANAGER_H_ */
