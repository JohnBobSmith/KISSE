#include "headers/KPhysics.hpp"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <chrono>
#include <random>
std::mt19937_64 seedGen;
WorldPhysics::WorldPhysics(float gravity, array<float, 3> wind, unsigned int topSpeed){
	this->gravity = gravity;
	this->wind = wind;
	this->topSpeed = topSpeed;
	std::mt19937_64 toSeedGen(clock());
	seedGen = toSeedGen;
}
WorldPhysics::~WorldPhysics(){
	this->PhysicsObjects.erase(this->PhysicsObjects.begin(), this->PhysicsObjects.end());
}
void WorldPhysics::setGravity(float gravity){
	this->gravity = gravity;
}
void WorldPhysics::setWind(float windX, float windY, float windS){
	this->wind[0] = windX;
	this->wind[1] = windY;
	this->wind[2] = windS;
}
void WorldPhysics::setTopSpeed(unsigned int topSpeed){
	this->topSpeed = topSpeed;
}
unsigned long long WorldPhysics::attachMember(PhysicsObject member){
	unsigned long long seed = seedGen();
	PhysicsObjects[seed] = member;
	return seed;
}
void WorldPhysics::detachMember(unsigned long long id){
	this->PhysicsObjects.erase(id);
}
PhysicsObject WorldPhysics::extractMember(unsigned long long id){
	PhysicsObject toreturn = PhysicsObjects[id];
	PhysicsObjects.erase(id);
	return toreturn;
}
unsigned long long WorldPhysics::PhysicsObject_dropIn(array<float, 2> location, int weight, float friction, int bouncyness, array<float, 3> initialvelocity, float acceleration, float airResistance){
	PhysicsObject toAdd(location, weight, friction, bouncyness, initialvelocity, acceleration, airResistance);
	unsigned long long seed = seedGen();
	PhysicsObjects[seed] = toAdd;
	return seed;
}
void WorldPhysics::PhysicsObject_setWeight(unsigned long long id, int weight){
	PhysicsObjects[id].setWeight(weight);
}
void WorldPhysics::PhysicsObject_setFriction(unsigned long long id, float friction){
	PhysicsObjects[id].setFriction(friction);
}
void WorldPhysics::PhysicsObject_setBounce(unsigned long long id, int bouncyness){
	PhysicsObjects[id].setBounce(bouncyness);
}
void WorldPhysics::PhysicsObject_setAccelerate(unsigned long long id, float acceleration){
	PhysicsObjects[id].setAccelerate(acceleration);
}
void WorldPhysics::PhysicsObject_setLocation(unsigned long long id, float x, float y){
	PhysicsObjects[id].setLocation(x, y);
}
void WorldPhysics::PhysicsObject_setAirResistance(unsigned long long id, float airResistance){
	PhysicsObjects[id].setAirResistance(airResistance);
}
array<float, 2> WorldPhysics::PhysicsObject_getLocation(unsigned long long id){
	return PhysicsObjects[id].getLocation();
}
size_t WorldPhysics::tick(){
	return 0;
}
PhysicsObject::PhysicsObject(array<float, 2> location, int weight, float friction, int bouncyness, array<float, 3> initialvelocity, float acceleration, float airResistance){
	this->location = location;
	this->weight = weight;
	this->friction = friction;
	this->bouncyness = bouncyness;
	this->velocity = initialvelocity;
	this->acceleration = acceleration;
	this->resistance = airResistance;
}
PhysicsObject::~PhysicsObject(){
	return;
}
void PhysicsObject::setAirResistance(float airResistance){
	this->resistance = airResistance;
}
void PhysicsObject::setWeight(int weight){
	this->weight = weight;
}
void PhysicsObject::setFriction(float friction){
	this->friction = friction;
}
void PhysicsObject::setBounce(int bouncyness){
	this->bouncyness = bouncyness;
}
void PhysicsObject::setAccelerate(float acceleration){
	this->acceleration = acceleration;
}
void PhysicsObject::setLocation(float x, float y){
	this->location[0] = x;
	this->location[1] = y;
}
array<float, 2> PhysicsObject::getLocation(){
	return this->location;
}

