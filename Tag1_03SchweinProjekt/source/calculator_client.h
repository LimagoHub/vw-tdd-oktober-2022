#pragma once
#include <iostream>
#include "calculator.h"

class calculator_client
{
	calculator& calculator_;


public:
	calculator_client(calculator& calculator)
		: calculator_(calculator)
	{
	}

	void go()
	{
		
		std::cout << calculator_.add(4, 4) << std::endl;
		std::cout << calculator_.add(3, 4) << std::endl;
	}
};
