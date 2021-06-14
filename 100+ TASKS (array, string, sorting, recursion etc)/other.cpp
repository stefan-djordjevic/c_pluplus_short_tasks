#include <iostream>
#include <math.h>

using namespace std;


//---------------------------------------------------------------------------------------------------
//Remaining time to midnight.

void time_until_midnight(){

	int h, m, s, hdifference, mdifference, sdifference;

	cout << "Enter time[24] - h:m:s = ";
	
	do{
		scanf_s("%d:%d:%d", &h, &m, &s);

		if (h < 0 || h>23) cout << "The hours value is not allowed. Try again.\n" << endl;
	
		if (m < 0 || m>59) cout << "The minuts value is not allowed. Try again.\n" << endl;

		if (s < 0 || s>59) cout << "The seconds value is not allowed. Try again.\n" << endl;

	} while (h < 0 || h>23 || m < 0 || m>59 || s < 0 || s>59);

	hdifference = 23 - h;
	mdifference = 59 - m;
	sdifference = 60 - s;

	if (sdifference == 60){
		sdifference = 0;
		mdifference++;
	}

	if (mdifference == 60){
		mdifference = 0;
		hdifference++;
	}

	cout << "\nThe remaining time until midnight is " << hdifference << ":" << mdifference << ":" << sdifference << endl;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Testing if is possible to make a triangle of three entered lengths.

void possible_triangle(){

	double x, y, z;
	cout << "Enter three lengths:" << endl;
	cin >> x >> y >> z;

	if (x > 0 && y > 0 && z > 0 && x + y > z && x + z > y && y + z > x)
		cout << "\nTriangle is possible for entered lengths." << endl;
	else cout << "\nTriangle is NOT possible for entered lengths." << endl;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Calculating the solution of the equation Ax+B=0.

void linear_Equation(){

	double a, b;

	cout << "Enter coefficients A and B of the equation Ax + B = 0:\n" << endl;
	cout << "A= ";
	cin >> a;
	cout << "B= ";
	cin >> b;

	if (a != 0)
		cout << "\nThe equation has unique solution: x= " << (-b / a) << endl;
	else if (b == 0)
		cout << "\nEvery real number satisfies the equation." << endl;
	else
		cout << "\nThe equation doesn't have solutions." << endl;

}


//---------------------------------------------------------------------------------------------------
//Calculating solutions of the system of equations: A1x+B1y=C1, A2x+B2y=C2.

void system_of_linear_Equations(){

	double a1, b1, c1, a2, b2, c2;	//system coefficients
	double Dx, Dy, D;				//determinants

	cout << "Enter coefficients of the system of equations: A1x+B1y=C1, A2x+B2y=C2:\n";
	cout << "A1 B1 C1: ";
	cin >> a1 >> b1 >> c1;
	cout << "A2 B2 C2: ";
	cin >> a2 >> b2 >> c2;

	D = a1*b2 - b1*a2;
	Dx = c1*b2 - b1*c2;
	Dy = a1*c2 - c1*a2;

	if (D != 0){
		cout << "\nThe system has unique solutions:\n" << endl;
		cout << "x= " << Dx / D << endl;
		cout << "y= " << Dy / D << endl;
	}
	else if (Dx == 0 && Dy == 0)
		cout << "\nThe system has infinitely many solutions." << endl;
	else
		cout << "\nThe system doesn't have solutions." << endl;

}


//---------------------------------------------------------------------------------------------------
//Calculating real solutions of the quadratic equation: Ax^2+Bx+C=0.

void quadratic_Equation(){

	double a, b, c;		//a!=0 !!!
	double D;			//discriminant

	cout << "Enter coefficients of the quadratic equation Ax^2 + Bx + C = 0:\n" << endl;
	do{
		cout << "A B C: ";
		cin >> a >> b >> c;
		if (a==0) cout << "'A' must be non-zero. Please try again.\n" << endl;
	} while (a==0);

	D = b*b - 4*a*c;

	if (D > 0){
		cout << "\nReal solutions are:\n" << endl;
		cout << "x1= " << (-b + sqrt(D)) / (2 * a) << endl;
		cout << "x2= " << (-b - sqrt(D)) / (2 * a) << endl;
	}
	else if (D == 0)
		cout << "\nThe unique real solution is:\nx= " << -b / (2 * a) << endl;
	else
		cout << "\nThe equation doesn't have real solutions." << endl;

}


//---------------------------------------------------------------------------------------------------
//For date input specify which day it is in order of the year.

void day_in_order_of_Year(){

	int day, month, year, sum_days;
	int daysNum_Month(int, int);

	cout << "Enter a date in format dd/mm/yyyy: ";
	do{
		scanf_s("%d/%d/%d", &day, &month, &year);
		if (year < 0) cout << "Invalid input for a year. Please try again.\n" << endl;
		if (month < 1 || month > 12) cout << "Invalid input for a month. Please try again.\n" << endl;
		if (day < 1 || day > daysNum_Month(month, year)) cout << "Invalid input for a day. Please try again.\n" << endl;

	} while (year < 0 || month < 1 || month > 12 || day < 1 || day > daysNum_Month(month, year));


	sum_days = 0;

	for (int i = 1; i < month; i++)
		sum_days += daysNum_Month(i, year);

	sum_days += day;

	cout << "\nNumber of days of the year until "<< day <<"/"<< month <<"/"<< year << " is: " << sum_days;

}


int daysNum_Month(int m, int y){

	int days_number[][13] = {
			{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
			{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
	};

	int leap_year = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;		//result 0 or 1 !!!

	return days_number[leap_year][m];
}


//---------------------------------------------------------------------------------------------------
//Multiplication table.

void multiplication_Table(){

	const int n = 10;
	int res;

	cout << "\n---------------------------- MULTIPLICATION TABLE ----------------------------\n\n" << endl;

	for (int i = 1; i <= n; i++){
		for (int j = 0; j < n; j++){
			res = i*j;
			cout << j << "*" << i << "=" << res;
			if (res < 10 && i < 10) cout << "   ";
			else if (res > 9 && i == 10) cout << " ";
			else cout << "  ";
		}
		cout << endl;
	}

}


//---------------------------------------------------------------------------------------------------
//Operations with fractions.

struct fraction{
	int numerator;
	int denominator;
};

void operations_with_Fractions(){

	int a, b, c, d;

	enum operation{ EXIT, ADD, SUBTRACT1, SUBTRACT2, MULTIPLY, DIVIDE1, DIVIDE2, SIMPLIFY1, SIMPLIFY2 };

	fraction create_Fraction(int, int);
	fraction add_Fractions(fraction, fraction);
	fraction subtract_Fractions(fraction, fraction);
	fraction multiply_Fractions(fraction, fraction);
	fraction divide_Fractions(fraction, fraction);
	fraction simplify_Fraction(fraction);

	cout << "--- Fraction input format is 'x/y' ---\n" << endl;
	
	do{
		cout << "Enter a fraction a/b: ";
		scanf_s("%d/%d", &a, &b);
		if (b == 0) cout << "Denominator value is not allowed. Please try again.\n" << endl;
	} while (b == 0);
	do{
		cout << "\nEnter a fraction c/d: ";
		scanf_s("%d/%d", &c, &d);
		if (d == 0) cout << "Denominator value is not allowed. Please try again.\n" << endl;
	} while (d == 0);

	fraction ab = create_Fraction(a, b);
	fraction cd = create_Fraction(c, d);
	fraction result = {0, 0};

	int choise;
	
	cout << "\n\nChoose one of the operations:\n" << endl;
	cout << "  1 Addition" << endl;
	cout << "  2 Subtract a/b - c/d" << endl;
	cout << "  3 Subtract c/d - a/b" << endl;
	cout << "  4 Multiplication" << endl;
	cout << "  5 Division a/b / c/d" << endl;
	cout << "  6 Division c/d / a/b" << endl;
	cout << "  7 Simplification a/b" << endl;
	cout << "  8 Simplification c/d" << endl;
	cout << "  0 Exit\n" << endl;
	
	do{
		
		cout << "--- ";
		cin >> choise;

		switch (choise){

		case ADD:
			result = add_Fractions(ab, cd);
			result = simplify_Fraction(result);
			break;

		case SUBTRACT1:
			result = subtract_Fractions(ab, cd);
			result = simplify_Fraction(result);
			break;

		case SUBTRACT2:
			result = subtract_Fractions(cd, ab);
			result = simplify_Fraction(result);
			break;

		case MULTIPLY:
			result = multiply_Fractions(ab, cd);
			result = simplify_Fraction(result);
			break;

		case DIVIDE1:
			result = divide_Fractions(ab, cd);
			result = simplify_Fraction(result);
			break;

		case DIVIDE2:
			result = divide_Fractions(cd, ab);
			result = simplify_Fraction(result);
			break;

		case SIMPLIFY1:
			result = simplify_Fraction(ab);
			break;

		case SIMPLIFY2:
			result = simplify_Fraction(cd);
			break;

		case EXIT:
			exit(-1);

		default:
			cout << "This option doesn't exist. Please try again.\n" << endl;
		}

	} while (choise < 0 || choise > 8);

	
	cout << "\nOperation result is: " << result.numerator << "/" << result.denominator << endl;

}

fraction create_Fraction(int num, int den){
	
	fraction res_fraction;
	
	res_fraction.numerator = num;
	res_fraction.denominator = den;
	
	return res_fraction;
}

fraction add_Fractions(fraction f1, fraction f2){

	fraction res;

	res.numerator = f2.denominator*f1.numerator + f1.denominator*f2.numerator;
	res.denominator = f1.denominator * f2.denominator;

	return res;
}

fraction subtract_Fractions(fraction f1, fraction f2){

	fraction res;

	res.numerator = f2.denominator*f1.numerator - f1.denominator*f2.numerator;
	res.denominator = f1.denominator * f2.denominator;

	return res;
}

fraction multiply_Fractions(fraction f1, fraction f2){

	fraction res;

	res.numerator = f1.numerator * f2.numerator;
	res.denominator = f1.denominator * f2.denominator;

	return res;
}

fraction divide_Fractions(fraction f1, fraction f2){

	fraction res;

	res.numerator = f1.numerator * f2.denominator;
	res.denominator = f1.denominator * f2.numerator;

	return res;
}

fraction simplify_Fraction(fraction f){

	fraction res = {0, 0};

	int a, b, min, max_divisor=1;

	a = abs(f.numerator);
	b = abs(f.denominator);

	min = (a < b) ? a : b;

	for (int i = 2; i <= min; i++){
		if (a%i == 0 && b%i == 0){
			if (max_divisor < i)
				max_divisor = i;
		}
	}

	res.numerator = f.numerator / max_divisor;
	res.denominator = f.denominator / max_divisor;

	return res;

}


//---------------------------------------------------------------------------------------------------
//Previous task in other way.

struct fractionn{
	int num;
	int den;
};

void operations_with_Fractions2()
{
	enum operation{ EXIT, ADD, SUBTRACT, MULTIPLY, DIVIDE, SIMPLIFY };

	fractionn inputFraction();

	cout << "--- Enter numerator then denominator ---\n" << endl;

	void printResult(fractionn);
	fractionn add(fractionn, fractionn);
	fractionn subtract(fractionn, fractionn);
	fractionn multiply(fractionn, fractionn);
	fractionn divide(fractionn, fractionn);
	fractionn simplify(fractionn);

	fractionn ab, cd;

	int ch;
	while (true){
		cout << "\nChoose one of the operation:\n" << endl;
		cout << "  1 Addition" << endl;
		cout << "  2 Subtract" << endl;
		cout << "  3 Multiplication" << endl;
		cout << "  4 Division" << endl;
		cout << "  5 Simplification" << endl;
		cout << "  0 Exit\n" << endl;

		cout << "---------------------" << endl;
		cout << "Option: ";
		cin >> ch;
		ab = cd = { 0, 0 };

		switch (ch)
		{
		case ADD:
			cout << "\nEnter a fraction a/b: " << endl;
			ab = inputFraction();
			cout << "\nEnter a fraction c/d: " << endl;
			cd = inputFraction();
			printResult(add(ab, cd));
			break;

		case SUBTRACT:
			cout << "\nEnter a fraction a/b: " << endl;
			ab = inputFraction();
			cout << "\nEnter a fraction c/d: " << endl;
			cd = inputFraction();
			printResult(subtract(ab, cd));
			break;

		case MULTIPLY:
			cout << "\nEnter a fraction a/b: " << endl;
			ab = inputFraction();
			cout << "\nEnter a fraction c/d: " << endl;
			cd = inputFraction();
			printResult(multiply(ab, cd));
			break;

		case DIVIDE:
			cout << "\nEnter a fraction a/b: " << endl;
			ab = inputFraction();
			cout << "\nEnter a fraction c/d: " << endl;
			cd = inputFraction();
			printResult(divide(ab, cd));
			break;

		case SIMPLIFY:
			cout << "\nEnter a fraction a/b: " << endl;
			ab = inputFraction();
			printResult(simplify(ab));
			break;

		case EXIT:
			goto endp;
			break;

		default:
			cout << "\nThat option doesn't exist. Try again.\n" << endl;
		}
	};


	endp: cout << "\nPress enter to exit...";

}

double inputDigit()
{
	double n;

	while (!(cin >> n)){
		cout << "Input is not digit. Try again." << endl;
		cin.clear();
		cin.ignore(80, '\n');
	}

	return n;
}

int inputInteger()
{
	double n;

	do{
		n = inputDigit();
		if (n != static_cast<int>(n)) cout << "Input is not integer. Try again." << endl;
		cin.ignore(80, '\n');
	} while (n != static_cast<int>(n));

	return static_cast<int>(n);
}

fractionn inputFraction()
{
	fractionn f;

	f.num = inputInteger();
	cout << "/" << endl;;
	do{
		f.den = inputInteger();
		if (f.den == 0) cout << "Denominator value is not allowed. Try again." << endl;
	} while (f.den == 0);

	void printFraction(fractionn);
	cout << "\nYou entered: ";
	printFraction(f);

	return f;
}

void printFraction(fractionn f)
{
	cout << f.num << "/" << f.den << endl;
}

void printResult(fractionn f)
{
	cout << "\nResult = " << f.num << "/" << f.den << endl;
}

fractionn add(fractionn a, fractionn b)
{
	fractionn f;
	fractionn simplify(fractionn);

	f.num = b.den*a.num + a.den*b.num;
	f.den = a.den * b.den;

	return simplify(f);
}

fractionn subtract(fractionn a, fractionn b)
{
	fractionn f;
	fractionn simplify(fractionn);

	f.num = b.den*a.num - a.den*b.num;
	f.den = a.den * b.den;

	return simplify(f);
}

fractionn multiply(fractionn a, fractionn b)
{
	fractionn f;
	fractionn simplify(fractionn);

	f.num = a.num * b.num;
	f.den = a.den * b.den;

	return simplify(f);
}

fractionn divide(fractionn a, fractionn b)
{
	fractionn f;
	fractionn simplify(fractionn);

	f.num = a.num * b.den;
	f.den = a.den * b.num;

	return simplify(f);
}

fractionn simplify(fractionn a)
{
	int n = abs(a.num), d = abs(a.den), maxdiv = 1;
	int min = n < d ? n : d;

	for (int i = 2; i <= min; i++){
		if (n%i == 0 && d%i == 0){
			if (maxdiv < i){
				maxdiv = i;
			}
		}
	}

	a.num /= maxdiv;
	a.den /= maxdiv;

	return a;
}

//---------------------------------------------------------------------------------------------------
//