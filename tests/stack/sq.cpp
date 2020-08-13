#include <gtest/gtest.h>
#include <stack/sq.h>

typedef struct Student_ {
    int num;
}Student;

Student* CreateStudent(int num) {
    Student* stu = (Student*)malloc(sizeof(Student));
    stu->num = num;
    return stu;
}

TEST(CreateSqStack, EqualsOne) {
    SqStack* stack = CreateSqStack(sizeof(Student));
    EXPECT_EQ(stack->length, 0);
    EXPECT_EQ(stack->Empty(stack), true);
    for (int i = 0; i < 20; i++) {
        Student* stu = CreateStudent(i);
        int result = stack->Push(stack, stu);
        EXPECT_EQ(result, 0);
    }
    Student* stu = (Student*)stack->Pop(stack);
    EXPECT_EQ(stu->num, 19);
    EXPECT_EQ(stack->length, 19);
    EXPECT_EQ(stack->Empty(stack), false);
}