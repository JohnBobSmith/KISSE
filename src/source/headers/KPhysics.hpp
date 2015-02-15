#pragma once
#include <cmath>
#include <algorithm>
#include <vector>
using std::vector;
class WorldPhysics{
public:
	WorldPhysics(float gravity=9.807, float wind[3]={0.0, 0.0, 0.0}, unsigned int topSpeed = 320000);
	~WorldPhysics();
	void setGravity(float gravity=9.807);
	void setWind(float wind=0.0);
	void setTopSpeed(unsigned int topSpeed=320000);
	short attachMember(PhysicsObject * member);
	short detachMember(PhysicsObject * member);
	size_t tick();
private:
	float gravity;
	float * wind;
	unsigned int topSpeed;
	vector<PhysicsObject*> PhysicsObjects;
};
class PhysicsObject{
public:
	PhysicsObject(float location[2] = {0.0,0.0},int weight = 5, float friction = 1.0, int bouncyness = 10, float initialvelocity[3] = {0.0, 0.0, 0.0}, float acceleration = 0.0, float airResistance = 0.0);
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
	WorldPhysics * boundto = nullptr;
	float * location;
	float resistance;
	int weight;
	float friction;
	int bouncyness;
	float * velocity;
	float acceleration;
};