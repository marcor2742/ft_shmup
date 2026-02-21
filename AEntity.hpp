#ifndef AENTITY_HPP
#define AENTITY_HPP

#include <iostream>
#include <string>
#include "colours.h"
using namespace std;

class ICharacter;

class AEntity
{
protected:
	string entityChar;
	string color;
	
	int start_x, start_y;
	int pos_x, pos_y;

	int speed;
	
	int health; //quantity of hits the entity can take before being destroyed
	bool isAlive;



	//update movement
	//check collision

public:
	AEntity();
	AEntity(AEntity const &aentity);
	// AEntity &operator=(AEntity const &aentity);
	AEntity(string const &type);
	virtual ~AEntity();

};

#endif