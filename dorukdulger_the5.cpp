#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "student.h"

using namespace std;

bool checkfile(string file){
	ifstream input;
	input.open(file.c_str());
	if(input.fail()){
		cout << "Can not find the requested file. Terminating application ..." << endl;
		return true;
	}
	return false;
}

void SelectSort(vector<Student> &students){
	int j, k, minIndex, numElts = students.size(),x=1;
	Student tempStuK, tempStuJ;
	for(k=0; k < numElts-1; k++){
		minIndex = k;             
		for(j=k+1; j < numElts; j++)
			if (students[j].getPoints() > students[minIndex].getPoints() || (students[j].getPoints() == students[minIndex].getPoints()
				&& students[j].getLastName() < students[minIndex].getLastName()))
				minIndex = j; 
		tempStuK = students[k];
		tempStuJ = students[minIndex];
		students[k] = tempStuJ;
		students[minIndex] = tempStuK;
	}
}

int main(){
	string a,Gradefile,Namefile,temp, examName, midstr ="***MIDTERM***" ,hwstr = "***HOMEWORK***" ,finalstr = "***FINAL***",line;
	int rank = 1, numStudents = 0;
	ifstream input;
	double point, hw=0.1, md=0.2, fnl=0.3, tempGrade,i;

	vector<Student> students;

	cout << "Please enter a filename for Students Grades Results: ";
	cin >> Gradefile;
	if(checkfile(Gradefile)){
		return 0;
	}

	cout << "Please enter a filename for Students Names: ";
	cin >> Namefile;
	if(checkfile(Namefile)){
		return 0;
	}


	input.open(Namefile.c_str());

	while(getline(input,line)){
		Student tempstu;
		tempstu.setId(line);
		tempstu.setName(line);
		students.push_back(tempstu);
		numStudents++;
	}

	input.close();

	input.open(Gradefile.c_str());

	input >> examName;
	a = examName;
	while(!input.eof()){
		examName = a;
		input >> temp;
		while(temp != midstr && temp != finalstr && temp != hwstr && temp != "end"){
			if(!input.eof()){
				input >> tempGrade;
				i = 0;
				while(i<numStudents){	
					if(temp == students[i].getId()){	
						students[i].setExamWeights(hw,md,fnl);
						point = students[i].getGrade(examName,tempGrade);
						students[i].setPoints(point);
						i = numStudents+1;
					}else{
						i++;
					}	
				}
				input >> temp;
				a = temp;
			}else{
				temp = "end";
			}

		}
	}

	input.close();

	SelectSort(students);


	while(students[numStudents-1].getPoints() == 0){
		numStudents--;
	}

	while(rank != 0){
		cout << "Enter the rank you want to query (enter 0 to exit): ";
		cin >> rank;
		if(rank != 0){
			if(rank >= 0 && rank <= numStudents){
				students[rank-1].display(students, rank);
			}else{
				cout << "Rank needs to be greater than 0 and smaller than " << numStudents+1 << "!" << endl; 
			}
		}
	}


	cout << "Exiting..." << endl;
	return 0;
}