#include <iostream>
#include <string>

using namespace std;

bool inputCheck(double  weight, double speed,double minute);
double calculateMET(double speed, string exercise);
void displayResults(double difference,double total,double weight,double Wmet,double Rmet,double Cmet,double calW,double calR,double calC);
void computeResults(double weight,double Wspeed,double Rspeed,double Cspeed,double Wmin,double Rmin,double Cmin,double goal);

void getInput(string username){
	double  weight, Wspeed, Rspeed, Cspeed, Wmin, Rmin, Cmin, goal; 
	cout << "Welcome "<< username << ", please enter your weight(kg): " ;
	cin >> weight;
	cout << username << ", please enter speed(km/h) and minutes spent in a week for the activities below." << endl;
	cout << "Walking: ";
	cin >> Wspeed >> Wmin;
	cout << "Running: ";
	cin >> Rspeed >> Rmin;
	cout << "Cycling: ";
	cin >> Cspeed >> Cmin;
	cout << username << ", please enter your weekly calorie burn goal: " ;
	cin >> goal;
	if(inputCheck(weight, Wspeed, Wmin)){
		if(inputCheck(weight, Rspeed, Rmin)){
		   if(inputCheck(weight, Cspeed, Cmin)){
			   computeResults(weight, Wspeed, Rspeed, Cspeed, Wmin, Rmin, Cmin, goal);
	}
	}
	}
}

bool inputCheck(double weight, double speed,double minute) {
	if (weight < 30){
		cout << "Weight out of range!" << endl;
		return false;
	}
	else if ((speed < 4) || (speed > 30)){
		cout << "Speed out of range!" << endl;
		return false;
	}
	else if ((minute < 0) || (minute > 2000)){
		cout << "Minute out of range!" << endl;
		return false;
	}
	return true;
}

double calculateMET(double speed, string exercise){
	if(exercise == "Walking"){
		if((speed >= 4) && (speed < 6.5)){
			return 4;
		}
		else{
			return 6.5;
		}
	}
	else if(exercise == "Running"){
		if((speed >= 4) && (speed < 11)){
			return 9;
		}
		else{
			return 12.5;
		}
	}
	else{
		if((speed >= 4) && (speed < 20)){
			return 6;
		}
		else if((speed >= 20) && (speed < 25)){
			return 8;
		}
		else{
			return 10.5;
		}
	}
}

void computeResults(double weight,double Wspeed,double Rspeed,double Cspeed,double Wmin,double Rmin,double Cmin,double goal){
	double Wmet, Rmet, Cmet, calW, calR, calC, difference, total;
	Wmet = calculateMET(Wspeed, "Walking");
	Rmet = calculateMET(Rspeed, "Running");
	Cmet = calculateMET(Cspeed, "Cycling");
	calW = weight * Wmet * (Wmin / 60);
	calR = weight * Rmet * (Rmin / 60);
	calC = weight * Cmet * (Cmin / 60);
	total = calW + calR + calC;
	difference = goal - total;
	displayResults(difference, total, weight, Wmet, Rmet, Cmet, calW, calR, calC);
}

void displayResults(double difference,double total,double weight,double Wmet,double Rmet,double Cmet,double calW,double calR,double calC){
	cout << "From walking, you burned " << calW << " calories." << endl;
	cout << "From running, you burned " << calR << " calories." << endl;
	cout << "From cycling, you burned " << calC << " calories." << endl;
	cout << "You burned " << total << " calories." << endl;
	if (difference < 0){
		difference *= -1;
		cout << "You have surpassed your goal! You can eat something worth "<< difference << " calories :)" << endl;
	}
	else if (difference == 0){
		cout << "Congratulations! You have reached your goal!" << endl;
	}
	else if (difference > 0){
		cout << "You did not reach your goal by " << difference << " calories." << endl;
		cout << "You need to walk " << difference / (weight * Wmet) * 60 << " minutes more to reach your goal or," << endl <<
"You need to run " << difference / (weight * Rmet) * 60 << " minutes more to reach your goal or," << endl <<
"You need to do cycling "<< difference / (weight * Cmet) * 60 <<" minutes more to reach your goal." << endl;
	}
}

int main(){
	string username,username2;

	cout << "Please enter your name: " ;
	cin >> username;
	getInput(username);
	cout << endl;
	cout << "Please enter your name: " ;
	cin >> username2;
	getInput(username2);



	return 0;
}