#ifndef STUDENT_INFO_LIST_H
#define STUDENT_INFO_LIST_H

#include "StudentInfo.h"

using namespace std;

class StudentInfoList
{
public:
    StudentInfoList();

    StudentInfoList(const StudentInfoList &other);
    StudentInfoList &operator=(const StudentInfoList &other);
    ~StudentInfoList();

    StudentInfo *searchByBnumber(const string &bnum);
    const StudentInfoList &getSchedule();

    int get_num_students() const;
    int removeStudent(const string &bnum);
    void addStudent(const StudentInfo &student_information);

    StudentInfo &getStudent(int index);

private:
    int num_students;
    int capacity;

    StudentInfo *infoList;
};

#endif