#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <ios>
#include <limits>
#include <sstream>
#include <map>

using namespace std;


//---------------------------------------------------------------------------------------------------
//Valid character input until point ('.'), comma (',') or end of file (EOF) is entered.

void character_Input(){

	int c;

	cout << "Enter characters:\n"<<endl;
	
	while ((c = getchar()) != '.'  && c != ',' && c != EOF)
		putchar(toupper(c));

}


//---------------------------------------------------------------------------------------------------
//Countig characters in words and sentences - C_string.

void counting_Characters(){

	//..........Word..........

	char w_str[256];

	cout << "Enter a word:\n" << endl;
	cin >> w_str;					//cin
	//cin.get(w_str, 256);
	//cin.getline(word, 80, '.');	//default terminating character is '\n'(new line)

	int i = 0;
	while (w_str[i])
		i++;

	cout << "\nNumber of word characters: " << i << endl;

	cin.ignore(256, '\n');

	//..........Sentence..........

	char s_str[256];

	cout << "\n\nEnter a sentence:\n" << endl;
	gets_s(s_str);					//gets_s()

	i = 0;
	int j = 0;

	/*while (s_str[i]){
		
		c = s_str[i];
		if (!isspace(c)) j++;		//<cctype>
		i++;

	}*/

	for (int i = 0; s_str[i]; i++){
		if (!isspace(s_str[i]))
			j++;							//<cctype>
	}

	/*
	int j = 0;
	for (int i = 0; str[i]; i++){
	if (s_str[i] != ' ')
	j++;
	}
	*/

	cout << "\nNumber of sentence characters: " << j << endl;

}


//---------------------------------------------------------------------------------------------------
//Size of "C_string" (char[]).

void size_of_C_string(){

	char str[256];

	cout << "Enter a string:\n" << endl;
	gets_s(str);

	//.....Without standard functions.....
	int i=0;
	while (str[i])
		i++;

	cout << "\n\nSize of string is: " << i << endl;


	//.....With standard library.....
	cout << "\n\nSize of string is: " << strlen(str) << endl;		//<cstring>

}


//---------------------------------------------------------------------------------------------------
//Transform uppercase to lowercase letter - C_string.

void upper_to_lowercase(){

	char str[256];

	cout << "Enter a string:\n" << endl;
	gets_s(str);

	char c;
	for (int i = 0; str[i]; i++){
		
		c = str[i];
		if (isupper(c)) c=tolower(c);			//<cctype>
		str[i] = c;
	}

	cout << "\n\nString with all lowercase:\n\n" << str << endl;
}


//---------------------------------------------------------------------------------------------------
//Correct input of email address - testing if email address characters are valid (C_string).

void input_email_Address(){

	char str[256];

	bool isAlphanumeric(char*);
	bool isLowercase(char*);

	bool alphanumeric = true;
	bool lowercase = true;

	cout << "Enter an email address: ";
	
	gets_s(str);
	alphanumeric = isAlphanumeric(str);
	lowercase = isLowercase(str);

	while ((!alphanumeric) || (!lowercase) || (strlen(str)==0)){
		
		if (!alphanumeric) cout << "Invalid email address - some characters are invalid. Please try again.\n" << endl;
		else if (!lowercase) cout << "Invalid email address - letters must be lowercase. Please try again.\n" << endl;
		else if (strlen(str) == 0) cout << "Email address is required! Please try again.\n" << endl;
		gets_s(str);
		alphanumeric = isAlphanumeric(str);
		lowercase = isLowercase(str);

	}

	if (alphanumeric && lowercase && (strlen(str) != 0)) cout << "\nEmail address is valid." << endl;
}


bool isAlphanumeric(char* astr){
	
	char c;

	bool alphanumeric = true;
	for (int i = 0; astr[i]; i++){
		c = astr[i];
		if (!(isalnum(c))){
			alphanumeric = false;
			if (c == '.' || c == '-' || c == '@')
				alphanumeric = true;
			break;
		}
	}

	return alphanumeric;
}


bool isLowercase(char* astr){
	
	char c;

	bool lowercase = true;
	for (int i = 0; astr[i]; i++){
		c = astr[i];
		if ( !(islower(c)) && (isalpha(c)) ){
			lowercase = false;
			break;
		}
	}

	return lowercase;

}

//---------------------------------------------------------------------------------------------------
//Correct input of email address - testing if email address characters are valid (C_string).
//IN OTHER WAY

void input_email_Address2()
{
	char str[80];

	bool isAlphanumericc(char*);
	bool isOnlyCharacter(char*);
	bool isFirstLastAlpha(char*);
	bool isLowercasee(char*);
	bool isEmpty(char*);

	do{
		cout << "Enter an email address: ";
		gets_s(str);
	} while (!isAlphanumericc(str) || isOnlyCharacter(str) || !isFirstLastAlpha(str) || !isLowercasee(str) || isEmpty(str));

	if (isAlphanumericc(str) && !isOnlyCharacter(str) && isFirstLastAlpha(str) && isLowercasee(str) && !isEmpty(str)) cout << "\nEmail address is valid." << endl;
}

bool isAlphanumericc(char* str)
{
	bool alphanumeric = true;

	for (int i = 0; str[i]; i++)
	{
		if (!(isalnum(str[i])) && str[i] != '.' && str[i] != '-' && str[i] != '@'){
			alphanumeric = false;
			cout << "Invalid email address - some characters are not allowed. Please try again.\n" << endl;
			break;
		}
	}

	return alphanumeric;
}

bool isOnlyCharacter(char* str)
{
	bool onlyCharacter = true;

	for (int i = 0; str[i]; i++)
	{
		if (isalnum(str[i])){
			onlyCharacter = false;
			break;
		}
	}
	if (strlen(str) == 0) onlyCharacter = false;

	if (onlyCharacter) cout << "Invalid email address - must contains alphanumeric character. Please try again.\n" << endl;

	return onlyCharacter;
}

bool isFirstLastAlpha(char* str)
{
	bool flAlpha = true;

	if ((!isalpha(str[0]) || !isalnum(str[strlen(str) - 1])) && strlen(str) != 0){
		flAlpha = false;
		cout << "Invalid email address - first character must be letter and last alphanumeric. Please try again.\n" << endl;
	}

	return flAlpha;
}

bool isLowercasee(char* str)
{
	bool lowercase = true;

	for (int i = 0; str[i]; i++)
	{
		if (isupper(str[i]) && isalpha(str[i])){
			lowercase = false;
			cout << "Invalid email address - letters must be lowercase. Please try again.\n" << endl;
			break;
		}
	}

	return lowercase;
}

bool isEmpty(char* str)
{
	bool empty = false;

	if (strlen(str) == 0){
		empty = true;
		cout << "Email address is required. Please try again.\n" << endl;
	}

	return empty;
}


//---------------------------------------------------------------------------------------------------
//Only alphanumeric input - C_string.

void alphanumeric_Input(){

	char str[256];
	char c;
	
	cout << "Enter string:\n" << endl;

	do{
		gets_s(str);
		for (int i = 0; str[i]; i++){
			c = str[i];
			if (!isalnum(c)){
				cout << "Only alphanumeric character is accepted. Please try again.\n" << endl;
				break;
			}
		}
	} while (!isalnum(c));

	if (isalnum(c)) cout << "\nInput is valid." << endl;

}


//---------------------------------------------------------------------------------------------------
//Copy string - C_string.

void copy_string(){

	char str[256], cstr[256];

	cout << "Enter string:" << endl;
	gets_s(str);


	//.....without standard functions.....

	for (int i = 0; cstr[i] = str[i]; i++);

	/*
	int i = 0;
	while (cstr[i] = str[i])
		i++;
	*/

	cout << "\nCopy string is:\n" << cstr << endl;


	//.....with standard library.....

	strcpy_s(cstr, str);			//<cstring>

	cout << "\nCopy string is:\n" << cstr << endl;


}


//---------------------------------------------------------------------------------------------------
//Valid character input until point ('.') is entered. Input the number of each digit impressions in array[10].

void numbers_of_Digits(){

	
	char c;
	int arr[10];

	for (int i = 0; i < 10; i++)
		arr[i] = 0;

	cout << "Enter string:\n" << endl;

	while ((c = getchar()) != '.'){
		if (c >= '0' && c <= '9')
			arr[c - '0']++;					//ASCII table
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";

}


//---------------------------------------------------------------------------------------------------
//Detecting when ENTER key is pressed.

void enter_input_Detect(){

	cout << "Press the ENTER key\n" << endl;
	if (cin.get() == '\n')												//getchar();
		cout << "The ENTER key is pressed. Good job!\n";
	else 
		cout << "Something is entered. I meant ONLY the ENTER key.\n";
	

}


//---------------------------------------------------------------------------------------------------
//Palindrome check - C_string.

void palindrome(){

	char str[256];

	do{
		cout << "Enter a sentence: ";
		gets_s(str);
		if (strlen(str) == 0) cout << "The sentence input is required. Try again.\n" << endl;
	} while (strlen(str) == 0);

	int k = 0;
	for (int i = 0; i <= strlen(str); i++){			//for (int i = 0; str[i]; i++){		
		if (!isspace(str[i])){
			str[k] = tolower(str[i]);
			k++;
		}
	}
										
	//str[k] = '\0';

	int i, j;
	bool con = true;
	for (i = 0, j = strlen(str)-1; i < j; i++, j--){
		
		if (str[i] != str[j]){
			cout << "\nSentece is NOT a palindrome." << endl;
			con = false;
			break;
		}
	}

	if (con) cout << "\nSentence is a palindrome." << endl;

}


//---------------------------------------------------------------------------------------------------
//Reverse entered string - C_string.

void reversed_String(){

	char str[256], temp;

	cout << "Enter a string: ";
	gets_s(str);

	int i, j;
	for (i = 0, j = strlen(str) - 1; i < j; i++, j--){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}

	cout << "Reversed entered string: " << str << endl;

}


//---------------------------------------------------------------------------------------------------
//Lexicographic comparison of two strings - like std function strcmp().

void lexicographic_comparison(){

	char str1[256], str2[256];

	cout << "Enter a string 1: ";
	gets_s(str1);

	cout << "\nEnter a string 2: ";
	gets_s(str2);

	int i, result = 1;

	for (i = 0; str1[i] == str2[i]; i++){
		if (str1[i] == '\0'){
			result = 0;
			break;
		}
	}
	
	if (result) 
		result = str1[i] - str2[i];


	if (result < 0)
		cout << "\nThe first string lexicographically precedes the second string." << endl;
	else if (result > 0)
		cout << "\nThe second string lexicographically precedes the first string." << endl;
	else
		cout << "\nStrings are lexicographically the same." << endl;

}


//---------------------------------------------------------------------------------------------------
// Testing if one string contains second string like substring - characters must be consecutive.
//***like std function strstr()
//There is a better way than this!

void consecutive_Substring(){

	char str[256], substr[256];

	cout << "Enter the first string: ";
	gets_s(str);

	cout << "\nEnter the second string: ";
	gets_s(substr);

	int i, j;
	bool sub = false;
	int temp = -1;

	for (i = 0; str[i]; i++){
		for (j = 0; substr[j] == str[i + j]; j++);
		
		if (substr[j] == '\0'){
			sub = true;
			temp = i;
			break;
		}

	}

	if (sub) cout << "\nThe second string is a consecutive substring of the first string.\n--- From the position: " << temp << endl;
	else cout << "\nThe second string is NOT a consecutive substring of the first string." << endl;

}


//---------------------------------------------------------------------------------------------------
// Testing if one string contains second string like substring - characters don't need to be consecutive, but must be in the same order.

void same_order_Substring(){

	char str[256], substr[256];

	cout << "Enter the first string: ";
	gets_s(str);

	cout << "\nEnter the second string: ";
	gets_s(substr);
	

	int i, j;
	bool sub = false;

	for (i = 0, j = 0; str[i]; i++){
		if(str[i] == substr[j]){
			j++;
		}
		if (substr[j] == '\0') sub = true;
	}

	/*
	int i, j;
	bool sub = true;
	for (i = 0, j = 0; substr[i]; i++){
		while(substr[i] != str[j]){
			if (str[j] == '\0'){
				sub = false;
				break;
			}
			j++;
		}
		if (!sub) break;
	}
	*/

	if (sub) cout << "\nThe second string is substring (in the same order) of the first string." << endl;
	else cout << "\nThe second string is NOT substring (in the same order) of the first string." << endl;

}


//---------------------------------------------------------------------------------------------------
//Clearing the input buffer - C/C++_string.

void clear_buffer()
{
	int a;
	char str[80];
	void output_text();

	//via cin.ignore()
	output_text();

	cin >> a;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');		//discards the input buffer
																//must include headers <ios> and <limits> 
	cin.getline(str, 80);

	cout << a << endl;
	cout << str << endl;


	//via cin.sync()
	output_text();

	cin >> a;
	
	cin.sync();					//discards the input buffer

	cin.getline(str, 80);

	cout << a << endl;
	cout << str << endl;

	//via <vector> and ws
	output_text();

	string s;

	cin >> a;

	cin >> ws;					//discards the input buffer and initial white spaces of string
								//must include header <vector>
	getline(cin, s);			//from header file <string>

	cout << a << endl;
	cout << s << endl;
}

void output_text()
{
	cout << "\nEnter number then string:" << endl;
}


//---------------------------------------------------------------------------------------------------
//For entered character find its type (via ASCII table)

void character_type()
{
	char ch;

	cout << "Enter a character: ";
	cin >> ch;

	if (ch >= 48 && ch <= 57)
		cout << "\nYou entered a digit.";
	else if (ch >= 65 && ch <= 90)
		cout << "\nYou entered an uppercase letter.";
	else if (ch >= 97 && ch <= 122)
		cout << "\nYou entered an lowercase letter.";
	else
		cout << "\nYou entered a special character.";

	//in other way
	if (ch >= '0' && ch <= '9')
		cout << "\nYou entered a digit.";
	else if (ch >= 'A' && ch <= 'Z')
		cout << "\nYou entered an uppercase letter.";
	else if (ch >= 'a' && ch <= 'z')
		cout << "\nYou entered an lowercase letter.";
	else
		cout << "\nYou entered a special character.";

}


//---------------------------------------------------------------------------------------------------
//Find a character position in the string - C string.

void character_position()
{
	char ch, str[80];

	cout << "Enter a string: ";
	cin.getline(str, 80);

	cin.sync();

	cout << "Enter a character to be searched for: ";
	cin.get(ch);

	bool find_pos(char[], char);

	if (!find_pos(str, ch))
	{
		cout << "Sorry! Character not found in the string." << endl;
		cout << "Press any key to exit..." << endl;
	}

}

bool find_pos(char str[], char ch)
{
	bool flag = false;
	int count = 0;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ch)
		{
			if (count == 0)
			{
				cout << "\nThe character is in the string at position:\n" << i + 1;
				count++;
			}
			else
			{
				cout << ", " << i + 1;
			}
			flag = true;
		}
	}
	return flag;
}


//---------------------------------------------------------------------------------------------------
//All input like string via stringstream - C++ string

void input_num_like_str()
{
	string str;											//string object from class string, header file <string>
	float price = 0;

	cout << "Enter price: ";
	getline(cin, str);
	stringstream(str) >> price;							//string object str like input stream enabled via constructor of class stringstream
														//put only that part until white space in string str to string price
														//it's normal because it's used operator >> 
														//with stringstream s(str) and getline(s, price) can be used the whole string str
														//from header <sstream>
	cout << "\nEntered price: " << price << endl;
}


//---------------------------------------------------------------------------------------------------
//Count number of words in a string (via stringstream) - C++ string

void count_words()
{
	string str, word;
	int count=0;

	cout << "Enter a string:" << endl;
	getline(cin, str);

	stringstream s(str);						//string object str like input stream s enabled via class stringstream
												//explanation in task above 
												//from header <sstream>
	while (s >> word)
	{
		count++;
		cout << "\n" << word;
	}

	cout << "\n\nNumber of words are: " << count;
}


//---------------------------------------------------------------------------------------------------
//Count frequencies of words in a string (via stringstream and map<>) - C++ string

void frequencies_of_words()
{
	string str, word;

	cout << "Enter a string:" << endl;
	getline(cin, str);

	stringstream s(str);						//string object str like input stream s enabled via class stringstream
												//explanation in task above 
												//from header <sstream>
	
	map<string, int> FW;						//class map<> from header <map> !!!!!!

	while (s >> word){
		FW[word]++;
	}

	map<string, int>::iterator it;

	for (it = FW.begin(); it != FW.end(); it++)
	{
		cout << it->first << " -> " << it->second << endl;
	}

}


//---------------------------------------------------------------------------------------------------
//Removing spaces from a string using stringstream (in two ways) - C++ string

void remove_spaces()
{
	//FIRST WAY - using EOF ................................
	string str, temp;
	stringstream ss;

	cout << "Enter a string:" << endl;
	getline(cin, str);

	ss << str;					//storing the whole string str into strin stream ss

	str = "";					//making the stream str empty

	while (!ss.eof())			//running loop till end of stream ss
	{
		ss >> temp;				//extracting word by word from stream

		str = str + temp;		//concatenating in the string
	}

	cout << "\n" << str;

	//SECOND WAY - using getline() ...........................
	string strng, word;

	cout << "\n\nEnter a string:" << endl;
	getline(cin, strng);

	stringstream sst(strng);	//storing the whole string strng into string stream sst 

	strng = "";
	
	while (getline(sst, word, ' ' ))
	{
		strng = strng + word;
	}

	cout << "\n" << strng;

}


//---------------------------------------------------------------------------------------------------
//Concatenate two strings - in 4 ways (C/C++ string).

void concatenate_strings()
{
	char s1[256], s2[128];

	cout << "Enter the first string: ";
	gets_s(s1);
	cout << "Enter the second string: ";
	gets_s(s2);

	//1. way - manualy.................................
	int i;
	for (i = 0; s1[i]; i++);
	for (int j = 0; s2[j]; j++)
	{
		s1[i++] = s2[j];
	}
	s1[i] = '\0';

	cout << "\nString after concatenation: " << s1 << endl;

	i = 0;
	cin.sync();

	//2. way - using strcat()..........................
	cout << "\nEnter the first string: ";
	gets_s(s1);
	cout << "Enter the second string: ";
	gets_s(s2);

	strcat_s(s1, s2);				//from library <cstring>

	cout << "\nString after concatenation: " << s1 << endl;

	cin.sync();

	//3. way - using pointers..........................
	cout << "\nEnter the first string: ";
	gets_s(s1);
	cout << "Enter the second string: ";
	gets_s(s2);

	char *ps1 = s1;
	char *ps2 = s2;

	while (*ps1)
		ps1++;
	while (*ps2)
	{
		*ps1 = *ps2;
		ps1++;
		ps2++;
	}
	*ps1 = '\0';

	cout << "\nString after concatenation: " << s1 << endl;

	cin.sync();

	//4. way - using class <string> and + operator......
	string str1 = "", str2 = "";			//from <string> library
	
	cout << "\nEnter the first string: ";
	getline(cin, str1);						//from <string> library
	cout << "Enter the second string: ";
	getline(cin, str2);

	str1 = str1 + str2;

	cout << "\nString after concatenation: " << str1 << endl;

	cin.sync();

}


//---------------------------------------------------------------------------------------------------
//Frequency of all character in string - C_string.

void character_frequency()
{
	char str[256];

	cout << "Enter the first string: ";
	gets_s(str);

	int n = strlen(str);
	int freq = 0;
	char ch;

	cout << "\nCharacter\tFrequency\tRemaining String" << endl;

	int i, j, k;
	for (i = 0; i < n; i++)
	{
		ch = str[i];
		for (j = 0; j < n; j++)
		{
			if (ch == str[j])
			{
				freq++;
				for (k = j; k < n - 1; k++)
					str[k] = str[k + 1];
				n--;
				str[n] = '\0';
				j--;
			}
		}
		cout << endl << ch << "\t\t" << freq << "\t\t" << str;
		freq = 0;
		i--;
	}
}