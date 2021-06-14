#ifndef sortarray
#define sortarray

//...............................................................................................................................
//Use generic class to sort array in ascending or descending order;
//Program with generic function should be able to sort arrays of:
//		- whole numbers by their value
//		- points in the plane by their distance from coordinate beginning
//		- rectangles by their area;


//Definition of generic class for array sorting
template <typename T, class U>
	class Sort
	{
	public:
		static void sort(T* a, int n);
	};


template <typename T, class U>
	void Sort<T, U>::sort(T *a, int n)
	{
		for (int i = 0; i < n - 1; i++){
			for (int j = i + 1; j < n; j++){
				if (U::compare(a[j], a[i]))
				{
					T temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}


//Definition of "help" generic class for sorting in ascending order
template <typename T>
	class Asc
	{
	public:
		static bool compare(const T& a, const T& b) { return a < b; }
	};


//Definition of "help" generic class for sorting in descending order
template <typename T>
	class Desc
	{
	public:
		static bool compare(const T& a, const T& b) { return b < a; }
	};

#endif
