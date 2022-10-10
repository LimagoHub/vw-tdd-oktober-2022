#include <iostream>
#include "calculator_client.h"
#include "calulator_impl.h"
#include "calculator_logger.h"
int main() {

	calculator_impl calc;
	calculator_logger logger{ calc };
	calculator_client client{logger};

	client.go();
}