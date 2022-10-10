#include "stapel_test.h"

TEST_F(stapel_test, is_empty__empty_stack__returns_true)
{
	// Arrange

	// Act

	bool result = object_under_test.is_empty();

	// Assertion
	// ASSERT_TRUE(result); // Brutal
	EXPECT_TRUE(result);
	
}

TEST_F(stapel_test, is_empty__not_empty_stack__returns_false)
{
	// Arrange
	object_under_test.push(1);
	
	// Act

	

	// Assertion
	// ASSERT_TRUE(result); // Brutal
	EXPECT_FALSE(object_under_test.is_empty());

}

TEST_F(stapel_test, push__fill_up_to_limit__no_exception_is_thrown)
{
	// Arrange
	for (int i = 0; i < 9; i++)
		object_under_test.push(1);

	// Act
	EXPECT_NO_THROW(object_under_test.push(1));
	

}

TEST_F(stapel_test, push_overflow_throws_stapelexception)
{
	for (int i = 0; i < 10; i++)
		object_under_test.push(1);

	EXPECT_THROW(object_under_test.push(1), stapel_execption);
}

TEST_F(stapel_test, push_overflow_throws_stapelexception_variante2)
{
	try
	{
		// Arrange
		for (int i = 0; i < 10; i++)
			object_under_test.push(i);
		// Act
		object_under_test.push(1);
		FAIL() << "expected exception is not thrown";
	}
	catch (const stapel_execption& ex)
	{
		EXPECT_STREQ("Overflow", ex.what());
	}
}

