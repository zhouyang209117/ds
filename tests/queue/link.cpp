#include <gtest/gtest.h>
#include <queue/link.h>
#include "../common.c"

TEST(CreateLinkQueue, EqualsOne) {
    LQueue* queue = CreateLQueue(sizeof(Student));
    EXPECT_EQ(queue->Empty(queue), true);
    for (int i = 0; i < 20; i++) {
        Student* stu = CreateStudent(i);
        int result = queue->Enter(queue, stu);
        EXPECT_EQ(result, 0);
    }
    EXPECT_EQ(queue->Empty(queue), false);
    for (int i = 0; i < 20; i++) {
        Student* stu = (Student*)queue->Delete(queue);
        EXPECT_EQ(stu->num, i);
    }
    EXPECT_EQ(queue->Empty(queue), true);
}
