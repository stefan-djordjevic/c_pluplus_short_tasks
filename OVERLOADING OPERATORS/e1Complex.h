#ifndef e1Complex
#define e1Complex

class Complex
{
	double real, imag;
public:
	Complex();
	Complex(double, double);
	Complex(const Complex &);
	~Complex() {}

	const double &getReal() const;
	const double &getImag() const;

	void setReal(const double);
	void setImag(const double);
	void setCmplx(const double, const double);

	Complex &operator = (const Complex &);
	friend Complex operator + (const Complex &, const Complex &);
	friend Complex operator + (const int &, const Complex &);
	friend Complex operator - (const Complex &, const Complex &);
	friend Complex operator - (const int &, const Complex &);
	friend Complex operator * (const Complex &, const Complex &);
	friend Complex operator * (const Complex &, const double);
	friend Complex operator / (const Complex &, const Complex &);
	friend Complex operator / (const int &, const Complex &);
	friend Complex operator ~ (const Complex &);

	friend double abs(const Complex &);

	void print() const;
};

#endif