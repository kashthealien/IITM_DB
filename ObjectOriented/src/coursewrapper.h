#ifndef COURSEWRAPPER_H
#define COURSEWRAPPER_H

#include "IITM_global.h"
#include "course.h"

#include <termios.h>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <iostream>
using namespace std;
class courseWrapper
{
    //map from course no to a course

    // Course Number to Course object
    map <CourseId,course> courseList;

    //map from student's rollno to a map of courses, grades
    //Thus we index into the table with the RollNo
    //to get a list of courses available by the student and the grades

    // Roll Number to <Course, Grade>
    map< RollNum,map< CourseId,Grade> > studentCourseMap;
    //Allow a student to post a request for enrolling
    //map from roll no to course no

    // Course Number to Roll Number list
    map<string,vector <string> > waitingStudents;

    public:
    courseWrapper();
    void addCourse(course courseItem);
    //Note that checks such as rollNo validity are to be done before-hand
    void addStudentToCourse(string rollNo,string courseNo,Grade grade = UNASSIGNED);
    void assignGrade(string facId,string courseNo,string rollNo,Grade grade);
    void viewCoursesTakenByStudent(string rollNo);
    void viewCoursesOfferedByFaculty(string facId);
    void addWaitingStudents(string facId);
    void requestToEnroll(string rollNo,string courseNo);
    void dropCourse(string rollNo, string courseNo);
    list<string> getCourseList();

};

#endif // COURSEWRAPPER_H
