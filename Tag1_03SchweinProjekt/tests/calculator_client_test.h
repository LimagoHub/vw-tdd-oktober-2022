#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Mockcalculator.h"
#include "../source/calculator.h"
#include "../source/calculator_client.h"

class calculator_client_test:public testing::Test
{
protected:
	Mockcalculator calculatorMock;
	calculator_client object_under_test{calculatorMock};




};
