#pragma once
#include <cmath>
class WorldPhysics{
public:
	WorldPhysics(float gravity=9.807, float wind=0.0, unsigned int topSpeed = 320000);
	~WorldPhysics();
	void setGravity(float gravity=9.807);
	void setWind(float wind=0.0);
	void setTopSpeed(unsigned int topSpeed=320000);
	byte attachMember(PhysicsObject * member);
	byte detachMember(PhysicsObject * member);
	size_t tick();
private:
	float gravity;
	float wind;
	unsigned int topspeed;
	PhysicsObject members[];
};
class PhysicsObjects{
public:
	PhysicsObject(float location[2] = {0.0,0.0},int weight = 5, float friction = 1.0, int bouncyness = 10, float initialvelocity[3] = {0.0, 0.0, 0.0}, float acceleration = 0.0);
	~PhysicsObject();
	void setWeight(int weight = 50);
	void setFriction(float friction = 1.0);
	void setBounce(int bouncyness = 10);
	void setAccelerate(float acceleration = 0.0);
	void setLocation(float x = 0.0, float y = 0.0);
	float * getLocation();
	void getLocation(float * output);
private:
	float * location;
	int weight;
	float friction;
	int bouncyness;
	float * velocity;
	float acceleration;
};