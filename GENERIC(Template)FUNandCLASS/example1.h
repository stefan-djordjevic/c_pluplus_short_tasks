#ifndef example1
#define example1

//..................................................
//1.1 Generic function - the largest of two elements

template <typename T> 
	T max_el(const T &a, const T &b) { return a > b ? a : b; }		//definition of generic function


//..................................................
//1.2 Generic function - array print

template <typename T> void print_array(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}


//..................................................
//1.3 Generic class - generating static array

template <typename T, int k>
	class Vect {
		T a[k];
	public:
		T& operator [] (int i) { return a[i]; }
		void empty();
	};

template <typename  T, int k>
	void Vect<T, k>::empty()
	{
		for (int i = 0; i < k; a[i++] = T());
	}


//..................................................
//1.4 Generic class - generating static array (default arguments and typedef)

template <typename T=double, int k=5>				//template with default arguments
	class Vecto {
		T a[k];
	public:
		T& operator [] (int i) { return a[i]; }
	};


//..................................................
//1.5 Generic function - delayed function type specifing

template <typename T, typename U>
auto sum(T t, U u) -> decltype(t + u) { return t + u; }



#endif