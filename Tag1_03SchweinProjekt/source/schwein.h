#pragma once
#pragma once
#include <ostream>
#include <string>
#include <stdexcept>

class schwein
{
	std::string name;
	int gewicht;

	void set_gewicht(const int gewicht)
	{
		this->gewicht = gewicht;
	}

public:
	

	void set_name(const std::string& name)
	{
		if (name == "Elsa")
			throw std::invalid_argument("Dieser Name verstoesst gegen die Schweinewuerde");
		this->name = name;
	}

	

	void fuettern()
	{
		set_gewicht(get_gewicht() + 1);
		
	}
	
	schwein(const std::string& name = "nobody")
		: name(name)
	{
	}

	// Generiert

	

	[[nodiscard]] std::string get_name() const
	{
		return name;
	}
	
	[[nodiscard]] int get_gewicht() const
	{
		return gewicht;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const schwein& obj)
	{
		return os
			<< "name: " << obj.name
			<< " gewicht: " << obj.gewicht;
	}


	friend bool operator==(const schwein& lhs, const schwein& rhs)
	{
		return lhs.name == rhs.name
			&& lhs.gewicht == rhs.gewicht;
	}

	friend bool operator!=(const schwein& lhs, const schwein& rhs)
	{
		return !(lhs == rhs);
	}

	
};