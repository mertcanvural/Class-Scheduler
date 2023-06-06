#include <iostream>

#include "StudentInfo.h"

StudentInfo::StudentInfo()
{
    userid = "";
    first = "";
    last = "";
    bnumber = "";
}

// value constructor
StudentInfo::StudentInfo(string bnum, string id, string first_name, string last_name)
{
    userid = id;
    first = first_name;
    last = last_name;
    bnumber = bnum;
}

StudentInfo::StudentInfo(const StudentInfo &other)
{
    userid = other.userid;
    first = other.first;
    last = other.last;
    bnumber = other.bnumber;
}

StudentInfo &StudentInfo::operator=(const StudentInfo other)
{
    if (this != &other)
    {
        userid = other.userid;
        first = other.first;
        last = other.last;
        bnumber = other.bnumber;
    }
    return *this;
}

// Bnumber getter
string StudentInfo::getBnumber() const
{
    return this->bnumber;
}

string StudentInfo::getFullName() const
{
    return this->first + " " + this->last;
}
