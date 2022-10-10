#include "stapel.h"
#include "staper_exception.h"
stapel::stapel():index(0)
{
}

void stapel::push(int value)
{
	if (is_full())
		throw stapel_execption{ "Overflow" };

	data[index++] = value;
}

int stapel::pop()
{
	if (is_empty())
		throw stapel_execption{ "Underflow" };

	return data[--index];
}

bool stapel::is_empty()
{
	return index <= 0;
}

bool stapel::is_full()
{
	return index >= 10;
}
