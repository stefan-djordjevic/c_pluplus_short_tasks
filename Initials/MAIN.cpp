#include <iostream>
using namespace std;

#include <string>

int main(){

	cout << "Please, enter your first name followed by your surname: ";

	char first, last;

	first = cin.get();
	cin.ignore(256, ' ');	//ignore all other characters until space

	last = cin.get();

	cout << "Your initials are: " << first << last<<'\n';

	//-----------------------------------------------------------------------------
	//the other way - with string 

	cin.sync();

	cout << "Please, enter your first name followed by your surname: ";

	string name, surname;

	cin >> name >> surname;

	cout << "Your initials are: " << name[0] << surname[0];



	cin.sync();
	cin.ignore();

	return 0;
}