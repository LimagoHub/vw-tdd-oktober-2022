#pragma once
class stapel
{
	int data[10];
	int index;
public:
	stapel();

	void push(int value);
	int pop();

	bool is_empty();
	bool is_full();
	
};

