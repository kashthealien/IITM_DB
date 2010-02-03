#include "course.h"

course::course()
{
	;
}

course::course(string courseName,string courseNo,string facId)
{
	this->courseName = courseName;
	this->courseNo = courseNo;
	this->facId = facId;
}
void course::addToPrerequisites(list<string> preRequisites)
{
	this->pre_requisites = preRequisites;
}

