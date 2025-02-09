

#include<string>
#include<iostream>
#include<exception>
#include<stdexcept>
class Movie
{
public:
	Movie(std::string t, std::string d, int r, int i, double rate);

	~Movie();
	std::string GetTitle() const;
	std::string GetDirector() const;
	double GetRating() const;
	int GetRuntime() const;
	void PrintMovieData();
private:
	int id;
	std::string title; 
	std::string director;
	int runtime;
	double rating; // 0 to 10
};



