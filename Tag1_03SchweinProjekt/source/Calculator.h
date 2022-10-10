#pragma once

class calculator // Interface (Klasse die ausschliesslich aus abstrakten Methoden besteht) Contract
{
public:
	virtual double add(double a, double b) const  = 0;
};
