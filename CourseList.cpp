#include "CourseList.h"

CourseList::CourseList()
{
    num_courses = 0;
    capacity = 2;
    courses = new Course[capacity];
}

CourseList::CourseList(const CourseList &other)
{
    num_courses = other.num_courses;
    capacity = other.capacity;
    courses = new Course[capacity];
    for (int i = 0; i < num_courses; ++i)
    {
        courses[i] = other.courses[i];
    }
}

CourseList &CourseList::operator=(const CourseList &other)
{
    if (this != &other)
    {
        num_courses = other.num_courses;
        capacity = other.capacity;
        delete[] courses;
        courses = new Course[capacity];
        for (int i = 0; i < num_courses; ++i)
        {
            courses[i] = other.courses[i];
        }
    }
    return *this;
}

int CourseList::get_num_students() const
{
    return this->num_courses;
}
void CourseList::addCourse(const Course &new_course)
{
    {
        // double the size if capacity is at full...
        if (num_courses == capacity)
        {
            capacity = 2 * capacity;
            Course *new_courses = new Course[capacity];
            for (int i = 0; i < num_courses; ++i)
            {
                new_courses[i] = courses[i];
            }
            delete[] courses;
            courses = new_courses;
        }
        courses[num_courses] = new_course;
        num_courses++;
    }
}

Course &CourseList::getCourse(int index) const
{
    return courses[index];
}

Course *CourseList::searchByCrn(const string &crn) const
{
    for (int i = 0; i < num_courses; ++i)
    {
        if (courses[i].getInfo().getCrn() == crn)
        {
            return &courses[i];
        }
    }
    return nullptr;
}

// remove a course from the course list
void CourseList::removeCourse(const string &crn)
{
    for (int i = 0; i < num_courses; i++)
    {
        if (courses[i].getInfo().getCrn() == crn)
        {
            for (int j = i; j < num_courses - 1; j++)
            {
                courses[j] = courses[j + 1];
            }
            num_courses--;
        }
    }
}

void CourseList::cancelCourse(const string &crn)
{
    {
        for (int i = 0; i < num_courses; i++)
        {
            if (courses[i].getInfo().getCrn() == crn)
            {
                for (int j = i; j < num_courses - 1; j++)
                {
                    courses[j] = courses[j + 1];
                }
                num_courses--;
                return;
            }
        }
    }
}

CourseList::~CourseList()
{
    // for (int i = 0; i < num_courses; ++i)
    // {
    //     courses[i].getRoster().~StudentInfoList();
    // }
    delete[] courses;
}
