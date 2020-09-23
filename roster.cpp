#include<string>
#include "roster.h"

using namespace std;

Roster::~Roster() {
};

void Roster::Add() {
	bool addSequence = true;
	bool studIdDuplicate = false;
	bool validDegreeEntered = false;
	string studId = "";

	while (addSequence == true) {
		do {
			studId = "";
			cout << "Enter Student Id: ";
			cout << endl;
			cin >> studId;
			studIdDuplicate = false;
			for (int i = 0; i < numStudents; ++i) {                       // find out if entered student id is a duplicate.  A duplicate student id would create problems. 
				if (classRosterArray[i].getStudentId() == studId) {
					cout << "That ID is already taken." << endl;
					studIdDuplicate = true;
				};
			};
		} while (studIdDuplicate == true);
		
			string fNameIn;
			string lNameIn;
			string ageIn;
			string emailAddressIn;
			string classDays1In;
			string classDays2In;
			string classDays3In;
			string degreeTypeIn;

			cout << "Enter first name: ";								  // collects strings from user
			cin >> fNameIn;
			cout << endl;
			cout << "Enter last name: ";
			cin >> lNameIn;
			cout << endl;
			cout << "Enter age: ";
			cin >> ageIn;
			cout << endl;
			cout << "Enter email address: ";
			cin >> emailAddressIn;
			cout << endl;
			cout << "Enter Class 1 days: ";
			cin >> classDays1In;
			cout << endl;
			cout << "Enter Class 2 days: ";
			cin >> classDays2In;
			cout << endl;
			cout << "Enter Class 3 days: ";
			cin >> classDays3In;
			cout << endl;
			cout << "Enter Degree Program(SECURITY, NETWORK, OR SOFTWARE): ";
			cin >> degreeTypeIn;
			cout << endl;

			Student* addStudentPtr = nullptr;
			addStudentPtr = new Student;
			(*addStudentPtr).setStudentId(studId);
			(*addStudentPtr).setFirstName(fNameIn);
			(*addStudentPtr).setLastName(lNameIn);
			(*addStudentPtr).setAge(stoi(ageIn));
			(*addStudentPtr).setEmailAddress(emailAddressIn);
			(*addStudentPtr).setDaysToFinishCourse(stoi(classDays1In), stoi(classDays2In), stoi(classDays3In));
			if (degreeTypeIn == "SECURITY") {
				(*addStudentPtr).setDegreeProgram(SECURITY);
				validDegreeEntered = true;
			};
			if (degreeTypeIn == "NETWORK") {
				(*addStudentPtr).setDegreeProgram(NETWORK);
				validDegreeEntered = true;
			};
			if (degreeTypeIn == "SOFTWARE") {
				(*addStudentPtr).setDegreeProgram(SOFTWARE);
				validDegreeEntered = true;
			};
			cout << "Student input received successfully." << endl << endl;

			//add the newly entered student to all other students in a new array and delete the old array.
			tmpClassRosterArrayPtr = new Student[numStudents];

			for (int i = 0; i < numStudents; i++) {
				tmpClassRosterArrayPtr[i].setStudentId(classRosterArray[i].getStudentId());
				tmpClassRosterArrayPtr[i].setFirstName(classRosterArray[i].getFirstName());
				tmpClassRosterArrayPtr[i].setLastName(classRosterArray[i].getLastName());
				tmpClassRosterArrayPtr[i].setAge(classRosterArray[i].getAge());
				tmpClassRosterArrayPtr[i].setEmailAddress(classRosterArray[i].getEmailAddress());
				tmpClassRosterArrayPtr[i].setDaysToFinishCourse(classRosterArray[i].getDaysToFinishCourse1(), classRosterArray[i].getDaysToFinishCourse2(), classRosterArray[i].getDaysToFinishCourse3()); 
				tmpClassRosterArrayPtr[i].setDegreeProgram(classRosterArray[i].getDegreeProgram());
 			};

			delete[] classRosterArray;

			numStudents++;

			classRosterArray = new Student[numStudents];
			for (int i = 0; i < numStudents - 1; i++) {								// I used -1 here because I need to leave room to add in the new student.
				classRosterArray[i].setStudentId(tmpClassRosterArrayPtr[i].getStudentId());
				classRosterArray[i].setFirstName(tmpClassRosterArrayPtr[i].getFirstName());
				classRosterArray[i].setLastName(tmpClassRosterArrayPtr[i].getLastName());
				classRosterArray[i].setAge(tmpClassRosterArrayPtr[i].getAge());
				classRosterArray[i].setEmailAddress(tmpClassRosterArrayPtr[i].getEmailAddress());
				classRosterArray[i].setDaysToFinishCourse(tmpClassRosterArrayPtr[i].getDaysToFinishCourse1(), tmpClassRosterArrayPtr[i].getDaysToFinishCourse2(), tmpClassRosterArrayPtr[i].getDaysToFinishCourse3()); 
				classRosterArray[i].setDegreeProgram(tmpClassRosterArrayPtr[i].getDegreeProgram());
			};

			delete[] tmpClassRosterArrayPtr;

			//time to add in the new student
			classRosterArray[numStudents - 1].setStudentId(addStudentPtr->getStudentId());
			classRosterArray[numStudents - 1].setFirstName(addStudentPtr->getFirstName());
			classRosterArray[numStudents - 1].setLastName(addStudentPtr->getLastName());
			classRosterArray[numStudents - 1].setAge(addStudentPtr->getAge());
			classRosterArray[numStudents - 1].setEmailAddress(addStudentPtr->getEmailAddress());
			classRosterArray[numStudents - 1].setDaysToFinishCourse(addStudentPtr->getDaysToFinishCourse1(), addStudentPtr->getDaysToFinishCourse2(), addStudentPtr->getDaysToFinishCourse3()); //FIXME needs to pick appropriate class number
			classRosterArray[numStudents - 1].setDegreeProgram(addStudentPtr->getDegreeProgram());

			delete addStudentPtr;

			//get out of "ADD" menu
			addSequence = false;
			break;
	
	};
};

void Roster::Remove(string studentId) {
	int studentToRemove = -9999999;
	bool foundStudIdToRemove = false;

	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i].getStudentId() == studentId) {
			studentToRemove = i;
			foundStudIdToRemove = true;
		};
	};

	if (foundStudIdToRemove == true) {
		//numStudents--;

		tmpClassRosterArrayPtr = new Student[numStudents];
		for (int i = 0; i < numStudents; i++) {
			tmpClassRosterArrayPtr[i].setStudentId(classRosterArray[i].getStudentId());
			tmpClassRosterArrayPtr[i].setFirstName(classRosterArray[i].getFirstName());
			tmpClassRosterArrayPtr[i].setLastName(classRosterArray[i].getLastName());
			tmpClassRosterArrayPtr[i].setAge(classRosterArray[i].getAge());
			tmpClassRosterArrayPtr[i].setEmailAddress(classRosterArray[i].getEmailAddress());
			tmpClassRosterArrayPtr[i].setDaysToFinishCourse(classRosterArray[i].getDaysToFinishCourse1(), classRosterArray[i].getDaysToFinishCourse2(), classRosterArray[i].getDaysToFinishCourse3()); 
			tmpClassRosterArrayPtr[i].setDegreeProgram(classRosterArray[i].getDegreeProgram());
		};

		delete[] classRosterArray;

		numStudents--;

		//reassemble the dynamic array in two parts- the separater will be the index of the student that will be removed.
		classRosterArray = new Student[numStudents];
		for (int i = 0; i < studentToRemove; i++) {								
			classRosterArray[i].setStudentId(tmpClassRosterArrayPtr[i].getStudentId());
			classRosterArray[i].setFirstName(tmpClassRosterArrayPtr[i].getFirstName());
			classRosterArray[i].setLastName(tmpClassRosterArrayPtr[i].getLastName());
			classRosterArray[i].setAge(tmpClassRosterArrayPtr[i].getAge());
			classRosterArray[i].setEmailAddress(tmpClassRosterArrayPtr[i].getEmailAddress());
			classRosterArray[i].setDaysToFinishCourse(tmpClassRosterArrayPtr[i].getDaysToFinishCourse1(), tmpClassRosterArrayPtr[i].getDaysToFinishCourse2(), tmpClassRosterArrayPtr[i].getDaysToFinishCourse3()); 
			classRosterArray[i].setDegreeProgram(tmpClassRosterArrayPtr[i].getDegreeProgram());
		};
		//part 2 of reassembly
		for (int i = studentToRemove; i < numStudents; i++) {
			classRosterArray[i].setStudentId(tmpClassRosterArrayPtr[i + 1].getStudentId());
			classRosterArray[i].setFirstName(tmpClassRosterArrayPtr[i + 1].getFirstName());
			classRosterArray[i].setLastName(tmpClassRosterArrayPtr[i + 1].getLastName());
			classRosterArray[i].setAge(tmpClassRosterArrayPtr[i + 1].getAge());
			classRosterArray[i].setEmailAddress(tmpClassRosterArrayPtr[i + 1].getEmailAddress());
			classRosterArray[i].setDaysToFinishCourse(tmpClassRosterArrayPtr[i + 1].getDaysToFinishCourse1(), tmpClassRosterArrayPtr[i + 1].getDaysToFinishCourse2(), tmpClassRosterArrayPtr[i + 1].getDaysToFinishCourse3()); 
			classRosterArray[i].setDegreeProgram(tmpClassRosterArrayPtr[i + 1].getDegreeProgram());
		};

		delete[] tmpClassRosterArrayPtr;
		cout << endl << "Student records deleted." << endl;
	};

	if (studentToRemove == -9999999) {
		cout << "Student Id not found. Please check the Id and try again." << endl;
	};
};

void Roster::PrintAll() {
	for (int i = 0; i < numStudents; i++)
	{
		classRosterArray[i].Student::Print();

	}
};

void Roster::PrintAvgDaysInCourse(string studentId) {           
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i].getStudentId() == studentId) {
			int Avg = (classRosterArray[i].getDaysToFinishCourse1() + classRosterArray[i].getDaysToFinishCourse2() + classRosterArray[i].getDaysToFinishCourse3()) / 3;
			cout << "This student's average amount of days to complete a course is: " << Avg << endl << endl;
		};
	};
}; 

void Roster::PrintInvalidEmails() {
	cout << "-----------------------------------" << endl;
	cout << "Valid emails must include '.' and '@'.  Valid emails must not include ' '." << endl;
	cout << "The following email addresses are invalid:" << endl << endl;

	for (int i = 0; i < numStudents; i++) {

		bool invalidEmail = false;
		string emailToParse = classRosterArray[i].getEmailAddress();
		size_t atSignSearch = -1;
		size_t spaceSearch = -1;
		size_t dotSearch = -1;

		atSignSearch = emailToParse.find("@");
		if (atSignSearch == string::npos) {
			invalidEmail = true;
		};
		spaceSearch = emailToParse.find(" ");
		if (spaceSearch != string::npos) {
			invalidEmail = true;
		};
		dotSearch = emailToParse.find(".");
		if (dotSearch == string::npos) {
			invalidEmail = true;
		};

		if (invalidEmail == true) {
			cout << classRosterArray[i].getEmailAddress() << endl;
		};

	};

};

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {



	for (int i = 0; i < numStudents; i++) {
	
		if (degreeProgram == classRosterArray[i].getDegreeProgram()) {
			classRosterArray[i].Print();
		};

	};
};

void Roster::parseTableForStudentData()  //only called once at start of main
{	
	studentsInTable students[5];
	classRosterArray = new Student[numStudents];

	for (int i = 0; i < numStudents; i++)
	{
		//this is the part that parses through the raw data and turns them into strings
		int rhs = studentData[i].find(",");
		students[i].studentId = studentData[i].substr(0, rhs);

		int lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		students[i].firstName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		students[i].lastName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		students[i].emailAddress = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		students[i].age = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		students[i].numDaysToFinishCourse1 = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		students[i].numDaysToFinishCourse2 = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		students[i].numDaysToFinishCourse3 = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find("\0", lhs);
		students[i].degreeProgram = studentData[i].substr(lhs);

		// THIS IS THE ARRAY OF PTRS THAT CAN CHANGE WHEN NEEDED  

		classRosterArray[i].setStudentId(students[i].studentId);
		classRosterArray[i].setFirstName(students[i].firstName);
		classRosterArray[i].setLastName(students[i].lastName);
		classRosterArray[i].setEmailAddress(students[i].emailAddress);
		classRosterArray[i].setAge(stoi(students[i].age));
		classRosterArray[i].setDaysToFinishCourse(stoi(students[i].numDaysToFinishCourse1), stoi(students[i].numDaysToFinishCourse2), stoi(students[i].numDaysToFinishCourse3));
		if (students[i].degreeProgram == "SECURITY") {
			classRosterArray[i].setDegreeProgram(SECURITY);
		};
		if (students[i].degreeProgram == "NETWORK") {
			classRosterArray[i].setDegreeProgram(NETWORK);
		};
		if (students[i].degreeProgram == "SOFTWARE") {
			classRosterArray[i].setDegreeProgram(SOFTWARE);
		};

	};
	
};

