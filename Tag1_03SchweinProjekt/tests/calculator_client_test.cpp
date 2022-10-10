#include "calculator_client_test.h"

using namespace testing;

TEST_F(calculator_client_test, xxx)
{
	/// Arrange (Assertion includiert)
	// Recordmode
	EXPECT_CALL(calculatorMock, add(3.0, 4.0)).Times(1).WillOnce(Return(47.11));
	
	

	// Replaymode

	// Act
	object_under_test.go();

	int result = 1;
	EXPECT_EQ(result, 2);
	EXPECT_THAT(result, Not(Eq(1)));
	// Verify
}