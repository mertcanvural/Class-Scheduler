#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <string>

using namespace std;

class StudentInfo
{
public:

    StudentInfo(string bnum, string id, string first_name, string last_name);
    StudentInfo();

    StudentInfo(const StudentInfo &other);
    StudentInfo &operator=(const StudentInfo other);

    string getBnumber() const;
    string getFullName() const;

private:
    string userid;
    string first;
    string last;
    string bnumber;
};

#endif