// for cin / cout
#include <iostream>
// for parsing
#include <sstream>
// for string manipulations
#include <string>

#include "CourseInfo.h"
#include "StudentInfoList.h"
#include "Course.h"
#include "StudentList.h"
#include "CourseList.h"

// using namespace std;

void showPrompt();
int check_crn(const string &crn);
int check_department_code(const string &department);
int check_number(const string &number);
int check_bnumber(const string &bnumber);
int check_userid(const string &userid);

int main()
{
  string input, command;
  int token_count;

  // all students enrolled
  StudentList all_students;
  // all courses created
  CourseList all_courses;
  while (true)
  {
    showPrompt();
    getline(cin, input);
    stringstream ss(input);

    token_count = 0;
    ss >> command;

    if (command == "quit")
    {
      break;
    }
    else if (command == "build")
    {
      string crn, department, number, name;
      if (ss >> crn)
      {
        token_count++;
      }
      if (ss >> department)
      {
        token_count++;
      }
      if (ss >> number)
      {
        token_count++;
      }
      getline(ss >> ws, name);
      token_count++;

      if (token_count != 4 || name.empty())
      {
        cout << "Input Error: too few arguments" << endl;
        continue;
      }
      if (!(check_crn(crn)))
      {
        continue;
      }

      if (!(check_department_code(department)))
      {
        continue;
      }

      if (!(check_number(number)))
      {
        continue;
      }

      if (all_courses.searchByCrn(crn) != nullptr)
      {
        cout << "Fail: cannot build course " << department << number << " (CRN: " << crn << "): " << "CRN exists" << endl;
        continue;
      }
      else
      {
        CourseInfo new_course_info(crn, department, number, name);

        StudentInfoList new_roster = StudentInfoList();
        
        Course new_course = Course(new_course_info, new_roster);
        all_courses.addCourse(new_course);
        cout << "Success: built course " << department << number << " (CRN: " << crn << "): " << name << endl;
      }
    }
    else if (command == "cancel")
    {
      string crn, extra_arg;
      if (ss >> crn)
      {
        token_count++;
      }
      // flag extra arguments
      if (ss >> extra_arg)
      {
        cout << "Warning: ignoring extra argument(s)" << endl;
      }

      // check token count
      if (token_count < 1)
      {
        cout << "Input Error: too few arguments" << endl;
        continue;
      }

      // Check CRN
      if (!(check_crn(crn)))
      {
        continue;
      }

      if (all_courses.searchByCrn(crn) == nullptr)
      {
        cout << "Fail: cannot cancel course, CRN does not exist" << endl;
        continue;
      }
      else
      {
        all_students.cancelCourse(crn);
        all_courses.removeCourse(crn);
        cout << "Success: cancelled course " << crn << endl;
        continue;
      }
    }
    else if (command == "enroll")
    {
      string bnumber, userid, first, last, extra_arg;
      if (ss >> bnumber)
      {
        token_count++;
      }
      if (ss >> userid)
      {
        token_count++;
      }
      if (ss >> first)
      {
        token_count++;
      }
      if (ss >> last)
      {
        token_count++;
      }

      // getline(ss >> ws, last);
      // token_count++;

      // Check token count
      if (token_count < 4)
      {
        cout << "Input Error: too few arguments" << endl;
        continue;
      }
      // Flag extra arguments
      if (ss >> extra_arg)
      {
        cout << "Warning: ignoring extra argument(s)" << endl;
      }
      // check bnumber
      if (!check_bnumber(bnumber))
      {
        continue;
      }
      // check userid
      if (!check_userid(userid))
      {
        continue;
      }
      // first and last name can be any string...

      if (all_students.searchStudent(bnumber) != nullptr)
      {
        cout << "Fail: cannot enroll student, B Number exists" << endl;
        continue;
      }
      else
      {
        StudentInfo new_student_info = StudentInfo(bnumber, userid, first, last);
        CourseInfoList new_schedule = CourseInfoList();
        Student new_student = Student(new_student_info, new_schedule);
        all_students.addStudent(new_student);
        cout << "Success: enrolled student " << bnumber << " (" << userid << ") " << first << " " << last << endl;
      }
    }
    else if (command == "add") // The user enters add to put a student(brn) into a course(crn)
    {
      string bnumber, crn, extra_arg;
      if (ss >> bnumber)
      {
        token_count++;
      }
      if (ss >> crn)
      {
        token_count++;
      }
      // Check token count
      if (token_count < 2)
      {
        cout << "Input Error: too few arguments" << endl;
        continue;
      }
      // Flag extra arguments
      if (ss >> extra_arg)
      {
        cout << "Warning: ignoring extra argument(s)" << endl;
      }
      // Check bnumber
      if (!check_bnumber(bnumber))
      {
        continue;
      }
      // Check CRN
      if (!(check_crn(crn)))
      {
        continue;
      }

      if (all_courses.searchByCrn(crn) == nullptr)
      {
        cout << "Fail: cannot add, student " << bnumber << ". CRN does not exist " << crn << endl;
        continue;
      }

      if (all_students.searchStudent(bnumber) == nullptr)
      {
        cout << "Fail: cannot add, student " << bnumber << " does not exist in the records." << endl;
        continue;
      }

      StudentInfo current_student_info = all_students.searchStudent(bnumber)->getInfo();
      if (all_courses.searchByCrn(crn)->getRoster().searchByBnumber(bnumber) != nullptr)
      {
        cout << "Fail: cannot add, student " << bnumber << " already enrolled in course " << crn << endl;
        continue;
      }
      else
      {
        all_courses.searchByCrn(crn)->getRoster().addStudent(current_student_info);
        CourseInfo current_course_information = all_courses.searchByCrn(crn)->getInfo();
        all_students.searchStudent(bnumber)->addToSchedule(current_course_information);
        cout << "Success: added student " << bnumber << " into course " << crn << endl;
        continue;
      }
    }
    else if (command == "drop") // The user types drop to remove a student from a course.
    {
      string bnumber, crn, extra_arg;
      if (ss >> bnumber)
      {
        token_count++;
      }
      if (ss >> crn)
      {
        token_count++;
      }
      // Check token count
      if (token_count < 2)
      {
        cout << "Input Error: too few arguments" << endl;
        continue;
      }
      // Flag extra arguments
      if (ss >> extra_arg)
      {
        cout << "Warning: ignoring extra argument(s)" << endl;
      }
      // Check bnumber
      if (!check_bnumber(bnumber))
      {
        continue;
      }
      // Check CRN
      if (!(check_crn(crn)))
      {
        continue;
      }

      // avoid segmentation error
      if (all_courses.searchByCrn(crn) == nullptr)
      {
        cout << "Fail: cannot drop, student " << bnumber << ". CRN does not exist." << endl;
        continue;
      }

      if (all_courses.searchByCrn(crn)->getRoster().searchByBnumber(bnumber) == nullptr)
      {
        cout << "Fail: cannot drop, student " << bnumber << " not enrolled in course " << crn << endl;
        continue;
      }
      else
      {
        all_courses.searchByCrn(crn)->getRoster().removeStudent(bnumber);
        all_students.searchStudent(bnumber)->getSchedule().removeCourse(crn);
        cout << "Success: removed student " << bnumber << " from course " << crn << endl;
        continue;
      }
      // check if the student is enrolled in the course
      // Course *course = courses.searchByCrn(crn);
      // Student *student = students.searchByBnumber(bnumber);
      // if (course && student && course->getRoster()->searchByBnumber(bnumber))
      //{
      //  course->getRoster()->removeStudent(student);
    }
    else if (command == "roster") // print out the students in a particular crn
    {
      string crn, extra_arg;
      if (ss >> crn)
      {
        token_count++;
      }
      // Check token count
      if (token_count < 1)
      {
        cout << "Input Error: too few arguments" << endl;
        continue;
      }
      // Flag extra arguments
      if (ss >> extra_arg)
      {
        cout << "Warning: ignoring extra argument(s)" << endl;
      }
      // Check CRN
      if (!(check_crn(crn)))
      {
        continue;
      }

      if (all_courses.searchByCrn(crn) == nullptr)
      {
        cout << "Fail: cannot show roster of " << crn << ". CRN does not exist." << endl;
        continue;
      }

      all_courses.searchByCrn(crn)->showRoster();
      continue;
    }
    else if (command == "schedule") // print out the courses that a particular bnumber is taking
    {
      string bnumber, extra_arg;
      if (ss >> bnumber)
      {
        token_count++;
      }
      // Check token count
      if (token_count < 1)
      {
        cout << "Input Error: too few arguments" << endl;
        continue;
      }
      // Flag extra arguments
      if (ss >> extra_arg)
      {
        cout << "Warning: ignoring extra argument(s)" << endl;
      }
      // Check CRN
      if (!(check_bnumber(bnumber)))
      {
        continue;
      }

      if (all_students.searchStudent(bnumber) == nullptr)
      {
        cout << "Fail: cannot show schddule of " << bnumber << ". Student does not exist." << endl;
        continue;
      }

      all_students.searchStudent(bnumber)->showSchedule();
    }
    else
    {
      cout << "Input Error: command not recognized, please try again." << endl;
      continue;
    }
  }

  //
  // all_courses.~CourseList();
  // all_students.~StudentList();
  // delete all_courses;
  // delete all_students;
}

int check_crn(const string &crn)
{
  if (crn.length() != 6)
  {
    cout << "Input Error: illegal CRN" << endl;
    return 0;
  }
  for (char c : crn)
  {
    if (!isdigit(c))
    {
      cout << "Input Error: illegal CRN" << endl;
      return 0;
    }
  }
  return 1;
}

int check_department_code(const string &department)
{
  if (department.length() < 2 || department.length() > 4)
  {
    cout << "Input Error: illegal department" << endl;
    return 0;
  }
  for (char c : department)
  {
    if (!isupper(c))
    {
      cout << "Input Error: illegal department" << endl;
      return 0;
    }
  }
  return 1;
}

int check_number(const string &number)

{
  if (number.length() != 3)
  {
    cout << "Input Error: illegal course number" << endl;
    return 0;
  }
  for (char c : number)
  {
    if (!isdigit(c))
    {
      cout << "Input Error: illegal course number" << endl;
      return 0;
    }
  }
  if (stoi(number) < 100 || stoi(number) > 700)
  {
    cout << "Input Error: illegal course number" << endl;
    return 0;
  }
  return 1;
}

int check_bnumber(const string &bnumber)
{
  int b_len = bnumber.length();

  if (b_len != 9)
  {
    cout << "Input Error: illegal Bnumber." << endl;
    return 0;
  }
  if (bnumber[0] != 'B')
  {
    cout << "Input Error: illegal Bnumber." << endl;
    return 0;
  }
  for (int i = 1; i < b_len; ++i)
  {
    if (!(isdigit(bnumber[i])))
    {
      cout << "Input Error: illegal Bnumber." << endl;
      return 0;
    }
  }

  return 1;
}

int check_userid(const string &userid)
{
  if (!isalpha(userid[0]))
  {
    cout << "Input Error: User id must start with a letter." << endl;
    return 0;
  }
  for (unsigned int i = 1; i < userid.size(); ++i)
  {
    if (!((isdigit(userid[i]) || (isalpha(userid[i])))))
    {
      cout << (isdigit(userid[i])) << " " << (isalpha(userid[i])) << endl;
      cout << "Input Error: User id must contain letters or integers after the first character." << endl;
      return 0;
    }
  }
  return 1;
}

void showPrompt()
{
  cout << "Enter [\"build <crn> <department> <number> <name>\"" << std::endl
            << "       \"cancel <crn>\"" << std::endl
            << "       \"enroll <bnumber> <userid> <first> <last>\"" << std::endl
            << "       \"add <bnumber> <crn>\"" << std::endl
            << "       \"drop <bnumber> <crn>\"" << std::endl
            << "       \"roster <crn>\"" << std::endl
            << "       \"schedule <bnumber>\"" << std::endl
            << "       \"quit\"]" << std::endl
            << ": ";
}
