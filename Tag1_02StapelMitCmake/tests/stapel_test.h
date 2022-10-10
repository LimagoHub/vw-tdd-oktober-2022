#pragma once

#include "gtest/gtest.h"
#include "../source/stapel.h"
#include "../source/staper_exception.h"

class stapel_test:public testing::Test
{
protected:
	stapel object_under_test; // Vor jedem Test wird eine neue, frische Instanz erzeugt
};

