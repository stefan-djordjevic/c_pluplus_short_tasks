#include <iostream>
#include <math.h>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;


//---------------------------------------------------------------------------------------------------
//The prime number.

void primeNumber(){

	int n;
	
	cout << "Enter a number: ";
	cin >> n;

	bool prime = true;
	for (int i = 2; i <= n/2; i++){
		if (n%i == 0) {
			prime = false;
			break;
		}
	}

	if (prime)
		cout << "\nThe number is prime." << endl;
	else
		cout << "\nThe number is composite." << endl;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Prime numbers - range.

void primeNumber_range(){

	int n;

	cout << "Enter a range of numbers: 1-";
	cin >> n;

	cout << "\nPrime numbers are:\n" << endl;

	bool prime;

	for (int i = 2; i <=n; i++){
		prime = true;
		for (int j = 2; j <= i / 2; j++){
			if (i%j == 0){
				prime = false;
				break;
			}
		}
		if (prime) cout << i << " ";
	}
	
	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Mutually prime numbers.

void mutuallyPrimeNumbers(){

	int n, m;

	cout << "Enter two numbers: " << endl;
	cin >> n >> m;

	int min;
	(n < m) ? min = n : min = m;

	bool mutprime = true;
	for (int i = 2; i <= min; i++){
		if (n%i == 0 && m%i == 0){
			mutprime = false;
			break;
		}
	}

	if (mutprime) cout << "\nNumbers are mutually prime.";
	else cout << "\nNumbers are NOT mutually prime.";

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Mutually prime numbers - range.

void mutuallyPrimeNumbers_range(){

	int n;

	cout << "Enter a range of numbers: 1-";
	cin >> n;

	cout << "\nMutually prime numbers are:" << endl;

	bool mutprime;

	for (int i = 2; i < n; i++){
		for (int j = i + 1; j <= n; j++){

			mutprime = true;

			for (int k = 2; k <= i; k++){
				if (i%k == 0 && j%k == 0){
					mutprime = false;
					break;
				}
			}

			if (mutprime) cout << i << " " << j << endl;

		}
	}

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Perfect number.

void perfectNumber(){

	int n, sum;

	cout << "*** Enter 0 to exit ***\n" << endl;

	while (1) {
		
		cout << "Enter a number: ";
		cin >> n;

		if (n == 0) exit(1);

		sum = 0;
		for (int i = 1; i <= n/2; i++){
			if (n%i == 0){
				sum += i;
			}
			if (sum > n) break;
		}

		if (sum == n) cout << "\nThe number is perfect.\n" << endl;
		else cout << "\nThe number is NOT perfect.\n" << endl;
	};

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Perfect numbers - range.

void perfectNumbers_range(){

	int n, sum;

	cout << "Enter a range of numbers: 1-";
	cin >> n;

	cout << "\nPerfect numbers are:\n\n";

	for (int i = 1; i <= n; i++){
		
		sum = 0;
		for (int j = 1; j < i; j++){
			if (i%j == 0){
				sum += j;
			}
			if (sum > i) break;
		}

		if (sum == i) cout << i << " ";
	}

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//The sum of digits of four-digit number.

void sum_of_digits(){

	int number, dig1, dig2, dig3, dig4;

	do{
		cout << "Enter a four-digit number: ";
		cin >> number;

		if (number < 1000 && number >(-1000) || number >= 10000 || number <= (-10000)) 
			cout << "That is not four-digit number. Try again.\n" << endl;

	} while (number < 1000 && number > (-1000) || number >= 10000 || number <= (-10000));

	dig1 = number % 10;
	dig2 = (number / 10) % 10;
	dig3 = (number / 100) % 10;
	dig4 = (number / 1000) % 10;
	//ovo moze u petlju while sa nizom dig[] !!!

	cout << "\nThe sum of entered number digits is: " << abs(dig1 + dig2 + dig3 + dig4) << endl;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Swap the last two digits of the number (WITH AVOIDING NON-DIGIT INPUT AND WITH ONLY INTEGER INPUT!!!)

void swap_digits(){

	int num, dig1, dig2;
	int getInteger();

	cout << "Enter a nature number: ";
	
	num = getInteger();

	while (num < 1 || num < 10){
		
		if (num < 1) cout << "Entered number is not natural. Please try again." << endl;
		else cout << "Entered number doesn't have enough digits. Please try again." << endl;
		num = getInteger();
	}

	dig1 = num % 10;
	dig2 = (num / 10) % 10;

	cout << "\nEntered number with swaped last two digits: " << (num / 100) * 100 + dig1 * 10 + dig2 << endl;

}


double getNumber(){

	double num;

	while (!(cin >> num)) {

		cin.clear();			// clear cin's error state
		cin.ignore(80, '\n');	// ignore whatever the user typed
		cout << "Only numbers are accepted. Please try again." << endl;
	}

	cin.ignore(80, '\n');		// remember to clear the input buffer

	return num;
}


int getInteger(){

	double num;
	double getNumber();

	num = getNumber();

	while (num != static_cast<int>(num)){
		
		cout << "Only integers are accepted. Please try again." << endl;
		num = getNumber();
	}

	return static_cast<int>(num);
}


//---------------------------------------------------------------------------------------------------
// Positive non-zero integer only digits input.

void positive_int_digit_input()
{
	int num;
	int getInt();

	num = getInt();

}

double getNum()
{
	double num;

	while (!(cin >> num)){

		cin.clear();
		cin.ignore(80, '\n');
		cout << "Only numbers. Try again." << endl;
	}

	cin.ignore(80, '\n');

	return num;
}


int getInt()
{
	double num;
	double getNum();

	num = getNum();

	while (num != static_cast<int>(num) || num != unsigned(num) || num == 0){

		if (num != static_cast<int>(num))
			cout << "Only integers. Try again." << endl;
		else
			cout << "Only positive non-zero numbers. Try again" << endl;

		num = getNum();
	}

	return static_cast<int>(num);
}


//---------------------------------------------------------------------------------------------------
// All divisors of the entered unsigned whole number.

void divisors_of_Number(){

	double number;

	cout << "Enter a number: ";
	do{
		cin >> number;
		if (number != static_cast<int>(number)) cout << "Only integers are accepted. Please try again.\n" << endl;
		else if (number != unsigned(number) || number == 0) cout << "Only positive non-zero numbers are accepted. Please try again.\n" << endl;
		cin.ignore(80, '\n');
	} while (number != static_cast<int>(number) || number != unsigned(number) || number == 0);			//unsigned() is for double type only !!!

	int num = static_cast<int>(number);

	cout << "\nAll divisors of the entered number are:\n" << endl;
	for (int i = 1; i <= num; i++){
		if (num%i == 0)
			cout << i << " ";
	}

}


//---------------------------------------------------------------------------------------------------
// Reverse digits in a positive number.

void reverse_Digits(){

	unsigned n;

	cout << "Enter a number: ";
	cin >> n;

	cout << "\nReversed number digits: ";

	do{
		cout << n % 10;
		n /= 10;
	} while (n>0);

}


//---------------------------------------------------------------------------------------------------
// Odd numbers.

void odd_Numbers(){

	unsigned n;

	cout << "Enter upper limit: ";
	cin >> n;

	cout << "\nOdd numbers are:\n\n" << endl;

	for (int i = 1; i < n; i += 2){
		cout << i << " ";
	}

}


//---------------------------------------------------------------------------------------------------
// Calculation x^n.

void calculation_pow_x_n(){

	double x, res;
	int n;

	cout << "Enter base: ";
	cin >> x;
	cout << "Enter exponent: ";
	cin >> n;

	res = 1;
	for (int i = 0; i < abs(n); i++){
		res *= x;
	}

	if (n >= 0)
		cout << "\nx^n is: " << res << endl;
	else
		cout << "\nx^n is: " << "1/" << res << "= " << 1.0/res << endl;

	

}


//---------------------------------------------------------------------------------------------------
// Sum of divisors of number.

void sum_of_Divisors(){

	unsigned num, d, sum;		//d - divisor

	cout << "Enter a number: ";
	cin >> num;

	sum = 0;
	for (d = 1; d*d < num; d++){
		if (num%d == 0)
			sum += d + num / d;
	}
	
	if (d*d == num)
		sum += d;

	cout << "\nSum of divisors of entered number is: " << sum << endl;

}


//---------------------------------------------------------------------------------------------------
// Prime factors of number;

void prime_Factors(){

	unsigned num;
	bool isPrime(unsigned);

	cout << "Enter a number: ";
	cin >> num;

	cout << "\nPrime factors of entered number is:\n" << endl;

	//.....With function isPrime().....
	/*
	int i = 2;
	while(i <= num){
		
		if (num%i == 0 && isPrime(i)){
			cout << i << " ";
			num /= i;
		}
		else i++;
	}
	*/

	//.....Without function isPrime().....
	int i = 2;
	while (i*i <= num){

		if (num%i == 0){
			cout << i << " ";
			num /= i;
		}
		else i++;
	}

	if (num > 1)
		cout << num;
}

bool isPrime(unsigned n){

	bool prime = true;
	for (int i = 2; i < n; i++){
		if (n%i == 0) {
			prime = false;
			break;
		}
	}

	return prime;

}


//---------------------------------------------------------------------------------------------------
// Valid number input until zero is entered.

void numbersInput_until_zero(){

	int n, count = 0;

	cout << "Enter numbers:\n-----------------------\n*to stop input enter 0*\n\n";
	
	while (1){

		while (!(cin >> n)){
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Only numbers are accepted. Please try again.\n" << endl;
		}

		if (n == 0) break;

		cin.ignore(80, '\n');

		count++;

	};

	cout << "\n" << count << " numbers are entered." << endl;

}


//---------------------------------------------------------------------------------------------------
// The longest series of successive same numbers.

void longest_series_of_sameNumbers(){

	int prevn, curn;				//previous number, current number
	int curs = 0, maxs = 0;		//current series of number, the longest (maximum) series of number 
	bool con = true;

	cout << "Enter numbers:\n-----------------------\n*to stop input enter 0*\n\n";

	cin >> prevn;
	if (prevn != 0){
		curs = maxs = 1;
	}
	else con = false;

	while (con){

		cin >> curn;
		if (curn == 0) break;

		if (curn == prevn)
			curs++;
		else
			curs = 1;

		if (maxs < curs)
			maxs = curs;

		prevn = curn;

	}

	cout << "\nThe longest series of successive same numbers is: "<< maxs << endl;

	/*
	int num, prev, count, max;
	
	bool log = true;
	
	while(1){
		cin>>num;
		
		if (num == 0) {
			cout << "Press enter to exit..." << endl;
			break;
		}
		else if (log){
			prev = num;
			count = max = 1;
			log = false;
		}
		else if (num == prev){
			count++;
			if (max < count)
				max = count;
		}
		else{
			count = 1;
			prev = num;
		}
	}

	cout << "\nMax series: " << max << endl;
	*/

}


//---------------------------------------------------------------------------------------------------
// Printing digits of entered number and calculation of the sum of digits. 

void print_digits_and_sumDigits(){

	int num, sum = 0;
	
	cout << "Enter a number: ";
	cin >> num;

	do{
		cout << num % 10 << " ";
		sum += num % 10;
		num /= 10;
	} while (num > 0);

	//using for loop
	/*
	for (sum = 0; num > 0; num /= 10)
	{
		sum += num % 10;
	}
	*/

	cout << "\nThe sum of digits of entered number is: " << sum << endl;

}


//---------------------------------------------------------------------------------------------------
// Merging numbers.

void merging_Numbers(){

	int num1, num2;

	cout << "Enter two numbers:\n";
	cin >> num1 >> num2;

	cout << "\nMerged entered numbers: " << num1 << num2 << endl;


	//.....With strings and library <cstring>..... 

	char cnum1[160], cnum2[80];

	cout << "\n\nEnter two numbers:\n";
	cin >> cnum1 >> cnum2;

	strcat_s(cnum1, cnum2);

	cout << "\nMerged entered numbers: " << cnum1 << endl;


	//.....Merged into a single number.....

	int n1 = 0, n2, temp;

	cout << "\n\nEnter two numbers:\n";
	cin >> n1 >> n2;

	temp = n2;

	while (temp > 0){
		n1 *= 10;
		temp /= 10;
	}

	n1 += n2;

	cout << "\nMerged entered numbers: " << n1 << endl;

	/*
	do{
	n1 *= 10;
	temp /= 10;
	} while (temp > 0);
	*/
}


//---------------------------------------------------------------------------------------------------
// Reverse number into new number.

void reversed_Number(){

	unsigned n, revn = 0;

	cout << "Enter a number: ";
	cin >> n;

	do{
		revn = revn * 10 + n % 10;
		n /= 10;
	} while (n>0);

	cout << "\nReversed number: " << revn << endl;

}


//---------------------------------------------------------------------------------------------------
//Throw odd digits out from entered number and create new number.

void throwing_odd_Digits(){

	unsigned num, new_num = 0, digit, level = 1;

	cout << "Enter a number: ";
	cin >> num;

	while (num > 0){

		digit = num % 10;
		num /= 10;

		if (digit % 2 == 0){
			new_num = digit * level + new_num;				// ! ! ! 
			level *= 10;
		}
	}

	cout << "\nNumber without odd digits of entered number: " << new_num << endl;

	/*
	do{
		digit = num % 10;
		if (digit % 2 == 0){
			new_num = digit * level + new_num;
			level *= 10;
		}
		num /= 10;
	} while (num > 0);
	*/
}


//---------------------------------------------------------------------------------------------------
//Create new number of entered number with a possibility to insert entered digit in entered position.

void insert_digit_into_Number(){

	unsigned num, new_num = 0, digit, new_digit, level = 1, dig_pos;

	cout << "Enter a number: ";
	cin >> num;
	cout << "Enter a digit: ";
	cin >> new_digit;
	cout << "Enter a digit position: ";
	cin >> dig_pos;

	while (dig_pos > 0){
		level *= 10;
		dig_pos--;
	}

	new_num = (num/level)*level*10 + new_digit*level + num%level;


	//..........Other way..........
	/*
	int i=0;
	while (num > 0){

		if (i == dig_pos)
			digit = new_digit;
		else
		{
			digit = num % 10;
			num /= 10;
		}

		new_num = digit * level + new_num;				// ! ! !
		level *= 10;

		i++;
	}
	*/


	cout << "\nNumber with inserted digit: " << new_num << endl;

}


//---------------------------------------------------------------------------------------------------
//Digit position manipulation - with creating new number.

void digit_position_Manipulation(){

	unsigned num, new_num = 0, level=1, temp;

	cout << "Enter a number: ";
	cin >> num;

	temp = num;
	while (temp >= 10){
		temp /= 10;
		level *= 10;
	}
	
	new_num = (num % 10) * level + ((num % level)/10)*10 + num / level;

	cout << "\nNumber with swapped first and last digits:	" << new_num << endl;


	new_num = (num%level)*10 + num / level;

	cout << "\nCyclically shifted number digits to the left:	" << new_num << endl;


	new_num = (num % 10) * level + num / 10;

	cout << "\nCyclically shifted number digits to the right:	" << new_num << endl;

}


//---------------------------------------------------------------------------------------------------
//The factorial of number.

void factorial()
{
	int num;
	cout << "Enter a number: ";
	cin >> num;

	int fact = 1;

	while (num)
	{
		fact *= num;
		num--;
	}

	cout << "\nThe factorial of the number is :" << fact << endl;
}


//---------------------------------------------------------------------------------------------------
//Swap two numbers without using third variable (temp).

void swap_numbers()
{
	int n1, n2;

	cout << "Enter first number: ";
	cin >> n1;
	cout << "Enter second number: ";
	cin >> n2;

	cout << "\nBefore swap:" << endl;
	cout << "First number = " << n1 << "\tSecond number = " << n2 << endl;

	n1 = n1 + n2;
	n2 = n1 - n2;
	n1 = n1 - n2;

	cout << "\nAfter swap:" << endl;
	cout << "First number = " << n1 << "\tSecond number = " << n2 << endl;

}


//---------------------------------------------------------------------------------------------------
//Find greatest of three numbers.

void great_of_3nums()
{
	int n1, n2, n3, big;

	cout << "Enter three numbers: ";
	cin >> n1 >> n2 >> n3;

	if (n1 > n2){
		if (n1 > n3)
			big = n1;
		else
			big = n3;
	}
	else{
		if (n2 > n3)
			big = n2;
		else
			big = n3;
	}

	cout << "\nLargest number is: " << big << endl;
}


//---------------------------------------------------------------------------------------------------
//LCM and HCF of two numbers.

void lcm_hcf()
{
	int n1, n2, lcm, hcf, mp;

	cout << "Enter two numbers: ";
	cin >> n1 >> n2;

	//LCM
	(n1 > n2) ? mp = n1 : mp = n2;

	for (int i = mp; i; i += mp)
	{
		if ((i%n1 == 0) && (i%n2 == 0)){
			lcm = i;
			break;
		}
	}

	//HCF
	(n1 < n2) ? mp = n1 : mp = n2;

	for (int i = mp; i > 0; i--)
	{
		if ((n1%i == 0) && (n2%i == 0)){
			hcf = i;
			break;
		}
	}

	cout << "\LCM = " << lcm << "\tHCF = " << hcf << endl;
}


//---------------------------------------------------------------------------------------------------
//Print Fibonacci series of N terms.

void fibonacci_series()
{
	int n;

	cout << "Enter the size of Fibonacci series: ";
	cin >> n;

	int* a = new int[n];
	
	for (int i = 0; i < n; i++){
		if (i < 2)
			a[i] = i;
		else
			a[i] = a[i - 1] + a[i - 2];
	}

	cout << "\nResult: ";
	for (int i = 0; i < n; i++){
		cout << a[i] << "  ";
	}

}


//---------------------------------------------------------------------------------------------------
//Converting decimal to binary - without using array.

void dec_to_bin()
{
	int dec, bin = 0, rem, mul = 1;

	cout << "Enter decimal number: ";
	cin >> dec;

	while (dec > 0)
	{
		rem = dec % 2;
		bin = bin + rem*mul;
		mul = mul * 10;
		dec = dec / 2;
	}

	cout << "\nEquivalent binary value: " << bin << endl;
}


//---------------------------------------------------------------------------------------------------
//Converting decimal to octal.

void dec_to_oct()
{
	int dec, oct[50];

	cout << "Enter decimal number: ";
	cin >> dec;

	int i = 0;
	while (dec > 0)
	{
		oct[i] = dec % 8;
		dec /= 8;
		i++;
	}

	cout << "\nEquivalent octal value: ";
	for (i = i-1; i >= 0; i--)
	{
		cout << oct[i];
	}

}


//---------------------------------------------------------------------------------------------------
//Converting decimal to hexadecimal.

void dec_to_hex()
{
	int dec;
	char hex[50];

	cout << "Enter decimal number: ";
	cin >> dec;

	int i = 0;
	while (dec > 0)
	{
		hex[i] = dec % 16;

		if (hex[i] < 10)
			hex[i] += 48;
		else
			hex[i] += 55;

		dec /= 16;
		i++;
	}

	cout << "\nEquivalent hexadecimal value: #";
	for (i = i - 1; i >= 0; i--)
	{
		cout << hex[i];
	}

}


//---------------------------------------------------------------------------------------------------
//Converting binary to decimal.

void bin_to_dec()
{
	int bin, dec = 0;

	cout << "Enter binary number: ";
	cin>>bin;

	int i = 0;
	while (bin)
	{
		dec = dec + ( (bin % 10) * pow(2,i) );
		i++;
		bin /= 10;
	}

	cout << "\nEquivalent decimal value: " << dec << endl;
}


//---------------------------------------------------------------------------------------------------
//Converting hexadecimal to decimal.

void hex_to_dec()
{
	char hex[50];
	int dec = 0, rem;

	cout << "Enter hexadecimal number: ";
	cin >> hex;

	int len = strlen(hex) - 1, i = 0;
	while (len >= 0)
	{
		rem = hex[len];
		if (rem >= 48 && rem <= 57)
			rem = rem - 48;
		else if (rem >= 65 && rem <= 70)
			rem = rem - 55;
		else if (rem >= 97 && rem <= 102)
			rem = rem - 87;
		else
		{
			cout << "\nInvalid Hex Digit!" << endl;
			return;
		}

		dec = dec + (rem * pow(16, i));
		len--;
		i++;
	}

	cout << "\nEquivalent decimal value: " << dec << endl;
}


//---------------------------------------------------------------------------------------------------
//Generate random numbers.

void random_numbers()
{
	int n;

	cout << "How many random numbers to generate? ";
	cin >> n;
	cout << endl;

	//we're using srand() (seed random) function to set the initial point 
	//for generating random numbers using time() function;
	//time() function is the thing that is continuouly changing its value;
	//everytime while executing this program, we'll get random numbers without repetition;
	//from library <ctime>
	srand(time(0));

	for (int i = 0; i < n; i++)
	{
		cout << rand() << endl;				//from library <cstdlib>
	}
}


//---------------------------------------------------------------------------------------------------
//Generate random numbers in given range.

void random_numbers_range()
{
	int n, first, last;

	cout << "Enter the interval [first then last]: ";
	cin >> first >> last;

	cout << "How many random numbers to generate? ";
	cin >> n;

	cout << endl;

	//we're using srand() (seed random) function to set the initial point 
	//for generating random numbers using time() function;
	//time() function is the thing that is continuouly changing its value;
	//everytime while executing this program, we'll get random numbers without repetition;
	//from library <ctime>
	srand(time(0));

	for (int i = 0; i < n; i++)
	{
		cout << rand()%(last+1-first)+first << endl;				//from library <cstdlib>
	}
}


//---------------------------------------------------------------------------------------------------
//