#pragma once
#include "HotDrink.h"

struct HotDrinkFactory // Abstract Factory
{
	virtual unique_ptr<HotDrink> make() const = 0;
};