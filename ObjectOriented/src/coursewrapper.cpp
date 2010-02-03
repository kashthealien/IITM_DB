#include "coursewrapper.h"

courseWrapper::courseWrapper()
{
    ;
}

void courseWrapper::addCourse(course courseItem)
{
    this->courseList[courseItem.getCourseNo()] = courseItem;
}
void courseWrapper::addStudentToCourse(string rollNo,string courseNo,Grade grade)
{
    if(this->courseList.find(courseNo)!=courseList.end())
        this->studentCourseMap[rollNo][courseNo] = grade;
    else
        cout<<"ERROR: Invalid course\n";
}
void courseWrapper::assignGrade(string facId,string courseNo,string rollNo,Grade grade)
{
    if(this->courseList[courseNo].getFacId()==facId)
    {
        this->studentCourseMap[courseNo][rollNo]=grade;
    }
    else
    {
        cout<<"ERROR: Invalid faculty id\n";
    }
}

void courseWrapper::requestToEnroll(string rollNo,string courseNo)
{
	if(this->courseList.find(courseNo)==this->courseList.end())
	{
		cout<<"ERROR: Invalid course number\n";
		return;
	}
    (this->waitingStudents[courseNo]).push_back(rollNo);
	cout<<"Your request is pending faculty approval\n";
}

void courseWrapper::viewCoursesTakenByStudent(string rollNo)
{
    map<string, Grade>::iterator stud_itr = this->studentCourseMap[rollNo].begin();
    cout << "The following courses are being taken by the student.\n";
    while(stud_itr != this->studentCourseMap[rollNo].end())
    {
        cout << stud_itr->first << "\t" << stud_itr->second <<endl;
        ++stud_itr;
    }
}
void courseWrapper::viewCoursesOfferedByFaculty(string facId)
{
    cout << "The following courses are offered by the faculty.\n";
    map<string, course>::iterator course_itr = (this->courseList).begin();
    while(course_itr != this->courseList.end())
    {
        if( (course_itr->second).getFacId() == facId)
            cout << (course_itr->second).getCourseNo() << "\t"
                << (course_itr->second).getCourseName() << endl;
        ++course_itr;
    }
}

/*
   There are students who have requested to enroll in a particular course.
   This is stored in the third and final map waitingStudents, from rollNo to courseNo
   addWaitingStudents takes a param facID.
   It then finds the coursed which are offered by the facID and then searches the waitingStudents map for students waiting for those courses.
   It adds those students to the second map <rollNo><courseNo><grade =unassigned>
 */
void courseWrapper::addWaitingStudents(string facId)
{
    map<string, course>::iterator course_itr;
    // Go through all courses
    for( course_itr = (this->courseList).begin(); course_itr != this->courseList.end() ; course_itr ++ )
    {
        // Check if the logged in faculty is incharge of the course
        if( (course_itr->second).getFacId() == facId)
        {
            // If so, get the students waiting to enroll for the course
            string courseNo = (course_itr->second).getCourseNo();
            vector<string> rollNos = waitingStudents[courseNo];
            vector<string>::iterator iter;
            // For all students waiting to enroll, do
            for( iter = rollNos.begin() ;iter != rollNos.end(); ++ iter)
            {
                cout << "Enroll roll number  " << *iter << ". [y/n] ? : ";
                char ch = 'n';
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                    studentCourseMap[*iter][course_itr->first] = UNASSIGNED;
            }
			waitingStudents.erase(courseNo);
        }
    }
}

void courseWrapper::dropCourse(string rollNo,string courseNo)
{
	if(studentCourseMap[rollNo].empty())
	{
		cout << "Sorry, you have not enrolled in this course.\n" ;
		return;
	}
	else if(studentCourseMap[rollNo][courseNo] == NULL)
	{
		cout << "Sorry, you have not enrolled in this course.\n" ;
		return;
	}
	else if ( studentCourseMap[rollNo][courseNo] != UNASSIGNED )
	{
		cout << "Sorry. You have already taken this course.\n" ;
		return;
	}
	else
	{
		studentCourseMap[rollNo].erase(courseNo);
		cout << "Course successfully dropped.\n" ;
		return;
	}
}

list<string> courseWrapper::getCourseList()
{
    list<string> myList;                            // The list of strings
    map <string,course>::iterator iter;             // Iterator for the map

    // Add all courseName : courseNumber to the list
    for ( iter = courseList.begin() ; iter != courseList.end() ; iter ++ )
    {
        myList.push_back(iter->second.getCourseNo()+" : "+iter->second.getCourseName());
    }
    // Return the list
    return myList;
}
