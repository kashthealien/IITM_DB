#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <termios.h>

#include "IITM_global.h"
#include "person.h"
#include "coursewrapper.h"
#include "utils.h"

using namespace std;
class student : public person
{
public:
  student(){this->courses = NULL;}
  student(string name,string address,BloodGroup bloodGroup,		\
	  Date DOB,string rollNo,Department branch,Hostel hostel,	\
	  Degree degreeProgram,int roomNo, Date enroll,			\
	  courseWrapper *courses);
  void showStudentMenu();
  string getRollNo(){return rollNo;}
  Department getBranch(){return branch;}
  Hostel getHostel(){return hostel;}
  Degree getDegreeProgram(){return degreeProgram;}
  int getRoomNo(){return roomNo;}
  Date getEnrollDate(){return enroll;}
  void showPersonalDetails();
  void requestToEnroll();
  void viewEnrolledCourses();
  void dropCourse();
protected:
  string rollNo;                      // Roll number of the student
  Department branch;                  // Branch of the student
  Hostel hostel;                      // Hostel name
  Degree degreeProgram;
  int roomNo;                      // Hostel room number
  Date enroll;                        // Date of enrollment
  courseWrapper *courses;

};

#endif // STUDENT_H
