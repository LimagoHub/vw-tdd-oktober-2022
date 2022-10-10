#pragma once
#include <stdexcept>

class stapel_execption: public std::out_of_range
{
public:
	stapel_execption(const std::string& _Message)
		: out_of_range(_Message)
	{
	}
};
