#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

#include "StudentInfo.h"
#include "CourseInfoList.h"

using namespace std;

class Student
{
public:
    Student();
    Student(string bnum, string id, string first_name, string last_name);

    Student(const Student &other);
    Student &operator=(const Student &other1);
    ~Student();

    void showSchedule();
    Student(const StudentInfo &student_information, const CourseInfoList &student_schedule);
    const StudentInfo &getInfo() const;
    CourseInfoList &getSchedule();
    void addToSchedule(const CourseInfo &new_course_information);

private:
    StudentInfo info;
    CourseInfoList schedule;
};

#endif