#pragma once
#pragma once
#include "person.h"
#include <optional>
#include <vector>

class personen_repository
{
public:
	virtual void save_or_update(const person& person) const = 0;
	virtual std::optional<person> find_by_id(std::string id) const = 0;
	virtual std::vector<person> find_all() const = 0;
	virtual bool delete_by_id(std::string id) const = 0;
};
