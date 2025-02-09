////////////////////////////////////////////////////////
//
// ECE 3574, A3, Walter Pereira Cruz
// File name: movie.h
// Description: Contains the declaration for the Movie class
//				
// Date:        02/09/2025
//

#ifndef MOVIE_H // include guard
#define MOVIE_H

#include<string>
#include<iostream>
#include<exception>
#include<stdexcept>
class Movie
{
public:
	Movie(std::string t, std::string d, int r, int i, double rate);

	~Movie();
	// gets the title member
	std::string GetTitle() const;
	// gets the director member
	std::string GetDirector() const;
	// gets the rating member
	double GetRating() const;
	// gets the runtime member
	int GetRuntime() const;
	// prints movie data to the console in a sentence
	// no set way for it to print in instructions.
	void PrintMovieData();
private:
	// id of movie. has no get method
	int id; // not in instructions but negative ids don't usually exist.
	std::string title; 
	std::string director;
	int runtime; // must be >= 0
	double rating; // 0 to 10
};
#endif /* MY_CLASS_H */


