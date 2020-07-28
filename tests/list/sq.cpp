#include <gtest/gtest.h>
#include <list/sq.h>

typedef struct Student_ {
    int num;
    wchar_t* name;
}Student;

TEST(One2, EqualsOne) {
    setlocale(LC_ALL, "zh_CN.UTF-8");
    SqList* list = CreateSqList(sizeof(Student));
    EXPECT_EQ(list->length, 0);
}