#pragma once
#include <vector>
#include <cstdint>
using std::vector;
class PhysicsObject;
/*
    This is really just a quick fix until I have more time to do this a better way,
    the C++ standard (all versions) does not allow for the use of initializer lists in constructors
    so for now I'm doing more or less the equivelent of that by creating strings of equal length (in bytes)
    to an array of three floats.  This makes the constructor produce
    an array stored on the .data segment of the executable, rather than allocating memory on the heap.  Which is preferable
    if only because it makes optimization easier.
*/
const float * empty3d = *(float**)&("\0\0\0\0\0\0\0\0\0\0\0\0");
class WorldPhysics{
public:

	WorldPhysics(float gravity=9.807, float * wind= (float*)empty3d, unsigned int topSpeed = 320000);
	~WorldPhysics();
	void setGravity(float gravity=9.807);
	void setWind(float windX = 0, float windY = 0, float windS = 0);
	void setTopSpeed(unsigned int topSpeed=320000);
	short attachMember(PhysicsObject * member);
	short detachMember(PhysicsObject * member);
	size_t tick();
private:
    friend class PhysicsObject;
	float gravity;
	float * wind;
	unsigned int topSpeed;
	vector<PhysicsObject*> PhysicsObjects;
};
class PhysicsObject{
public:
	PhysicsObject(float * location = (float*)empty3d,int weight = 5, float friction = 1.0, int bouncyness = 10, float * initialvelocity = (float*)empty3d, float acceleration = 0.0, float airResistance = 0.0);
	~PhysicsObject();
	void setWeight(int weight = 50);
	void setFriction(float friction = 1.0);
	void setBounce(int bouncyness = 10);
	void setAccelerate(float acceleration = 0.0);
	void setLocation(float x = 0.0, float y = 0.0);
	void setAirResistance(float airResistance = 0.0);
	float * getLocation();
	void getLocation(float * output);
private:
    friend class WorldPhysics;
	WorldPhysics * boundto = nullptr;
	float * location;
	float resistance;
	int weight;
	float friction;
	int bouncyness;
	float * velocity;
	float acceleration;
};
