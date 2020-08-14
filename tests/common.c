typedef struct Student_ {
    int num;
}Student;

Student* CreateStudent(int num) {
    Student* stu = (Student*)malloc(sizeof(Student));
    stu->num = num;
    return stu;
}