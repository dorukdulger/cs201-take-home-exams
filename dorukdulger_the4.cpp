#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
void printS(vector<string> x){
	for (unsigned int i = 0; i < x.size(); i++) {
		cout << x[i] << endl;
	}
}
void printD(vector <double> x){
	for (unsigned int i = 0; i < x.size(); i++) {
		cout << x[i] << endl;
	}
}
void SelectSort(vector<double> & grades, vector<string> & names, vector<string> & Lnames, vector<string> & IDs){
	int j, k, minIndex, numElts = grades.size();
	double tempGr;
	string tempName, tempLast, tempID;
	for(k=0; k < numElts-1; k++){
		minIndex = k;             
		for(j=k+1; j < numElts; j++)
			if (grades[j] > grades[minIndex] || (grades[j] == grades[minIndex] && Lnames[j] < Lnames[minIndex]))
				minIndex = j; 
		tempGr = grades[k];
		tempName = names[k];
		tempLast = Lnames[k];
		tempID = IDs[k];

		grades[k] = grades[minIndex];
		names[k] = names[minIndex];
		Lnames[k] = Lnames[minIndex];
		IDs[k] = IDs[minIndex];

		grades[minIndex] = tempGr;
		names[minIndex] = tempName;
		Lnames[minIndex] = tempLast;
		IDs[minIndex] = tempID;

	}
}


int main(){

	string Gradefile,Namefile,line,tempnum,tempname,templastname,j;
	int rank = 1, numStudents = 0, spaceind,length,i;
	ifstream input;
	double point,limit=0;


	vector<string> stuNames;
	vector<string> stuIDNum;
	vector<string> stuLastnames;


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
		numStudents++;
		length = line.length();
		spaceind = line.find(" ");
		tempnum = line.substr(0,spaceind);
		line = line.substr(spaceind+1, length-1);
		spaceind = line.find(" ");
		tempname = line.substr(0,spaceind);
		templastname = line.substr(spaceind+1, length-1);
		stuIDNum.push_back(tempnum);
		stuNames.push_back(tempname);
		stuLastnames.push_back(templastname);
	}

	input.close();

	vector<double> stuPoints(numStudents);

	input.open(Gradefile.c_str());

	double num = 0.0;
	input >> tempnum;

	while(limit != 1){
		if(tempnum == "***HOMEWORK***"){
			tempnum = " ";
			while(tempnum != "***HOMEWORK***" &&tempnum != "***MIDTERM***" &&tempnum != "***FINAL***"&&j!=tempnum){
				j = tempnum;
				input >> tempnum;
				if(tempnum != "***HOMEWORK***" &&tempnum != "***MIDTERM***" &&tempnum != "***FINAL***"&&j!=tempnum){
					input >> num;
					i = 0;
					while(i<numStudents){	
						if(tempnum == stuIDNum[i]){	
							point = num * 0.1;
							stuPoints[i] = stuPoints[i] + point;
							i = numStudents+1;
						}
						else{
							i++;
						}
					}
				}
			}
		}
		else if(tempnum == "***MIDTERM***"){
			tempnum = " ";
			while(tempnum != "***HOMEWORK***" &&tempnum != "***MIDTERM***" &&tempnum != "***FINAL***"&&j!=tempnum){
				j = tempnum;
				input >> tempnum;
				if(tempnum != "***HOMEWORK***" &&tempnum != "***MIDTERM***" &&tempnum != "***FINAL***"&&j!=tempnum){
					input >> num;
					i = 0;
					while(i<numStudents){	
						if(tempnum == stuIDNum[i]){	
							point = num * 0.2;
							stuPoints[i] = stuPoints[i] + point;
							i = numStudents+1;
						}
						else{
							i++;
						}
					}
				}
			}
		}
		else if(tempnum == "***FINAL***"){
			tempnum = " ";
			while(tempnum != "***HOMEWORK***" &&tempnum != "***MIDTERM***" &&tempnum != "***FINAL***"&&j!=tempnum){
				j = tempnum;
				input >> tempnum;
				if(tempnum != "***HOMEWORK***" &&tempnum != "***MIDTERM***" &&tempnum != "***FINAL***"&&j!=tempnum){
					input >> num;
					i = 0;
					while(i<numStudents){	
						if(tempnum == stuIDNum[i]){	
							point = num * 0.3;
							stuPoints[i] = stuPoints[i] + point;
							i = numStudents+1;
						}
						else{
							i++;
						}
					}
				}
			}
		}
		else{
			limit = 1;
		}
	}

	
	SelectSort(stuPoints,stuNames,stuLastnames,stuIDNum);

	/*
	printS(stuIDNum);
	printS(stuNames);
	printS(stuLastnames);
	printD(stuPoints);
	*/

	while(stuPoints[numStudents-1] == 0){
		numStudents--;
	}

	while(rank != 0){
		cout << "Enter the rank you want to query (enter 0 to exit): ";
		cin >> rank;
		if(rank != 0){
			if(rank >= 0 && rank <= numStudents){
				cout << rank << ", "<<  stuIDNum[rank-1] << ", " << stuNames[rank-1] << " " << stuLastnames[rank-1] << ", " << stuPoints[rank-1] << endl;
			}else{
				cout << "Rank needs to be greater than 0 and smaller than " << numStudents+1 << "!" << endl; 
			}
		}
	}

	cout << "Exiting..." << endl;
	return 0;
}