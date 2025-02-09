
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "movie_factory.h"

TEST_CASE("Testing Movie project methods") {
	Movie movie1("Foo", "Terry", 35, 78, 8.5);
	Movie movie2("Foo 2", "Terrance", 35, 24, 3); // ids can be negative? or at least they aren't said to not be.
	SECTION("Testing invalid Movie declarations") {
		// tests runtime invalid
		REQUIRE_THROWS_AS(Movie("Foo 3", "Tom", -5, 24, 3), std::invalid_argument);
		// id invalid
		REQUIRE_THROWS_AS(Movie("Foo 3", "Tom", 35, -90, 3), std::invalid_argument);
		// rating negative invalid
		REQUIRE_THROWS_AS(Movie("Foo 3", "Tom", 35, 24, -1), std::invalid_argument);
		// rating above ten invalid
		REQUIRE_THROWS_AS(Movie("Foo 3", "Tom", 35, 24, 11), std::invalid_argument);
	}
	SECTION("Testing movie methods") {
		REQUIRE(movie1.GetTitle() == "Foo");
		REQUIRE(movie1.GetDirector() == "Terry");
		REQUIRE(movie1.GetRuntime() == 35);
		REQUIRE(movie1.GetRating() == 8.5);
		REQUIRE_NOTHROW(movie1.PrintMovieData()); // outputs to the console with no return.
		REQUIRE(movie2.GetTitle() == "Foo 2");
		REQUIRE(movie2.GetDirector() == "Terrance");
		REQUIRE(movie2.GetRuntime() == 35);
		REQUIRE(movie2.GetRating() == 3);
		REQUIRE_NOTHROW(movie2.PrintMovieData()); // outputs to the console with no return.
	}
	SECTION("Testing movie_factory function CreateMovies") {
		// invalid input. different sizes of vectors
		std::vector<std::string> titles{ "Foo", "Foo 2", "Bar", "Bar 2", "FooBar" };
		std::vector<std::string> titlesW{ "Foo", "Foo 2", "Bar", "Bar 2"};
		std::vector<std::string> directors{ "Finn", "Clancy", "James", "Lance", "Jim" };
		std::vector<std::string> directorsW{ "Finn", "Clancy", "James", "Lance"};
		std::vector<int> runtimes{ 100, 125, 140, 150, 90 };
		std::vector<int> runtimesW{ 100, 125, 140, 150};
		std::vector<int> ids{ 1, 2, 3, 4, 5 };
		std::vector<int> idsW{ 1, 2, 3, 4};
		std::vector<double> ratings{ 9.1, 5.2, 8.9, 5.8, 9.9 };
		std::vector<double> ratingsW{ 9.1, 5.2, 8.9, 5.8};
		std::vector<Movie*> som = CreateMovies(titles, directors, runtimes, ids, ratings);
		for (std::size_t i = 0; i < titles.size(); i++) {
			REQUIRE(som[i]->GetTitle() == titles[i]);
			REQUIRE(som[i]->GetDirector() == directors[i]);
			REQUIRE(som[i]->GetRuntime() == runtimes[i]);
			REQUIRE(som[i]->GetRating() == ratings[i]);
		}

		REQUIRE_THROWS(CreateMovies(titlesW, directors, runtimes, ids, ratings));
		REQUIRE_THROWS(CreateMovies(titles, directorsW, runtimes, ids, ratings));
		REQUIRE_THROWS(CreateMovies(titles, directors, runtimesW, ids, ratings));
		REQUIRE_THROWS(CreateMovies(titles, directors, runtimes, idsW, ratings));
		REQUIRE_THROWS(CreateMovies(titles, directors, runtimes, ids, ratingsW));

	}
	

}