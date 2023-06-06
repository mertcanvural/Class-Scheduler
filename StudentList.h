#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include "Student.h"

using namespace std;

class StudentList
{
public:
    StudentList();


    StudentList(const StudentList &other);
    StudentList &operator=(const StudentList &other);
    ~StudentList();

    Student *searchStudent(const string &bnumber) const;
    void cancelCourse(const string &crn) const;

    int get_num_students() const;
    void addStudent(const Student &new_student);

private:
    int num_students;
    int capacity;

    Student *students;
};

#endif