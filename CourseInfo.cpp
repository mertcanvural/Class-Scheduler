#include <iostream>
#include <stdlib.h>

#include "CourseInfo.h"

using namespace std;

CourseInfo::CourseInfo()
{
   crn = "";
   department = "";
   number = "";
   name = "";
}

CourseInfo::CourseInfo(string crn_string, string department_string, string number_string, string name_string)
{
   crn = crn_string;
   department = department_string;
   number = number_string;
   name = name_string;
}

CourseInfo::CourseInfo(const CourseInfo &other)
{
   crn = other.crn;
   department = other.department;
   number = other.number;
   name = other.name;
}

CourseInfo &CourseInfo::operator=(const CourseInfo &other)
{
    if (this != &other)
    {
        crn = other.crn;
        department = other.department;
        number = other.number;
        name = other.name;
    }
    return *this;
}

string CourseInfo::getCrn()
{
   return crn;
}

string CourseInfo::getDepartment()
{
   return department;
}

string CourseInfo::getNumber()
{
   return number;
}

string CourseInfo::getName()
{
   return name;
}
