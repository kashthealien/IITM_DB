#include "iitm.h"

IITM::IITM()
{
    admin rootUser("root","chennai",Bpos,\
            Date(1,1,1950),"root",10000.00,Date(1,1,2010),
            &this->studentList,
            &this->facultyList,
            &this->feeStaffList,
            &this->administratorList,
            &this->courses,
	    &this->feeDetails);

    this->administratorList["root"] = rootUser;
}

void IITM::showMainMenu()
{
	horizLine();
	cout<<"\t\tWelcome to the IITM Main Database\n";
	horizLine();

    while(1)
    {
        horizLine();
        cout<<"\t\tMain Menu\n";
        horizLine();
        cout<<"1. Administrative Staff\n";
        cout<<"2. Fee Collection Staff\n";
        cout<<"3. Faculty\n";
        cout<<"4. Student\n";
        cout<<"5. Quit\n";

        char ch;
        cin>>ch;
        switch (ch)
        {
            case '1':
                showDatabaseAdministratorMenu();
                break;
            case '2':
                 showStaffMenu();
                break;
            case '3':
                 showFacultyMenu();
                 break;
            case '4':
                 showStudentMenu();
                 break;
            default:
                 exit(0);
        }
    }
}

void IITM::showDatabaseAdministratorMenu()
{
	cout<<"Kindly Authenticate yourself: \n";
	cout<<"Enter Username: ";
        string username, password;
	cin>>username;
	if(this->administratorList.find(username+password) == this->administratorList.end())
	{
		cout<<"ERROR: Invalid id\n";
		return;
	}
	bool res = administratorList[username].authenticate();
	if(!res)
	{
		cout<<"Authentication Failure\n";
		return;
	}
	cout<<"\nWelcome "<<username<<"\n\n";	
    administratorList[username].showMenu();
    
}
void IITM::showStaffMenu()
{

    horizLine();
	cout<<"\t\tFee Collection Staff Menu\n";
    horizLine();

	cout<<"Kindly Authenticate yourself: \n";
	cout<<"Enter Username: ";
    string username;
    cin>>username;
	if(this->feeStaffList.find(username) == this->feeStaffList.end())
	{
		cout<<"ERROR: Invalid id\n";
		return;
	}
	bool res = this->feeStaffList[username].authenticate();
	if(!res)
	{
		cout<<"ERROR: Authentication Failure\n";
		return;
	}
	feeStaffList[username].showMenu();
}


void IITM::showFacultyMenu()
{

    horizLine();
	cout<<"\t\tFaculty Menu\n";
    horizLine();

	cout<<"Kindly Authenticate yourself: \n";
	cout<<"Enter Username: ";
    string username;
    cin>>username;
	if(this->facultyList.find(username) == this->facultyList.end())
	{
		cout<<"ERROR: Invalid id\n";
		return;
	}
	bool res = this->facultyList[username].authenticate();
	if(!res)
	{
		cout<<"ERROR: Authentication Failure\n";
		return;
	}
	facultyList[username].showMenu();
}

void IITM::showStudentMenu()
{
	cout<<"Welcome student, authenticate yourself to login\n";
	string username;
	cout<<"Roll Number: ";
	cin>>username;
	if(this->studentList.find(username) == this->studentList.end())
	{
		cout<<"ERROR: Invalid id\n";
		return;
	}
	bool res = this->studentList[username].authenticate();
	if(!res)
	{
		cout<<"ERROR: Authentication failure\n";
		return;
	}
	studentList[username].showStudentMenu();

}

