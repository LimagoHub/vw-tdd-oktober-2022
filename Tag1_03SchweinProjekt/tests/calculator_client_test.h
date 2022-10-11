#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Mockcalculator.h"
#include "../source/calculator.h"
#include "../source/calculator_client.h"

using ::testing::StrictMock;
using ::testing::NiceMock;

class calculator_client_test:public testing::Test
{
protected:
	NiceMock<Mockcalculator> calculatorMock;
	calculator_client object_under_test{calculatorMock};




};
