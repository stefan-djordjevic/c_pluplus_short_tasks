#include <iostream>
using namespace std;



int main(){

	cout << "Upisi datum u formatu DD MM GGGG : ";

	int dan, mesec;
	long int godina;

	cin >> dan >> mesec >> godina;

	long datum;

	if (mesec < 3){
		datum = 365 * godina + dan + 31 * (mesec - 1) + (godina - 1) / 4 - 3 * ((godina - 1) / 100 + 1) / 4;
	}
	else{
		datum = 365 * godina + dan + 31 * (mesec - 1) - static_cast<int>(0.4*mesec + 2.3) + godina / 4 - 3 * (godina / 100 + 1) / 4;
	}

	cout << dan << "." << mesec << "." << godina << ". pada u ";

	switch (datum % 7)
	{
		case 0:
			cout << "subotu." << endl;
			break;
		case 1:
			cout << "nedelju." << endl;
			break;
		case 2:
			cout << "ponedeljak." << endl;
			break;
		case 3:
			cout << "utorak." << endl;
			break;
		case 4:
			cout << "sredu." << endl;
			break;
		case 5:
			cout << "cetvrtak." << endl;
			break;
		case 6:
			cout << "petak." << endl;
			break;
		default:
			cout << "Error!" << endl;
			break;
	}
	
	std::cin.sync();	//remove any unread character from the standard input
	std::cin.ignore();	//ignore characters up to the number specified, or until the delimiter is reached (if included)
						//with no arguments, it ignore one character from the input

	//together are replacement for -- system("pause") --

	return 0;
}