#include <wchar.h>

typedef struct Student_ {
    int num;
    wchar_t* name;
}Student;

Student* CreateStudent(int num ,wchar_t* name) {
    Student* s = (Student*)malloc(sizeof(Student));
    s->num = num;
    s->name = name;
    return s;
}