#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//----------------------------------------------------------------------------------
//Create and open a text file. Write to the file.

void example_1_Write(){

	ofstream myFile("Example_1.txt");				//create and open a text file

	myFile << "My first writting to the file.";		//write  to the file

	myFile.close();									//close the file

}


//----------------------------------------------------------------------------------
//Read the file and output the text from the file.

void example_1_Read(){

	string str;

	ifstream myReadFile("Example_1.txt");			//open existing text file

	while (getline(myReadFile, str)){				//reading the file line by line
		cout << str;
	}

	myReadFile.close();

}


