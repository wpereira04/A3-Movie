////////////////////////////////////////////////////////
//
// ECE 3574, A3, Walter Pereira Cruz
// File name: movie_factory.cpp
// Description: Contains the definition for the function
//				in movie_factory.h
// Date:        02/09/2025
//

#include "movie_factory.h"
// finds the highest rated movie from a vector of movies
Movie* FindHighestRatedMovie(std::vector<Movie*> ptrs) {
	double highest{ 0 };
	int index{ 0 };
	for (std::size_t i{ 0 }; i < ptrs.size(); i++) {
		if (ptrs[i]->GetRating() > highest) {
			highest = ptrs[i]->GetRating();
			index = i;
		}
	}
	return ptrs[index];
}
// calculates the average runtime of movies in a vector of movies
double CalculateAverageRuntime(std::vector<Movie*> ptrs) {
	int sum{ 0 };
	for (std::size_t i{ 0 }; i < ptrs.size(); i++) {
		sum += ptrs[i]->GetRuntime();
	}
	return sum / ptrs.size();
}

int main() {
	// uses the earlier defined functions
	std::vector<std::string> titles{ "Foo", "Foo 2", "Bar", "Bar 2", "FooBar" };
	std::vector<std::string> directors{ "Finn", "Clancy", "James", "Lance", "Jim" };
	std::vector<int> runtimes{ 100, 125, 140, 150, 90 };
	std::vector<int> ids{ 1, 2, 3, 4, 5 };
	std::vector<double> ratings{ 9.1, 5.2, 8.9, 5.8, 9.9 };
	std::vector<Movie*> movies = CreateMovies(titles, directors, runtimes, ids, ratings);
	Movie* movie = FindHighestRatedMovie(movies);
	if (movie->GetTitle() != "FooBar" || movie->GetDirector() != "Jim" ||
		movie->GetRuntime() != 90 || movie->GetRating() != 9.9) {
		throw std::invalid_argument("Wrong parameters");
	}
	double avg = CalculateAverageRuntime(movies);
	if (avg != 121) {
		throw std::invalid_argument("Wrong parameters");
	}
	movie->PrintMovieData();
	std::cout << avg;
	return 0;
}