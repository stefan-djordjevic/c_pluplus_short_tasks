#include <iostream>
using namespace std;


//---------------------------------------------------------------------------------------------------
//For entered number of the day of the week specify if that day is workday or weekday.

void workday_or_weekend(){

	enum day_week{
		MONDAY = 1,
		TUESDAY,
		WEDNESDAY,
		THURSDAY,
		FRIDAY,
		SATURDAY,
		SUNDAY
	};

	int num;

	cout << "Enter number of the day of the week (Monday is 1): ";
	do{
		cin >> num;
		if (num<1 || num>7) cout << "Invalid input. Please try again.\n" << endl;
	} while (num<1 || num>7);

	if (num >= MONDAY && num <= FRIDAY) cout << "\nEntered day is a workday." << endl;
	else cout << "\nEntered day is a weekday." << endl;

}