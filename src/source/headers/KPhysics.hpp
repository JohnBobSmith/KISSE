#pragma once
#include <unordered_map>
#include <cstdint>
#include <array>
using std::unordered_map;
using std::array;
using std::string;
class PhysicsObject;
/*
NOTE: Unless I find something horribly wrong with this implementation the header is not going to change

WorldPhysics is the class that represents a given "world"
each world has it's own gravity, windspeed, and terminal velocity.
All speeds are represented in meters per second, this is also true
of PhysicsObject.  Gravity is in this case represented as the speed at which
falling objects accelerate in meters per second per second.
*/
class WorldPhysics{
public:
	/*
	This is the constructor for worldphysics, this sets the windspeed, gravity, and the terminal velocity (topspeed) of the current
	world.  It also initializes the random number generator used for the unordered map.
	*/
	WorldPhysics(float gravity = 9.807, array<float, 3> wind = { { 0, 0, 0 } }, unsigned int topSpeed = 320000);
	/*
	This destructor will remove all PhysicsObjects from the unordered map and then return.
	*/
	~WorldPhysics();
	void setGravity(float gravity = 9.807);
	/*
	This function sets the wind speed and direction
	windX and windY produce a unit vector that represents the direction the wind blows
	*/
	void setWind(float windX = 0, float windY = 0, float windS = 0);
	void setTopSpeed(unsigned int topSpeed=320000);
	/*
	this function adds a copy of the supplied PhysicsObject to the unordered map in this WorldPhysics object.
	The returned value is the key to be used in order to access the added PhysicsObject.
	*/
	unsigned long long attachMember(PhysicsObject member);
	/*
	This function removes the PhysicsObject at the given key from the unorderd map.
	The PhysicsObject, unless a copy of it was stored elsewhere, is lost after being detached.
	*/
	void detachMember(unsigned long long key);
	/*
	The same as detachMember, except a copy of the detached PhysicsObject is returned in order to be used elsewhere.
	*/
	PhysicsObject extractMember(unsigned long long key);
	/*
	This function creates a new PhysicsObject instance using the same arguments as the PhysicsObject constructor, and then stores
	it in the unordered map all in one function.  This is useful if you do not wish to create a PhysicsObject instance if the only
	thing you are going to do with it is call attachmember afterwords.
	*/
	unsigned long long PhysicsObject_dropIn(array<float, 2> location = { { 0, 0 } }, int weight = 5, float friction = 1.0, int bouncyness = 10, array<float, 3> initialvelocity = { { 0, 0, 0 } }, float acceleration = 0.0, float airResistance = 0.0);
	/*
	All of the functions starting with PhysicsObject_ are passthrough functions that call the given PhysicsObject function at the given key.
	*/
	void PhysicsObject_setWeight(unsigned long long key, int weight = 50);
	void PhysicsObject_setFriction(unsigned long long key, float friction = 1.0);
	void PhysicsObject_setBounce(unsigned long long key, int bouncyness = 10);
	void PhysicsObject_setAccelerate(unsigned long long key, float acceleration = 0.0);
	void PhysicsObject_setLocation(unsigned long long key, float x = 0.0, float y = 0.0);
	void PhysicsObject_setAirResistance(unsigned long long key, float airResistance = 0.0);
	array<float, 2> PhysicsObject_getLocation(unsigned long long key);
	/*
	This function runs all of the Physics calculations for the world (falling, speedup, slowdown, friction, attraction, etc...) and will perform all calculations
	that would have been done since the last time tick was called.  All calculations use the current time as a variable, so calling it over large gaps of time will
	produce the same results as calling it rapidly.  Keep in mind that doing that would make movement appear choppy however.

	The returned value of the function is an error code
	*/
	size_t tick();
private:
    friend class PhysicsObject;
	float gravity;
	array<float, 3> wind;
	unsigned int topSpeed;
	unordered_map<unsigned long long, PhysicsObject>PhysicsObjects;
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
	array<float, 2> getLocation();
private:
    friend class WorldPhysics;
	array<float, 2> location;
	float resistance;
	int weight;
	float friction;
	int bouncyness;
	array<float, 3> velocity;
	float acceleration;
};
