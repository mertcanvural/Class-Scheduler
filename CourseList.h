#ifndef COURSE_LIST_H
#define COURSE_LIST_H

#include "Course.h"

using namespace std;

class CourseList
{
public:
    CourseList();

    CourseList(const CourseList &other);
    CourseList &operator=(const CourseList &other);
    ~CourseList();

    int get_num_students() const;
    void addCourse(const Course &new_course);

    Course* searchByCrn(const string& crn) const;
    
    Course &getCourse(int index) const;

    void addCourse(const CourseInfo &course_information);
    void removeCourse(const string &crn);
    void cancelCourse(const string &crn);

private:
    int num_courses;
    int capacity;
    Course *courses;
};

#endif