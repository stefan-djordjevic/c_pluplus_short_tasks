#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <array>
using namespace std;


//---------------------------------------------------------------------------------------------------
//primitive phonebook

void phonebook()
{
	char pbook[10][80] = {					//it can contain 10 strings with max length of 79 character (80th character is '\0')
		"Pera", "065/234-11-23",
		"Deki", "063/565-46-67",
		"Sandra", "062/325-63-43",
		"Laza", "061/345-34-53"
	};

	char str[80];

	cout << "Enter name: ";
	gets_s(str);

	int i;
	for (i = 0; i < 10; i += 2)
	{
		if (!strcmp(pbook[i], str))
		{
			cout << "\nPhone number is: " << pbook[i + 1] << endl;
			break;
		}
	}

	if (i==10)
		cout << "\nThat name doesn't exist." << endl;

}


//---------------------------------------------------------------------------------------------------
// 5 different ways to create array of strings

void arrayOfStrings_5_ways()
{
	//FIRST WAY - Using 2D array ...................................
	
	char colour[4][10] = { "Blue", "Red", "Orange", "Yellow" };			//initialize 2D array

	for (int i = 0; i < 4; i++)
	{
		cout << colour[i] << endl;
	}

	cout << endl;

	//SECOND WAY - Using pointers ..................................

	const char *pcolour[4] = { "Blue", "Red", "Orange", "Yellow" };		//initialize array of pointer

	for (int i = 0; i < 4; i++)
	{
		cout << pcolour[i] << endl;
	}

	cout << endl;

	//THIRD WAY - Using the string class ...........................

	string scolour[4] = { "Blue", "Red", "Orange", "Yellow" };			//initialize string array
																		//must include header <string>
	for (int i = 0; i < 4; i++)
	{
		cout << scolour[i] << endl;
	}

	cout << endl;

	//FOURTH WAY - Using the vector class (BEST WAY !!!)............

	vector<string> vcolour = { "Blue", "Red", "Orange" };				//declaring vector of string type
																		//must include headers <vector> and <string>
	vcolour.push_back("Yellow");										//strings can be added at any time with push_back	
	
	for (int i = 0; i < vcolour.size(); i++)							//!!!
	{
		cout << vcolour[i] << endl;
	}

	cout << endl;

	//FIFTH WAY - Using the array class ............................

	array<string, 4> acolour= { "Blue", "Red", "Orange", "Yellow" };	//initialize array
																		//must include headers <array> and <string>
																		//similar to vector, but the size is always fixed !!!
	for (int i = 0; i < 4; i++)
	{
		cout << acolour[i] << endl;
	}

	cout << endl;

}