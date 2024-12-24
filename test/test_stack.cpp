#include "stack.h"
#include <gtest.h>

TEST(Stack, can_push_element_into_empty_stack_size)
{
    Stack<int> stack;

    stack.push(5);

    EXPECT_EQ(stack.size(), 1);
}

TEST(Stack, can_push_element_into_empty_stack_top)
{
    Stack<int> stack;

    stack.push(5);

    EXPECT_EQ(stack.top(), 5);
}

TEST(Stack, can_push_multiple_elements_size)
{
    Stack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    EXPECT_EQ(stack.size(), 3);
}

TEST(Stack, can_push_multiple_elements_top)
{
    Stack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    EXPECT_EQ(stack.top(), 15);
}

TEST(Stack, can_pop_element_size)
{
    Stack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.pop();

    EXPECT_EQ(stack.size(), 1);
}

TEST(Stack, can_pop_element_top)
{
    Stack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.pop();

    EXPECT_EQ(stack.top(), 5);
}

TEST(Stack, throws_when_pop_on_empty_stack)
{
    Stack<int> stack;

    ASSERT_ANY_THROW(stack.pop());
}

TEST(Stack, can_access_top_element)
{
    Stack<int> stack;

    stack.push(5);
    stack.push(10);

    EXPECT_EQ(stack.top(), 10);
}

TEST(Stack, throws_when_access_top_on_empty_stack)
{
    Stack<int> stack;

    ASSERT_ANY_THROW(stack.top());
}

TEST(Stack, empty_returns_true_for_empty_stack)
{
    Stack<int> stack;

    EXPECT_TRUE(stack.empty());
}

TEST(Stack, empty_returns_false_for_nonempty_stack)
{
    Stack<int> stack;

    stack.push(5);

    EXPECT_FALSE(stack.empty());
}

TEST(Stack, size_returns_zero_for_empty_stack)
{
    Stack<int> stack;

    EXPECT_EQ(stack.size(), 0);
}

TEST(Stack, size_returns_correct_size)
{
    Stack<int> stack;

    stack.push(5);
    stack.push(10);

    EXPECT_EQ(stack.size(), 2);
}

TEST(Stack, can_push_and_pop_multiple_elements_size)
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();

    EXPECT_EQ(stack.size(), 2);
}

TEST(Stack, can_push_and_pop_multiple_elements_top)
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();

    EXPECT_EQ(stack.top(), 2);
}

TEST(Stack, behaves_correctly_under_multiple_push_and_pop_operations_size)
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.pop();
    stack.push(4);

    EXPECT_EQ(stack.size(), 2);
}

TEST(Stack, behaves_correctly_under_multiple_push_and_pop_operations_top)
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.pop();
    stack.push(4);

    EXPECT_EQ(stack.top(), 4);
}