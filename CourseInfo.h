#ifndef COURSE_INFO_H
#define COURSE_INFO_H

#include <string>

using namespace std;

class CourseInfo
{
public:
    CourseInfo();
    CourseInfo(string crn_string, string department_string, string number_string, string name_string);


    CourseInfo(const CourseInfo &other);
    CourseInfo &operator=(const CourseInfo &other);

    string getCrn();
    string getDepartment();
    string getNumber();
    string getName();


private:
    string crn;
    string department;
    string number;
    string name;
};

#endif
