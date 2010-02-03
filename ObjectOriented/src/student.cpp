#include "student.h"

student::student(string name,string address,BloodGroup bloodGroup,\
        Date DOB,string rollNo,Department branch,Hostel hostel,\
        Degree degreeProgram,int roomNo, Date enroll,courseWrapper *courses)\
    :person(name,address,bloodGroup,DOB)
{
    this->rollNo = rollNo;
    this->branch = branch;
    this->hostel = hostel;
    this->degreeProgram = degreeProgram;
    this->roomNo = roomNo;
    this->enroll = enroll;
    this->courses = courses;

}
void student::viewEnrolledCourses()
{
    this->courses->viewCoursesTakenByStudent(this->rollNo);
}
void student::requestToEnroll()
{
    cout<<"Enter course no you wish to enroll\n";
    string courseNo;
    cin>>courseNo;
    courses->requestToEnroll(this->rollNo,courseNo);
}
void student::showStudentMenu()
{
    while(1)
    {
		horizLine();
		cout<<"\t\tStudent Menu\n";
		horizLine();
        cout<<"1. View personal details\n";
        cout<<"2. View enrolled courses\n";
        cout<<"3. Request to enroll for a course\n";
        cout<<"4. Reset password\n";
        cout<<"5. Drop a course\n";
        cout<<"6. Quit\n";
        char ch;
        cin>>ch;
        switch(ch)
        {
            case '1': 
                showPersonalDetails();
                break;
            case '2': 
                viewEnrolledCourses();
                break;
            case '3':
                requestToEnroll();
                break;
            case '4':
                resetPassword();
                break;
            case '5':
                dropCourse();
                break;

            default: 
                return;
        }
    }

}
void student::showPersonalDetails()
{
    cout<<"Name: "<<this->name<<endl;
    cout<<"Address: "<<this->address<<endl;
    cout<<"Department no: "<<this->branch<<" Degree program no: "<<this->degreeProgram<<endl;
}

void student::dropCourse()
{
	cout << "Enter the Course Id of the course you wish to drop : " << endl;
	string cid;
	cin >> cid;
	courses->dropCourse(this->rollNo, cid);
}
	

