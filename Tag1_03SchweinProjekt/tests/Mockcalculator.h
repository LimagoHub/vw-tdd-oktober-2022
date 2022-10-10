#pragma once
#include "gmock/gmock.h"
#include "../source/Calculator.h"

class Mockcalculator : public calculator {
 public:
  MOCK_METHOD(double, add, (double a, double b), (const, override));
};
