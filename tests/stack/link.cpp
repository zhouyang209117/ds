#include <gtest/gtest.h>
#include <list/link.h>

typedef struct Student_ {
    int num;
    wchar_t* name;
}Student;

Student* CreateStudent(int num, wchar_t* name) {
    Student* stu = (Student*)malloc(sizeof(Student));
    stu->num = num;
    stu->name = name;
    return stu;
}

TEST(CreateStack, EqualsOne) {
    LList* stack = LL_Create(sizeof(Student));
    EXPECT_EQ(stack->length, 0);
    Student* stu = CreateStudent(1, L"张三");
    int result = stack->Push(stack, stu);
    EXPECT_EQ(result, 0);
    result = stack->Pop(stack);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(true, stack->Empty(stack));
}