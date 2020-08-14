#include <gtest/gtest.h>
#include <queue/sq.h>
#include "../common.c"

TEST(CreateSqQueue, EqualsOne) {
    SqQueue* queue = CreateSqQueue(sizeof(Student));
    EXPECT_EQ(queue->Empty(queue), true);
    for (int i = 0; i < 15; i++) {
        Student* stu = CreateStudent(i);
        int result = queue->Enter(queue, stu);
        EXPECT_EQ(result, 0);
        EXPECT_EQ(queue->Empty(queue), false);
    }
    int result = queue->Enter(queue, CreateStudent(16));
    EXPECT_EQ(result, 1);
    for (int i = 0; i < 15; i++) {
        Student* stu = (Student*)(queue->Delete(queue));
        EXPECT_EQ(stu->num, i);
    }
    EXPECT_EQ(queue->Empty(queue), true);
    Student* stu1 = (Student*)queue->Delete(queue);
    EXPECT_EQ(stu1 == NULL, true);
}
