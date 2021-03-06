#include <gtest/gtest.h>
#include <list/link.h>
#include <tree/bi.h>
#include <stack/link.h>
#include "../common.c"

TEST(CreateStackStu, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    LStack* stack = CreateLStack(sizeof(Student));
    Student* stu = CreateStudent(1);
    int result = stack->Push(stack, stu);
    EXPECT_EQ(result, 0);
    Student* top = (Student*)stack->Top(stack);
    EXPECT_EQ(top->num, 1);
    Student* stu1 = (Student*)stack->Pop(stack);
    EXPECT_EQ(stu1 != NULL, true);
    EXPECT_EQ(1, stack->Empty(stack));
    EXPECT_EQ(1, stu->num);
}

TEST(CreateStackIntPointer, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    LStack* stack = CreateLStack(sizeof(int*));
    int a = 1;
    int result = stack->Push(stack, &a);
    EXPECT_EQ(result, 0);
    int* b = (int*)stack->Pop(stack);
    EXPECT_EQ(a, *b);
}

void printStu(void* stu) {
    Student* tmp = (Student*)stu;
    if (stu == NULL) {
        printf("stu is null\n");
        return;
    }
    printf("num=%d\n", tmp->num);
}

TEST(CreateStackBiNode, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    LStack* stack = CreateLStack(sizeof(BiNode**));
    BiNode* node = (BiNode*)malloc(sizeof(BiNode));
    Student* stu = CreateStudent(10);
    node->data = stu;
    node->l = NULL;
    node->r = NULL;
    int result = stack->Push(stack, &node);
    EXPECT_EQ(result, 0);
    BiNode** b = (BiNode**)stack->Pop(stack);
    Student* stu1 = (Student*)((*b)->data);
    EXPECT_EQ(10, stu1->num);
}