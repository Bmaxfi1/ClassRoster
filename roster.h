#pragma once

#include "student.h"
#include<string>

using namespace std;

class Roster
{
public:
	~Roster();  //DESTRUCTOR
		
	void Add();
	void Remove(string studentId);
	void PrintAll();
	void PrintAvgDaysInCourse(string studentId);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degreeProgram);
	void parseTableForStudentData();

	int numStudents = 5;
	string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	};
	struct studentsInTable
	{
		string studentId;
		string firstName;
		string lastName;
		string emailAddress;
		string age;
		string numDaysToFinishCourse1;
		string numDaysToFinishCourse2;
		string numDaysToFinishCourse3;
		string degreeProgram;
	};
	studentsInTable students[5];

	Student* classRosterArray = nullptr;
	Student* tmpClassRosterArrayPtr = nullptr;
};

