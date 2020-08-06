#include <gtest/gtest.h>
#include <list/link.h>
#include <tree/bi.h>

typedef struct Student_ {
    int num;
}Student;

Student* CreateStudent(int num, wchar_t* name) {
    Student* stu = (Student*)malloc(sizeof(Student));
    stu->num = num;
    return stu;
}

TEST(CreateStackStu, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    LList* stack = CreateLList(sizeof(Student), NULL);
    EXPECT_EQ(stack->length, 0);
    Student* stu = CreateStudent(1, L"张三");
    int result = stack->Push(stack, stu);
    EXPECT_EQ(result, 0);
    Student* stu1 = (Student*)stack->Pop(stack);
    EXPECT_EQ(stu1 != NULL, true);
    EXPECT_EQ(true, stack->Empty(stack));
}

TEST(CreateStackIntPointer, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    LList* stack = CreateLList(sizeof(int*), NULL);
    EXPECT_EQ(stack->length, 0);
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
    LList* stack = CreateLList(sizeof(BiNode**), NULL);
    EXPECT_EQ(stack->length, 0);
    BiNode* node = (BiNode*)malloc(sizeof(BiNode));
    Student* stu = CreateStudent(10, L"张三");
    node->data = stu;
    node->l = NULL;
    node->r = NULL;
    int result = stack->Push(stack, &node);
    EXPECT_EQ(result, 0);
    BiNode** b = (BiNode**)stack->Pop(stack);
    Student* stu1 = (Student*)((*b)->data);
    EXPECT_EQ(10, stu1->num);
}