#include "CourseInfoList.h"
#include "CourseInfo.h"

CourseInfoList::CourseInfoList()
{
    num_courses = 0;
    capacity = 2;
    infoList = new CourseInfo[capacity];
}

CourseInfoList::CourseInfoList(const CourseInfoList &other)
{
    num_courses = other.num_courses;
    capacity = other.capacity;
    infoList = new CourseInfo[capacity];
    for (int i = 0; i < num_courses; ++i)
    {
        infoList[i] = other.infoList[i];
    }
}

CourseInfoList &CourseInfoList::operator=(const CourseInfoList &other)
{
    if (this != &other)
    {
        num_courses = other.num_courses;
        capacity = other.capacity;
        delete[] infoList;
        infoList = new CourseInfo[capacity];
        for (int i = 0; i < num_courses; ++i)
        {
            infoList[i] = other.infoList[i];
        }
    }
    return *this;
}

int CourseInfoList::getNumCourses() const
{
    return num_courses;
}

int CourseInfoList::getCapacity() const
{
    return capacity;
}

CourseInfo &CourseInfoList::getCourseInfo(int index) const
{
    return infoList[index];
}

CourseInfo *CourseInfoList::searchByCrn(const string &crn)
{
    for (int i = 0; i < num_courses; ++i)
    {
        if (infoList[i].getCrn() == crn)
        {
            return &infoList[i];
        }
    }
    // If bnumber does not exist in the dynamically allocated array return nullptr.
    return nullptr;
}

void CourseInfoList::addCourse(const CourseInfo &course_information)
{
    if (num_courses == capacity)
    {
        capacity *= 2;
        CourseInfo *new_courses = new CourseInfo[capacity];
        for (int i = 0; i < num_courses; ++i)
        {
            new_courses[i] = infoList[i];
        }
        new_courses[num_courses] = course_information;
        num_courses++;
        delete[] infoList;
        infoList = new_courses;
    }
    else
    {
        infoList[num_courses] = course_information;
        num_courses++;
    }
}

void CourseInfoList::removeCourse(const string &crn)
{
    for (int i = 0; i < num_courses; i++)
    {
        if (infoList[i].getCrn() == crn)
        {
            for (int j = i; j < num_courses - 1; j++)
            {
                infoList[j] = infoList[j + 1];
            }
            num_courses--;
        }
    }
}

CourseInfoList::~CourseInfoList()
{
    delete[] infoList;
}