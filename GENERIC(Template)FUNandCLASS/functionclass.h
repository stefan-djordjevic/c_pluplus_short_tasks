#ifndef functionclass
#define functionclass

//...............................................................................................................................
//Function class like parameter of template - damped oscillations

//- FUNCTION CLASS
//- calculates the value of dumped  oscillations e^(-0.1x)*sinx for a given value of the variable 'x'
template <typename T>
	class Oscillations
	{
	public:
		T operator () (const T& x) const { return exp(-0.1*x)*sin(x); }
	};
//*** T can be float, double, long double or specific class of complex numbers


//- like GENERIC FUNCTION
//- tables the values of function f(x) for all values of a given variable x of some type T, from xmin to xmax with step dx 
template <class F, typename T>
	void table(F f, T xmin, T xmax, T dx)
	{
		for (T x = xmin; x <= xmax; x += dx)
			cout << x << "\t" << f(x) << endl;
	}


//- like GENERIC CLASS
template <class F, typename T>
class Table
{
	F f;
public:
	void table(T xmin, T xmax, T dx)
	{
		for (T x = xmin; x <= xmax; x += dx)
			cout << x << "\t" << f(x) << endl;
	}
};


#endif