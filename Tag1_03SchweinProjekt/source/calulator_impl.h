#pragma once
#include "calculator.h"

class calculator_impl: public calculator
{
public:
	double add(double a, double b) const override
	{
		return a + b;
	}
};
