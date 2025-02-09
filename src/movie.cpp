

#include "movie.h"



Movie::Movie(std::string t, std::string d, int r, int i, double rate)
{
	if (i < 0) {
		throw std::invalid_argument("Id must be a positive value.");
	}
	id = i;
	title = t;
	director = d;
	if (r < 0) {
		throw std::invalid_argument("Runtime is an invalid value");
	}
	runtime = r;
	if (rate < 0 || rate > 10) {
		throw std::invalid_argument("Rate is an invalid value");
	}
	rating = rate;
}

Movie::~Movie()
{
}

std::string Movie::GetTitle() const
{
	return title;
}

std::string Movie::GetDirector() const
{
	return director;
}

double Movie::GetRating() const
{
	return rating;
}

int Movie::GetRuntime() const
{
	return runtime;
}

void Movie::PrintMovieData()
{
	std::cout << title + " by " + director + " with a rating of " 
		<< rating << " and a runtime of " << runtime << ". Movie has id " << id << '\n';
}


