#ifndef PROF_H
#define PROF_H

#include <string>
#include <termios.h>

#include "IITM_global.h"
#include "staff.h"
#include "coursewrapper.h"
using namespace std;
class faculty : public staff
{
public:
    faculty(string name,string address,BloodGroup bloodGroup,\
				 Date DOB,string staffId,double salary,Date joinDate,\
				 Department department,courseWrapper *courses);
	faculty(){this->courses = NULL;}
	Department getDepartment(){return dept;}
	void assignGrade();
	void viewCoursesOffered()
	{courses->viewCoursesOfferedByFaculty(this->staffID);}
	void addWaitingStudents()
	{courses->addWaitingStudents(this->staffID);}
	void showPersonalDetails();
	void showMenu();

protected:
    Department dept;
	courseWrapper *courses;
};

#endif // PROF_H
