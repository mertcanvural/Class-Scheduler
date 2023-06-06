#include "StudentInfoList.h"
#include "StudentInfo.h"


StudentInfoList::StudentInfoList()
{
    num_students = 0;
    capacity = 2;
    infoList = new StudentInfo[capacity];
}

StudentInfoList::StudentInfoList(const StudentInfoList& other)
{
    num_students = other.num_students;
    capacity = other.capacity;
    infoList = new StudentInfo[capacity];
    for (int i = 0; i < num_students; ++i)
    {
        infoList[i] = other.infoList[i];
    }
}

StudentInfoList& StudentInfoList::operator=(const StudentInfoList& other)
{
    if (this != &other)
    {
        num_students = other.num_students;
        capacity = other.capacity;
        delete[] infoList;
        infoList = new StudentInfo[capacity];
        for (int i = 0; i < num_students; ++i)
        {
            infoList[i] = other.infoList[i];
        }
    }
    return *this;
}


int StudentInfoList::get_num_students() const
{
    return this->num_students;
}

StudentInfo &StudentInfoList::getStudent(int index)
{
    return infoList[index];
}

void StudentInfoList::addStudent(const StudentInfo &student_information)
{
    if (num_students == capacity)
    {
        capacity = 2 * capacity;
        StudentInfo *new_infoList = new StudentInfo[capacity];
        for (int i = 0; i < num_students; ++i)
        {
            new_infoList[i] = infoList[i];
        }
        delete[] infoList;
        infoList = new_infoList;
    }
    infoList[num_students] = student_information;
    num_students++;
}

StudentInfo *StudentInfoList::searchByBnumber(const string &bnum)
{
    for (int i = 0; i < num_students; ++i)
    {
        if (infoList[i].getBnumber() == bnum)
        {
            return &infoList[i];
        }
    }
    return nullptr;
}

int StudentInfoList::removeStudent(const string &bnum)
{
    int index = -1;
    for (int i = 0; i < num_students; i++)
    {
        if (infoList[i].getBnumber() == bnum)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        return 0;
    }
    for (int i = index; i < num_students - 1; i++)
    {
        infoList[i] = infoList[i + 1];
    }
    num_students--;
    return 1;
}

StudentInfoList::~StudentInfoList()
{
    delete[] infoList;
}
