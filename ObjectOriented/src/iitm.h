#ifndef IITM_H
#define IITM_H

#include "IITM_global.h"
#include "student.h"
#include "staff.h"
#include "faculty.h"
#include "admin.h"
#include "utils.h"

//#include <termios.h>
#include <vector>
#include <map>
#include <iostream>
#include <cstdlib>
#include <termios.h>
using namespace std;

class IITM {
    public:
        IITM();
	void showMainMenu();
	void showDatabaseAdministratorMenu();
	void showStaffMenu();
	void showFacultyMenu();
	void showStudentMenu();
    protected:
        //We have no notion of decentralization at the moment, in terms of departments.
        //We are viewing the institute as a set of people and resources
        //The following members are self explanatory from the member name itself
        map<RollNum,student> studentList;
        map<StaffId,faculty> facultyList;
        map<StaffId,staff> feeStaffList; //Normal staff
        map<StaffId,admin> administratorList; //Administrative staff, who can modify any part of the database
        courseWrapper courses;
        financeWrapper feeDetails;
            //We by default build the database by a single root user, with userid root and password as rootpassword.
};

#endif // IITM_H
