////////////////////////////////////////////////////////
//
// ECE 3574, A3, Walter Pereira Cruz
// File name: movie.cpp
// Description: Contains the definitions for the member functions
//				of the Movie class from movie.h
// Date:        02/09/2025
//

#include "movie.h"



Movie::Movie(std::string t, std::string d, int r, int i, double rate)
{
	// checks if id is valid
	if (i < 0) {
		throw std::invalid_argument("Id must be a positive value.");
	}
	id = i;
	title = t;
	director = d;
	// checks if runtime is valid
	if (r < 0) {
		throw std::invalid_argument("Runtime is an invalid value");
	}
	runtime = r;
	// checks if rating is valid
	if (rate < 0 || rate > 10) {
		throw std::invalid_argument("Rate is an invalid value");
	}
	rating = rate;
}

Movie::~Movie()
{
}
// returns title member
std::string Movie::GetTitle() const
{
	return title;
}

// returns director member
std::string Movie::GetDirector() const
{
	return director;
}

// returns rating member
double Movie::GetRating() const
{
	return rating;
}

// returns runtime member
int Movie::GetRuntime() const
{
	return runtime;
}

// prints movie data in no particular order
void Movie::PrintMovieData()
{
	std::cout << title + " by " + director + " with a rating of " 
		<< rating << " and a runtime of " << runtime << ". Movie has id " << id << '\n';
}


