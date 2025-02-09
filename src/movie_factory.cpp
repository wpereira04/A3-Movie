#include "movie_factory.h"



std::vector<Movie*> CreateMovies(std::vector<std::string>& titles, std::vector<std::string>& directors,
	std::vector<int>& runtimes, std::vector<int>& ids,
	std::vector<double>& ratings)
{
	std::vector<Movie*> movies;
	if (titles.size() != directors.size() ||
		titles.size() != runtimes.size() ||
		titles.size() != ids.size() ||
		titles.size() != ratings.size()) {
		throw std::invalid_argument("Vectors must be of same size.");
	}
	for (std::size_t i = 0; i < titles.size(); i++) {
		movies.push_back(new Movie(titles[i], directors[i], runtimes[i], ids[i], ratings[i]));
	}

	return movies;
}
