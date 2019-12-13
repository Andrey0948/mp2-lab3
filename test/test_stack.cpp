#include "stack.h"
#include <gtest.h>


TEST(Stack, Stack_with_neditive_length)
{
	ASSERT_ANY_THROW(Stack<int> st(-10));
}


TEST(Stack, Stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> st(10));
}

TEST(Stack, Error_Pop_From_Empty_Stack)
{
	Stack<int> Stack(10);

	ASSERT_ANY_THROW(Stack.Pop());
}


TEST(Stack, Error_Push_From_Full_Stack)
{
	Stack<int> Stack(3);
	Stack.Push(1);
	Stack.Push(2);
	Stack.Push(3);
	ASSERT_ANY_THROW(Stack.Push(1));
}

TEST(Stack, Pop_From_Stack)
{
	Stack<int> Stack(10);
	Stack.Push(1);
	Stack.Push(2);
	Stack.Push(3);
	ASSERT_NO_THROW(Stack.Pop());
}


TEST(Stack, Check_Stack_isEmpty)
{
	Stack<int> Stack(10);

	ASSERT_TRUE(Stack.IsEmpty);
}


