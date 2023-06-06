#include "StudentList.h"


StudentList::StudentList()
{
    num_students = 0;
    capacity = 2;
    students = new Student[capacity];
}
StudentList::StudentList(const StudentList &other)
{
    num_students = other.num_students;
    capacity = other.capacity;
    students = new Student[capacity];
    for (int i = 0; i < num_students; ++i)
    {
        students[i] = other.students[i];
    }
}


StudentList &StudentList::operator=(const StudentList &other)
{
    if (this != &other)
    {
        num_students = other.num_students;
        capacity = other.capacity;
        delete[] students;
        students = new Student[capacity];
        for (int i = 0; i < num_students; ++i)
        {
            students[i] = other.students[i];
        }
    }
    return *this;
}


int StudentList::get_num_students() const
{
    return this->num_students;
}

void StudentList::addStudent(const Student &new_student)
{

    // double the size if capacity is at full...
    if (num_students == capacity)
    {
        capacity = 2 * capacity;
        Student *new_students = new Student[capacity];
        for (int i = 0; i < num_students; ++i)
        {
            new_students[i] = students[i];
        }
        delete[] students;
        students = new_students;
    }
    students[num_students] = new_student;
    num_students++;
}

Student *StudentList::searchStudent(const string &bnumber) const
{
    for (int i = 0; i < num_students; ++i)
    {
        if (students[i].getInfo().getBnumber() == bnumber)
        {
            return &students[i];
        }
    }
    // student with given bnumber not found
    return nullptr;
}

void StudentList::cancelCourse(const string &crn) const
{
    for (int i = 0; i < num_students; ++i)
    {
        if (students[i].getSchedule().searchByCrn(crn) != nullptr)
        {
            students[i].getSchedule().removeCourse(crn);
        }
    }
}

StudentList::~StudentList()
{
    // for (int i = 0; i < num_students; ++i)
    // {
    //     students[i].getSchedule().~CourseInfoList();
    // }
    delete[] students;
}
