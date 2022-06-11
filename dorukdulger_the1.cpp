//Doruk Dulger
#include <iostream>
#include <string>

using namespace std;


int main()
{
	double  midterm, final, the1, the2, the3, the4, wexam_avg, rec_days, ratio, the_grade, the_avg, prt_pnts, overall;
	string name;

	cout << "The purpose of this program is to calculate your CS201 grade. What is your name? ";
	cin >> name;
	cout << "Hello " << name << ", what are your midterm and final exam grades? ";
	cin >> midterm >> final;
	
	wexam_avg = (((0.33 * midterm) + (0.35 * final)) / 68) * 100;

	if(wexam_avg < 30){
		cout << name << ", your weighted exam average is less than 30, you will fail the course!" << endl;
		return 0;
	}

	cout << "What are the grades of your 4 take-home exams? ";
	cin >> the1 >> the2 >> the3 >> the4;
	the_avg = (the1 + the2 + the3 + the4)/4;
	ratio = the_avg / wexam_avg;

	if( ratio <= 2){
		the_grade =  the_avg;
		cout << "You'll get all the points earned from take-home exams!"<< endl;
	}
	else if( (2 < ratio) && (ratio < 3) ){
		the_grade =  the_avg * (3-ratio);
		cout << "You'll get " << the_grade << " from the points earned from take-home exams!"<< endl;
	}
	else if( ratio >= 3){
		the_grade = 0;
	    cout << "You'll get NONE of the points earned from take-home exams!"<< endl;
	}

	cout << "How many days have you attended recitations? ";
	cin >> rec_days;
	prt_pnts = rec_days / 13 * 100;
	overall = prt_pnts * 0.07 + the_grade * 0.25 + midterm * 0.33 + final * 0.35;

	cout << name << ", your grade for CS201 is: " << overall << endl;

	return 0;
}