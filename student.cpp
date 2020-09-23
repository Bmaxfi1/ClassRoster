#include "student.h"

#include<string>

using namespace std;

//constructor
Student::Student() {
	studentId = "NA";
	firstName = "not yet entered";
	lastName = "not yet entered";
	emailAddress = "notyetentered@null.com";
	age = 0;
	daysToFinishCourse[0] = 0;
	daysToFinishCourse[1] = 0;
	daysToFinishCourse[2] = 0;
	degreeNum;
};


//accessors
string Student::getStudentId() const {
	return studentId;
};
string Student::getFirstName() const {
	return firstName;
};
string Student::getLastName() const {
	return lastName;
};
string Student::getEmailAddress() const {
	return emailAddress;
};
int Student::getAge() const {
	return age;
};
int Student::getDaysToFinishCourse1() const {
	return daysToFinishCourse[0];
};
int Student::getDaysToFinishCourse2() const {
	return daysToFinishCourse[1];
};
int Student::getDaysToFinishCourse3() const {
	return daysToFinishCourse[2];
};
DegreeProgram Student::getDegreeProgram() const {
	return degreeNum;
};

//mutators
void Student::setStudentId(string inputStudentId) {
	studentId = inputStudentId;
};
void Student::setFirstName(string inputFirstName) {
	firstName = inputFirstName;
};
void Student::setLastName(string inputLastName) {
	lastName = inputLastName;
};
void Student::setEmailAddress(string inputEmailAddress) {
	emailAddress = inputEmailAddress;
};
void Student::setAge(int inputAge) {
	age = inputAge;
};
void Student::setDaysToFinishCourse(int inputDaysToFinishCourse1, int inputDaysToFinishCourse2, int inputDaysToFinishCourse3) {
	daysToFinishCourse[0] = inputDaysToFinishCourse1;
	daysToFinishCourse[1] = inputDaysToFinishCourse2;
	daysToFinishCourse[2] = inputDaysToFinishCourse3;

};
void Student::setDegreeProgram(DegreeProgram inputDegree) {
	degreeNum = inputDegree;
	if (degreeNum == SECURITY) {
		degree = "SECURITY";
	}
	if (degreeNum == NETWORK) {
		degree = "NETWORK";
	}
	if (degreeNum == SOFTWARE) {
		degree = "SOFTWARE";
	}

};

//misc functions
void Student::Print() {
	cout << studentId << "	First Name: " << firstName << "	Last Name: " << lastName << "	Age: " << age << "	Email Address: " << emailAddress <<
		"		daysInCourse: " << daysToFinishCourse[0] << ", " << daysToFinishCourse[1] << ", " << daysToFinishCourse[2] << "	Degree Program: " << degree << endl;

	//I personally think the following format looks better, but it does not meet the requirements outlined for this assignment.
	/*cout << "Student Id: " << studentId << endl;
	cout << "Name: " << firstName << " ";
	cout << lastName << endl;
	cout << "Email Address: " << emailAddress << endl;
	cout << "Age: " << age << endl;
	cout << "Days to Finish Course: " << daysToFinishCourse[0] << ", " << daysToFinishCourse[1] << ", " << daysToFinishCourse[2] << endl;
	cout << "Degree Program: " << degree << endl;
	cout << endl;*/
};