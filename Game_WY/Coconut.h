#pragma once

#include "Egg.h"

// Class Coconut can take any PNG image as a path (in string format)
// and does not have to be a coconut
class Coconut : public egg::Unit
{
public:
	Coconut(const std::string& image, int x, int y, int speed);
	Coconut(std::string&& image, int x, int y, int speed);

	int GetSpeed() const;

private:
	//egg::Unit mCoconut;
	int mSpeed = 10;			// Speed of the falling debris
};