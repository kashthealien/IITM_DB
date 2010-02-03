#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <list>
#include <termios.h>

#include "IITM_global.h"

// Added getCourseName method

using namespace std;
class course
{
public:
    course();
	course(string courseName,string courseNo,string facId);
	string getCourseNo() { return courseNo;}
	string getCourseName() { return courseName;}
	void addToPrerequisites(list<string> preRequisites);
	string getFacId(){return facId;}
protected:
    string courseName;
    string courseNo;
    string facId;
    list<string> pre_requisites;

    Department dept;
};

#endif // COURSE_H
