#include "faculty.h"

faculty::faculty(string name,string address,BloodGroup bloodGroup,\
				 Date DOB,string staffId,double salary,Date joinDate,\
				 Department department,courseWrapper *courses)\
				 :staff(name,address,bloodGroup,DOB,staffId,salary,joinDate, NULL)
{
	this->dept = department;
	this->courses = courses;
}
void faculty::assignGrade()
{
	string rollNo,courseNo;
	int grade;
	cout<<"Enter Roll Number: ";
	cin>>rollNo;
	cout<<"Enter Course No: ";
	cin>>courseNo;
	cout<<"Enter Grade number: ";
	readInt(grade);
	courses->assignGrade(this->staffID,courseNo,rollNo,(Grade)grade);
}

void faculty::showMenu()
{
    while(1)
	{
		horizLine();
		cout<<"\t\tFaculty Menu\n";
		horizLine();
		cout<<" 1. Enroll students.\n";
		cout<<" 2. Grade a student\n";
		cout<<" 3. View Courses\n";
		cout<<" 4. Reset Password\n";

		char ch;
		cin>>ch;

		switch(ch)
		{
		case '1':
                        this->addWaitingStudents();
			break;
		case '2':
                        this->assignGrade();
			break;
		case '3':
                        this->viewCoursesOffered();
			break;
		case '4':
                        this->resetPassword();
			break;
		default: return;
		}
	}
}

void faculty::showPersonalDetails()
{
    cout<<"Name: "<<this->name<<endl;
    cout<<"Address: "<<this->address<<endl;
    cout<<"Department: "<<this->dept<<endl;
}
