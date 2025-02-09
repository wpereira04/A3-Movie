////////////////////////////////////////////////////////
//
// ECE 3574, A3, Walter Pereira Cruz
// File name: movie_factory.h
// Description: Contains the declaration of a function
//				CreateMovies.
// Date:        02/09/2025
//

#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include "movie.h"
#include<string>
#include<vector>


// takes vectors of parameters of the Movie class and turns it into a vector of Movie pointers
std::vector<Movie*> CreateMovies(std::vector<std::string>& titles,
	std::vector<std::string>& directors, std::vector<int>& runtimes,
	std::vector<int>& ids, std::vector<double>& ratings);

#endif 