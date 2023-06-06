#ifndef COURSELIST_INFO_H
#define COURSELIST_INFO_H

#include "CourseInfo.h"

using namespace std;

class CourseInfoList
{
public:
    CourseInfoList();

    CourseInfoList(const CourseInfoList &other);
    CourseInfoList &operator=(const CourseInfoList &other);
    ~CourseInfoList();

    int getNumCourses() const;
    int getCapacity() const;

    CourseInfo &getCourseInfo(int index) const;

    CourseInfo *searchByCrn(const string &crn);

    void addCourse(const CourseInfo &course_information);
    void removeCourse(const string &crn);

private:
    int num_courses;
    int capacity;

    CourseInfo *infoList;
};

#endif
