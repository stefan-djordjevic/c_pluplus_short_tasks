#include <iostream>
#include <string>
#include <sstream>

using namespace std;



//---------------------------------------------------------------------------------------------------
//Primitive database of movies.

struct movie{								//definition of structure "movie"

	string title;
	int year;

};


void list_of_movies()
{
	int n;
	string str;

	cout << "How many movies do you want to enter: ";
	getline(cin, str);
	stringstream(str) >> n;

	movie* movies = new movie[n];

	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter title " << i << ": ";
		getline(cin, movies[i].title);
		cout << "Enter year " << i << ": ";
		getline(cin, str);
		stringstream(str) >> movies[i].year;
	}

	cout << "\nInput was successfull. Do you want to see list of entered movies?[y/n]: ";
	char answer = getchar();

	void print_movies(movie);						//declaration of function print_movies

	if (answer == 'y' || answer == 'Y')
	{
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			print_movies(movies[i]);
		}
		cout << "\n\nGoodbye!" << endl;
	}
	else
		cout << "\n\nGoodbye!" << endl;

	delete[] movies;

}

void print_movies(movie mov)						//function for printing movies on display
{
	cout << mov.title;
	cout << " (" << mov.year << ")" << endl;
}