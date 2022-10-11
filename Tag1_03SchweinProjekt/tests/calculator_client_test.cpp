#include "calculator_client_test.h"

using namespace testing;

TEST_F(calculator_client_test, xxx)
{
	/// Arrange (Assertion includiert)
	// Recordmode
	
	//ON_CALL(calculatorMock, add(_, _)).WillByDefault(Return(123.4));
	//EXPECT_CALL(calculatorMock, add(Lt(4.0), 4.0)).Times(0);
	//EXPECT_CALL(calculatorMock, add(4.0, 4.0)).Times(1).WillOnce(Return(42.0));

	// Replaymode

	// Act
	object_under_test.go();

	
}