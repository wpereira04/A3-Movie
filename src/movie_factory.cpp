////////////////////////////////////////////////////////
//
// ECE 3574, A3, Walter Pereira Cruz
// File name: movie_factory.cpp
// Description: Contains the defenitions for the function
//				from movie_factory.h
//				CreateMovies;
// Date:        02/09/2025
//

#include "movie_factory.h"


// takes vectors of parameters of the Movie class and turns it into a vector of Movie pointers
std::vector<Movie*> CreateMovies(std::vector<std::string>& titles, std::vector<std::string>& directors,
	std::vector<int>& runtimes, std::vector<int>& ids,
	std::vector<double>& ratings)
{
	// result vector
	std::vector<Movie*> movies;
	// checks if vectors are the same size otherwise throw
	if (titles.size() != directors.size() ||
		titles.size() != runtimes.size() ||
		titles.size() != ids.size() ||
		titles.size() != ratings.size()) {
		throw std::invalid_argument("Vectors must be of same size.");
	}
	// fills result vector
	for (std::size_t i = 0; i < titles.size(); i++) {
		movies.push_back(new Movie(titles[i], directors[i], runtimes[i], ids[i], ratings[i]));
	}

	return movies;
}
