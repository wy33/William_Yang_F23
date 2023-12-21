#include<string>

#include "Coconut.h"

Coconut::Coconut(const std::string& image, int x, int y, int speed) :
	egg::Unit{ image, x, y }, mSpeed{ speed }
{
}

Coconut::Coconut(std::string&& image, int x, int y, int speed) :
	egg::Unit{ std::move(image), x, y }, mSpeed{ speed }
{
}

int Coconut::GetSpeed() const
{
	return mSpeed;
}