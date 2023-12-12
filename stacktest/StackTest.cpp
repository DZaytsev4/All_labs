#include "MyStack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_size) {
    ASSERT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, can_create_stack_with_negative_size) {
    ASSERT_ANY_THROW(TStack<int> s(-5));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
    TStack<int> s(5);
    s.Push(1);
    TStack<int> s1(s);
    ASSERT_EQ(s.Pop(), s1.Pop());
}

TEST(TStack, push_pop_test) {
    TStack<int> stack(5);

    for (int i = 1; i <= 5; i++) {
        stack.Push(i);
    }

    for (int i = 5; i >= 1; i--) {
        ASSERT_EQ(stack.Pop(), i);
    }
}

TEST(TStack, top_view_test) {
    TStack<int> stack(5);

    for (int i = 1; i <= 5; i++) {
        stack.Push(i);
    }

    ASSERT_EQ(stack.TopView(), 5);
}

TEST(TStack, operator_equal)
{
    TStack<int> s(5);
    s.Push(1);
    TStack<int> s1 = s;
    ASSERT_EQ(s.Pop(), s1.Pop());
}

TEST(TSack, cant_push_when_stack_overflow)
{
    TStack<int> s(1);
    s.Push(1);
    ASSERT_ANY_THROW(s.Push(1));
}

TEST(TStackTest, cant_pop_when_stack_empty) {
    TStack<int> s(3);
    ASSERT_ANY_THROW(s.Pop());

}
