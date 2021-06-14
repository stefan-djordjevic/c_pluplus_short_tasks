#include <iostream>
#include <cmath>
using namespace std; 

#include "e1Complex.h"


Complex::Complex() : real(0), imag(0) {}
Complex::Complex(double re, double im) : real(re), imag(im) {}
Complex::Complex(const Complex &c) : real(c.real), imag(c.imag) {}

const double &Complex::getReal() const { return real; }
const double &Complex::getImag() const { return imag; }

void Complex::setReal(const double re) { real = re; }
void Complex::setImag(const double im) { imag = im; }
void Complex::setCmplx(const double re, const double im) { real = re; imag = im; }

Complex &Complex::operator = (const Complex &c)
{
	real = c.real;
	imag = c.imag;
	return *this;
}

Complex operator + (const Complex &c1, const Complex &c2)
{
	Complex temp(c1.real + c2.real, c1.imag + c2.imag);
	return temp;
}

Complex operator + (const int &num, const Complex &c2)
{
	Complex c1(static_cast<double>(num), static_cast<double>(0));

	Complex temp(c1.real + c2.real, c1.imag + c2.imag);
	return temp;
}

Complex operator - (const Complex &c1, const Complex &c2)
{
	Complex temp(c1.real - c2.real, c1.imag - c2.imag);
	return temp;
}

Complex operator - (const int &num, const Complex &c2)
{
	Complex c1(static_cast<double>(num), static_cast<double>(0));

	Complex temp(c1.real - c2.real, c1.imag - c2.imag);
	return temp;
}

Complex operator * (const Complex &c1, const Complex &c2)
{
	Complex temp(c1.real*c2.real - c1.imag*c2.imag, c1.real*c2.imag + c2.real*c1.imag);
	return temp;
}

Complex operator * (const Complex &c, const double d)
{
	Complex temp(c.real * d, c.imag * d);
	return temp;
}

Complex operator / (const Complex &c1, const Complex &c2)
{
	double t = c2.real*c2.real + c2.imag*c2.imag;
	Complex temp((c1.real*c2.real + c1.imag*c2.imag) / t, (c2.real*c1.imag - c1.real*c2.imag) / t);
	return temp;
}

Complex operator / (const int &num, const Complex &c2)
{
	Complex c1(static_cast<double>(num), static_cast<double>(0));

	double t = c2.real*c2.real + c2.imag*c2.imag;
	Complex temp((c1.real*c2.real + c1.imag*c2.imag) / t, (c2.real*c1.imag - c1.real*c2.imag) / t);
	return temp;
}

Complex operator ~ (const Complex &c)
{
	Complex temp;
	temp.real = c.real;
	temp.imag = -c.imag;
	return temp;
}

double abs(const Complex &c)
{
	double temp = sqrt(c.real*c.real + c.imag*c.imag);
	return temp;
}

void Complex::print() const
{
	if (imag >= 0)
		cout << "(" << real << "+i" << imag << ")" << endl;
	else
		cout << "(" << real << "-i" << abs(imag) << ")" << endl;
}