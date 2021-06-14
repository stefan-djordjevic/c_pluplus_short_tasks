#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//----------------------------------------------------------------------------------
//Create and open a file with function open(). 

void example_2_Open(){

	ofstream myfile;

	myfile.open("Example_2_Open.txt");

	myfile << "This text file is from the function example_2_Open.\n";
	myfile << "This is the second line.\n";

	myfile.close();

}


//----------------------------------------------------------------------------------
//Open function with its modes.

void example_2_open_with_Modes(){

	ofstream myfile;

	myfile.open("Example_2_Open.txt", ios::out | ios::app);

	myfile << "This line is from the function example_2_open_with_Modes.\n";
	myfile << "This line is from the function example_2_open_with_Modes.\n";

	myfile.close();

	//  .....MODE...................................................................................................................................
	//	ios::in		 Open for input operations.
	//	ios::out	 Open for output operations.
	//	ios::binary	 Open in binary mode.
	//	ios::ate	 Set the initial position at the end of the file. If this flag is not set, the initial position is the beginning of the file.
	//	ios::app	 All output operations are performed at the end of the file, appending the content to the current content of the file.
	//	ios::trunc	 If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
	//  ............................................................................................................................................

}


//----------------------------------------------------------------------------------
//Create and open a file with modes. Use the function is_open().

void example_2_ofstream_with_Modes(){

	ofstream myfile("Example_2_Open.txt", ios::out | ios::app);

	if (myfile.is_open()){
		
		myfile << "Create and open file by ofstream with modes.\n";
		myfile.close();
	}
	else cout << "Unable to open a file." << endl;

}


//----------------------------------------------------------------------------------
//Reading from a file.

void example_2_Read(){

	string line;

	ifstream myfile("Example_2_Open.txt");

	if (myfile.is_open()){

		while (getline(myfile, line)){
			cout << line << endl;
		}

		myfile.close();

	}
	else cout << "Unable to open a file." << endl;

}


//----------------------------------------------------------------------------------
//Reading from a file. Use a checking state flags.

void example_2_Flags(){

	string line;

	ifstream file("Example_2_Open.txt");
	//ifstream file;						//for testing else statement

	if (file.is_open()){

		while (!file.eof()){
			getline(file, line);
			cout << line << endl;
		}

		file.close();
		file.clear();						//reset the state flags !!!

	}
	else cout << "Unable to open a file." << endl;

	//  .....CHECKING STATE FLAGS.................................................................................................................
	//  bad()		Returns true if a reading or writing operation fails.For example, in the case that we try to write to a file that is not open 
	//  			for writing or if the device where we try to write has no space left.
	//  fail()		Returns true in the same cases as bad(), but also in the case that a format error happens, like when an alphabetical character 
	//  			is extracted when we are trying to read an integer number.
	//  eof()		Returns true if a file open for reading has reached the end.
	//  good()		It is the most generic state flag : it returns false in the same cases in which calling any of the previous functions would 
	//  			return true.Note that good and bad are not exact opposites(good checks more state flags at once).
	//  ..........................................................................................................................................

}


//----------------------------------------------------------------------------------
//Size of a binary file. Get and put stream positioning.

void example_2_size_of_BinaryFile(){

	streampos begin, end;

	fstream binfile("Example_2_Binary.bin", ios::binary);

	begin = binfile.tellg();
	binfile.seekg(0, ios::end);
	end = binfile.tellg();								//return a value of the member type streampos, which is a type representing the current 
														//get position (in the case of tellg) or the put position (in the case of tellp).
	binfile.close();

	cout << "Size of a binary file is: " << end - begin << " bytes." << endl;

	//  .....SEEKG/SEEKP..............................................................................................................................
	//  seekg(offset, direction);
	//  seekp(offset, direction);
	//  Using this prototype, the get or put position is set to an offset value relative to some specific point determined by the parameter direction.
	//	offset is of type streamoff.And direction is of type seekdir, which is an enumerated type that determines the point from where offset is 
	//	counted from, and that can take any of the following values:
	//		ios::beg	offset counted from the beginning of the stream
	//		ios::cur	offset counted from the current position
	//		ios::end	offset counted from the end of the stream
	//  ..............................................................................................................................................

}