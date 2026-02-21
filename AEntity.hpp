#ifndef AENTITY_HPP
#define AENTITY_HPP

#include <iostream>
#include <string>
#include "colours.h"

class ICharacter;

class AEntity
{
protected:
	std::string type;
	
public:
	AEntity();
	AEntity(AEntity const &aentity);
	AEntity &operator=(AEntity const &aentity);
	AEntity(std::string const &type);
	virtual ~AEntity();

};

#endif