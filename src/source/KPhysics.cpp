#include "headers/KPhysics.hpp"
WorldPhysics::WorldPhysics(float gravity, float wind, unsigned int topSpeed){
	this->gravity = gravity;
	this->wind = wind;
	this->topSpeed = topSpeed;
}
WorldPhysics::~WorldPhysics(){
	for(int i = 0; i < this->PhysicsObjects.size(); i++){
		PhysicsObjects[i]->boundto = nullptr;
	}
	this->PhysicsObjects.erase(this->PhysicsObjects.begin, this->PhysicsObjects.end);
}
void WorldPhysics::setGravity(float gravity){
	this->gravity = gravity;
}
void WorldPhysics::setWind(float wind){
	this->wind = wind;
}
void WorldPhysics::setTopSpeed(unsigned int topSpeed){
	this->topSpeed = topSpeed;
}
short WorldPhysics::attachMember(PhysicsObject * member){
	member->boundto = this;
	this->PhysicsObjects.push_back(member);
}
short WorldPhysics::detachMember(PhysicsObject * member){
	member->boundto = nullptr;
	this->PhysicsObjects.erase(std::remove(this->PhysicsObjects.begin(), this->PhysicsObjects.end(), member));
}
size_t WorldPhysics::tick(){
	return 0;
}
PhysicsObject::PhysicsObject(float location[2], int weight, float friction, int bouncyness, float initialvelocity[3], float acceleration){
	this->location = location;
	this->weight = weight;
	this->friction = friction;
	this->bouncyness = bouncyness;
	this->velocity = initialvelocity;
	this->acceleration = acceleration;
}
PhysicsObject::~PhysicsObject(){
	if(boundto != nullptr) boundto->detachMember(this);
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
float * PhysicsObject::getLocation(){
	float * toreturn = new float[2];
	toreturn[0] = this->location[0];
	toreturn[1] = this->location[1];
	return toreturn;
}
void PhysicsObject::getLocation(float * output){
	output[0] = this->location[0];
	output[1] = this->location[1];
}