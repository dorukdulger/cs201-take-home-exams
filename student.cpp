#include "student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Student::Student(){
	firstName = "";                     // name of the student (include middle name if exists)
	lastName = "";					    // lastname of the student
	ID = "";                            // identity number of the student
	points = 0;

	midtermWeight = 0; 
	finalWeight = 0;
	hwWeight = 0;
}

void Student::setId(string id){
	int ind = id.find(" ");
	int len = id.length();
	id = id.substr(0,ind);
	ID = id;
}

string Student::getId() const{
	return ID;
}

void Student::setName(string name){
	int ind = name.find(" ");
	int len = name.length();
	name = name.substr(ind+1, len-1);
	ind = name.rfind(" ");
	firstName = name.substr(0,ind);
	lastName = name.substr(ind+1, len-1);
}

string Student::getFirstName() const{
	return firstName;
}

string Student::getLastName() const{
	return lastName;
}

void Student::setPoints(double puan){
	points += puan;
}

double Student::getPoints() const{
	return points;
}


void Student::display(vector<Student>& students, int rank){
	cout << rank << ", " << students[rank-1].getId()  << ", " << students[rank-1].getFirstName() << " " 
		<< students[rank-1].getLastName() << ", " <<students[rank-1].getPoints()  << endl;
}

// Exam Functions

void Student::setExamWeights(double hw, double md, double fnl){
	hwWeight = hw;
	midtermWeight = md;
	finalWeight = fnl;
}

double Student::getGrade(string examName, double grade) const{
	if(examName == "***HOMEWORK***"){
		return grade*hwWeight;
	}
	else if(examName == "***MIDTERM***"){
		return grade*midtermWeight;
	}
	else if(examName == "***FINAL***"){
		return grade*finalWeight;
	}
	else{
		return 0;
	}
} 
