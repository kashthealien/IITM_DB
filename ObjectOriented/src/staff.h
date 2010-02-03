#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <termios.h>

#include "person.h"
#include "IITM_global.h"
#include "financeWrapper.h"

using namespace std;
class staff : public person
{
public:
	staff(){;}
    staff(string name,string address, \
			 BloodGroup bloodGroup, Date DOB, \
			 string staffId, double salary, Date joinDate,
			 financeWrapper *fee = NULL);
	string getStaffId(){return staffID;}
	double getSalary(){return salary;}
	Date getDateOfJoin(){return join;}
    void payFees();
    void showMenu();
    
protected:
    string staffID;
    double salary;
    Date join;                          // Date of joining
    financeWrapper *feeDetails;
};

#endif // FACULTY_H
