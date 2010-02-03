#include "staff.h"
#include "financeWrapper.h"
staff::staff(string name,string address, \
			 BloodGroup bloodGroup, Date DOB, \
			 string staffId, double salary, Date joinDate,financeWrapper *fee):person(name,address,bloodGroup,DOB \
			 )
{
	this->staffID = staffId;
	this->salary = salary;
	this->join = joinDate;
	this->feeDetails = fee;
}

void staff::payFees()
{
    cout << "Enter the students roll number : ";
    string studRoll;
    cin >> studRoll;
    Fees fee;
    readFees(fee);
    feeDetails->payFees(studRoll, fee);
}

void staff::showMenu()
{
    while(1)
	{
		horizLine();
		cout<<"\t\tFee Collection Staff Menu Menu\n";
		horizLine();
		cout<<" 1. Pay student fee.\n";
		cout<<" 2. Reset Password\n";

		char ch;
		cin>>ch;

		switch(ch)
		{
		case '1':
                        this->payFees();
			break;
		case '2':
                        this->resetPassword();
			break;
		default: return;
		}
	}
}

