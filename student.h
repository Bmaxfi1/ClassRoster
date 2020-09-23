#pragma once

#include<iostream>
#include<string>

#include "degree.h"

using namespace std;

	class Student {
	public:

		//constructor
		Student();

		//accessors
		string getStudentId() const;
		string getFirstName() const;
		string getLastName() const;
		string getEmailAddress() const;
		int getAge() const;
		int getDaysToFinishCourse1() const;
		int getDaysToFinishCourse2() const;
		int getDaysToFinishCourse3() const;
		DegreeProgram getDegreeProgram() const;

		//mutators
		void setStudentId(string inputStudentId);
		void setFirstName(string inputFirstName);
		void setLastName(string inputLastName);
		void setEmailAddress(string inputEmailAddress);
		void setAge(int inputAge);
		void setDaysToFinishCourse(int inputDaysToFinishCourse1, int inputDaysToFinishCourse2, int inputDaysToFinishCourse3);
		void setDegreeProgram(DegreeProgram inputDegree);

		//misc functions
		void Print();

	private:
		string studentId;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysToFinishCourse[3];
		DegreeProgram degreeNum;
		string degree = "VOID";
	};
