#pragma once
#include <iostream>
#include "calculator.h"
class calculator_logger : public calculator
{
	calculator& calculator_;


public:
	calculator_logger(calculator& calculator)
		: calculator_(calculator)
	{
	}


	double add(double a, double b) const override
	{
		std::cout << "Add wurde gerufen" << std::endl;
		return calculator_.add(a,b);
	}
};
