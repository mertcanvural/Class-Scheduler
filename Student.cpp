#include "Student.h"

Student::Student() : info(), schedule()
{
}
Student::Student(const StudentInfo &student_information, const CourseInfoList &student_schedule)
{
    info = student_information;
    schedule = student_schedule;
}

Student::Student(string bnum, string id, string first_name, string last_name)
    : info(bnum, id, first_name, last_name)
{
}

Student::Student(const Student &other)
{
    info = other.info;
    schedule = other.schedule;
}

Student &Student::operator=(const Student &other)
{
    if (this != &other)
    {
        info = other.info;
        schedule = other.schedule;
    }
    return *this;
}

const StudentInfo &Student::getInfo() const
{
    return info;
}

CourseInfoList &Student::getSchedule()
{
    return schedule;
}

void Student::addToSchedule(const CourseInfo &new_course_information)
{
    schedule.addCourse(new_course_information);
}

void Student::showSchedule()
{
    int numCourses = schedule.getNumCourses();
    cout << "Student: " << info.getBnumber() << ":" << info.getFullName() << endl;

    for (int i = 0; i < numCourses; i++)
    {
        CourseInfo &course = schedule.getCourseInfo(i);
        cout << course.getCrn() << " ";
        cout << course.getDepartment() << " ";
        cout << course.getNumber() << " ";
        cout << course.getName();
        cout << endl;
    }
}

Student::~Student()
{
}