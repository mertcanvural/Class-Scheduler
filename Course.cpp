#include "Course.h"

Course::Course() : info(), roster() {}

Course::Course(const CourseInfo &course_information, StudentInfoList &student_info_list)
{
    info = course_information;
    roster = student_info_list;
}

CourseInfo &Course::getInfo()
{
    return info;
}

Course::Course(const Course &other)
{
    info = other.info;
    roster = other.roster;
}

Course &Course::operator=(const Course &other)
{
    if (this != &other)
    {
        info = other.info;
        roster = other.roster;
    }
    return *this;
}

StudentInfoList &Course::getRoster()
{
    return roster;
}

void Course::showRoster()
{
    int numStudents = roster.get_num_students();
    cout << "CRN: " << info.getCrn() << endl;
    cout << "Student: " << numStudents << endl;

    for (int i = 0; i < numStudents; i++)
    {
        StudentInfo &student = roster.getStudent(i);
        cout << student.getBnumber() << " ";
        cout << student.getFullName() << " ";
        cout << endl;
    }
}

Course::~Course(){
    
}