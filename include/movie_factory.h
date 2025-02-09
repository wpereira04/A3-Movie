
#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include "movie.h"
#include<string>
#include<vector>


std::vector<Movie*> CreateMovies(std::vector<std::string>& titles,
	std::vector<std::string>& directors, std::vector<int>& runtimes,
	std::vector<int>& ids, std::vector<double>& ratings);

#endif 