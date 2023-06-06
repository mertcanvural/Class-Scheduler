#ifndef COURSE_H
#define COURSE_H
#include <iostream>

#include "CourseInfo.h"
#include "StudentInfoList.h"

using namespace std;

class Course
{
public:
    // constructors
    Course();
    Course(const CourseInfo &info);
    Course(const CourseInfo &course_information, StudentInfoList &student_info_list);

    // copy
    Course(const Course &other);
    Course &operator=(const Course &other);
    // destructor
    ~Course();

    // 
    CourseInfo &getInfo();
    StudentInfoList &getRoster();
    void showRoster();

private:
    CourseInfo info;
    StudentInfoList roster;
};


#endif