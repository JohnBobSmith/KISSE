#pragma once
#include <vector>
#include <cstdint>
#include <array>
using std::vector;
using std::array;
class PhysicsObject;

class WorldPhysics{
public:

	WorldPhysics(float gravity = 9.807, array<float, 3> wind = { { 0, 0, 0 } }, unsigned int topSpeed = 320000);
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
	array<float, 3> wind;
	unsigned int topSpeed;
	vector<PhysicsObject*> PhysicsObjects;
};
class PhysicsObject{
public:
	PhysicsObject(array<float, 2> location = { {0, 0} }, int weight = 5, float friction = 1.0, int bouncyness = 10, array<float, 3> initialvelocity = { { 0, 0, 0 } }, float acceleration = 0.0, float airResistance = 0.0);
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
	array<float, 2> location;
	float resistance;
	int weight;
	float friction;
	int bouncyness;
	array<float, 3> velocity;
	float acceleration;
};
