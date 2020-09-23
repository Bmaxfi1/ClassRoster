#include <iostream>
#include <string>

#include "roster.h"

//Developed by Brandon Maxfield, September 2020

using namespace std;

int main()
{	
	cout << "<<<<  Welcome to ClassRoster!  >>>>" << endl;
	cout << "-----------------------------------" << endl;

	Roster classRoster;
	classRoster.parseTableForStudentData();

	while (bool remain = true)
	{
		cout << "-----------------------------------" << endl;
		string chosenCommand = "";
		string studId = "";
		string pickedDegreeString = "";
		DegreeProgram pickedDegree;

		cout << "Please enter a command." << endl;
		cout << "(valid commands are: ADD, REMOVE, PRINTALL, AVGCOURSELENGTH, INVALIDEMAILS, LISTBYDEGREE and EXIT)" << endl;
		cin >> chosenCommand;

		if (chosenCommand == "ADD")
		{
			classRoster.Add();
			continue;
		}
		if (chosenCommand == "REMOVE")
		{
			cout << "Enter student Id." << endl;
			cin >> studId;
			classRoster.Remove(studId);
			continue;
		}
		if (chosenCommand == "PRINTALL")
		{
			classRoster.PrintAll();
			continue;
		}
		if (chosenCommand == "AVGCOURSELENGTH")
		{
			cout << "Enter student Id." << endl;
			cin >> studId;
			classRoster.PrintAvgDaysInCourse(studId);
			continue;
		}
		if (chosenCommand == "INVALIDEMAILS")
		{
			classRoster.PrintInvalidEmails();
			continue;
		}
		if (chosenCommand == "LISTBYDEGREE")
		{	
			pickedDegreeString = "";
			cout << "Enter degree type:" << endl;
			cout << "(SECURITY, NETWORK, or SOFTWARE)" << endl;
			cin >> pickedDegreeString;

			if (pickedDegreeString == "SECURITY") {
				pickedDegree = SECURITY;
			}
			else if (pickedDegreeString == "NETWORK") {
				pickedDegree = NETWORK;
			}
			else if (pickedDegreeString == "SOFTWARE") {
				pickedDegree = SOFTWARE;
			}
			else {
				cout << "Degree unidentified.  Showing 'SOFTWARE'." << endl;
				pickedDegree = SOFTWARE;
			};

			classRoster.PrintByDegreeProgram(pickedDegree);
			continue;
		}
		if (chosenCommand == "EXIT")
		{
			remain = false;
			break;
		}
		else
		{
			cout << "Invalid command.  Please try again." << endl << endl;
		};
	};

	delete[] classRoster.classRosterArray;  //destructor
	return 0;
}
