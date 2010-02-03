#ifndef ADMIN_H
#define ADMIN_H
#include "staff.h"
#include "faculty.h"
#include "student.h"
#include "coursewrapper.h"
#include "financeWrapper.h"
#include "course.h"
#include "utils.h"

#include <termios.h>
#include <string>
#include <map>

using namespace std;
class admin : public staff
{
public:
	admin(){;}
	admin(string name,string address,BloodGroup bloodGroup,Date DOB,\
          string staffid,double salary, Date joinDate,\
          map<RollNum,student>* studentList,\
          map<StaffId,faculty>* facultyList,\
          map<StaffId,staff>* feeStaffList,\
          map<StaffId,admin>* administratorList,\
          courseWrapper* courses,\
          financeWrapper* fees);

        void showMenu();
        // Administration functions
        void addFaculty();
        void addFeeStaff();
        void addStudent();
        void addCourse();
        void addStudentToCourse();
        
        // View Lists from the Database
        
        void listStudents();
        void listFaculty();
        void listCourses();

private:
        map<RollNum,student>* studentList;
        map<StaffId,faculty>* facultyList;
        map<StaffId,staff>* feeStaffList;
        map<StaffId,admin>* administratorList;
        courseWrapper* courses;
        financeWrapper* feeDetails;
};

#endif // ADMIN_H
