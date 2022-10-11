//
// Created by JoachimWagner on 11.10.2022.
//

#pragma once
#include "../persistence/person.h"

class blacklist_service {
public:
    virtual bool is_blacklisted(const person& person) const = 0;
};
