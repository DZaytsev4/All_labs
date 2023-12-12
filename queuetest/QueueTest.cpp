#include "MyQueue.h"
#include <gtest.h>


TEST(TQueue, cant_create__with_negative_size)
{
    ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, is_full)
{
    TQueue<int> q(3);
    q.Push(1);
    q.Push(1);
    q.Push(1);
    ASSERT_EQ(q.IsFull(), true);
}

TEST(TQueue, is_empty)
{
    TQueue<int> q(3);

    ASSERT_EQ(q.IsEmpty(), true);
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
    TQueue<int> s(5);
    s.Push(3);
    TQueue<int> s1(s);
    ASSERT_EQ(s.Get(), s1.Get());
}

TEST(TQueue, cant_add_el_when_queue_is_full)
{
    TQueue<int> q(3);
    q.Push(1);
    q.Push(1);
    q.Push(1);
    ASSERT_ANY_THROW(q.Push(1));
}

TEST(TQueue, cant_get_el_when_queue_is_empty)
{
    TQueue<int> q(3);
    ASSERT_ANY_THROW(q.Get());
}
