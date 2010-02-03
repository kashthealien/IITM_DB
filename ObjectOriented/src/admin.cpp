#include "admin.h"
#include "utils.h"

admin::admin(string name,string address,BloodGroup bloodGroup,Date DOB,\
          string staffid,double salary, Date joinDate,
          map<string,student>* studentList,
          map<string,faculty>* facultyList,
          map<string,staff>* feeStaffList,
          map<string,admin>* administratorList,
          courseWrapper* courses,
          financeWrapper* fees)
          :staff(name,address,bloodGroup,DOB,staffid,salary,joinDate, NULL)
{
        this->studentList = studentList;
        this->facultyList = facultyList;
        this->feeStaffList = feeStaffList;
        this->administratorList = administratorList;
        this->courses = courses;
        this->feeDetails = fees;
}
void admin::addCourse()
{
        cout<<"Enter course name, course number and faculty id\n";
        string courseName,courseNo,facId;
        cin>>courseName>>courseNo>>facId;
        if(facultyList->find(facId) == facultyList->end())
        {
                cout<<"ERROR: INVALID faculty Id\n";
                return;
        }
        course courseItem(courseName,courseNo,facId);
        courses->addCourse(courseItem);
}
void admin::addStudent()
{
        string name,address,rollNo;
        cout<<"Please enter the personal details of the student\n";
        cout<<"Name: ";
        cin>>name;
        cout<<"Roll No: ";
        cin>>rollNo;
        cout<<"Address: ";
        cin>>address;
		printENUM_DEPT();
        cout<<"Department No:";
        int dept;
        readInt(dept);
		cout<<"Date of birth(dd mm yyyy): ";
        Date date;
		readDate(date);
        int hostel,degreeProgram,roomNo;
		printENUM_HOS();
        cout<<"Hostel: ";
        readInt(hostel);
        cout<<"Room No:";
        readInt(roomNo);
		printENUM_DEG();
        cout<<"Degree Program No:";
        readInt(degreeProgram);
        student studentItem(name,address,Bpos,date,rollNo,(Department)dept,(Hostel)hostel,(Degree)degreeProgram,roomNo,Date(1,1,2008),courses);
        (*studentList)[rollNo] = studentItem;
}
void admin::addFeeStaff()
{
        string name,staffId,address;
        float salary;
        int dept;
        cout<<"Enter details of the faculty\n";
        cout<<"Name:";
        cin>>name;
        cout<<"Staff Id:";
        cin>>staffId;
        cout<<"Address:";
        cin>>address;
		cout<<"Date of birth (dd mm yyy):";
        Date DOB;
		readDate(DOB);
        cout<<"Salary:";
        readFloat(salary);
		printENUM_DEPT();
        cout<<"Department:";
        readInt(dept);
        staff feeStaffItem(name,address,Bpos,DOB,staffId,salary,Date(1,1,2009), feeDetails );
        (*feeStaffList)[staffId]=feeStaffItem;
}

void admin::addFaculty()
{
        string name,staffId,address;
        float salary;
        int dept;
        cout<<"Enter details of the faculty\n";
        cout<<"Name:";
        cin>>name;
        cout<<"Staff Id:";
        cin>>staffId;
        cout<<"Address:";
        cin>>address;
		cout<<"Date of birth (dd mm yyy):";
        Date DOB;
		readDate(DOB);
        cout<<"Salary:";
        readFloat(salary);
		printENUM_DEPT();
        cout<<"Department:";
        readInt(dept);
        faculty facultyItem(name,address,Bpos,DOB,staffId,salary,Date(1,1,2009),(Department)dept,courses);
        (*facultyList)[staffId]=facultyItem;
}

void admin::addStudentToCourse()
{
        string rollNo,courseNo;
        cout<<"Enter roll no\n";
        cin>>rollNo;
        if( studentList->find(rollNo) == this->studentList->end())
        {
                cout<<"ERROR: Invalid roll no\n";
                return;
        }
        cout<<"Enter course number\n";
        cin>>courseNo;
        courses->addStudentToCourse(rollNo,courseNo);
}

void admin::showMenu()
{
    while(1)
    {
	horizLine();
	cout<<"\t\tDatabase Administrator Menu\n";
	horizLine();
        cout<<" 1. Add a course\n";
        cout<<" 2. Add a student\n";
        cout<<" 3. Add a faculty member\n";
        cout<<" 4. Add a student to a course\n";
	cout<<" 5. Add a fee collection staff\n";
        cout<<" 6. View all student details\n";
	cout<<" 7. View all faculty details\n";
	cout<<" 8. View all course details\n";
        char ch;
        cin>>ch;

        switch(ch)
        {
            case '1':
                addCourse();
                break;
            case '2':
                addStudent();
                break;
            case '3':
                addFaculty();
                break;
            case '4':
                addStudentToCourse();
                break;
	    case '5':
		addFeeStaff();
		break;
            case '6':
                listStudents();
                break;
            case '7':
                listFaculty();
                break;
            case '8':
                listCourses();
                break;
            default: return;
        }
    }
}

void admin::listStudents()
{
	horizLine();
	cout<<"\t\tStudent Information\n";
	horizLine();
	map<RollNum, student>::iterator stuItr = studentList->begin();
	for(; stuItr != studentList->end(); ++stuItr)
	{
		(stuItr->second).showPersonalDetails();
		cout << endl;
	}
}

void admin::listFaculty()
{
	horizLine();
	cout<<"\t\tFaculty information\n";
	horizLine();
	map<StaffId, faculty>::iterator facItr = facultyList->begin();
	for(; facItr != facultyList->end(); ++facItr)
	{
		(facItr->second).showPersonalDetails();
		cout << endl;
	}
}
void admin::listCourses()
{
	horizLine();
	cout<<"\t\tList of all courses offered\n";
	horizLine();
	list <string> allcourses = courses->getCourseList();
	list <string>::iterator iter = allcourses.begin();
	for( ; iter != allcourses.end(); ++iter)
		cout << *iter << endl;
}


