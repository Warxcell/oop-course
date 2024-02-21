//
// Created by bozhidar_hristov on 19.01.24.
//

#ifndef COURSE_MOVIELIBRARY_H
#define COURSE_MOVIELIBRARY_H

#include <string>
#include "vector"
#include "Movie.h"
#include <map>

using namespace std;

class MovieLibrary {
private:
    string name;
    map<int, Movie> movies;
public:
    MovieLibrary(string name);

    MovieLibrary();

    void addMovie(const Movie &movie);

    bool removeMovieByNumber(const int &number);

    map<int, Movie> getMovies() const;

    void printMovieByNumber(ostream &os, const int &number) const;

    void printLatestAvailableMovieByDirectorAndType(ostream &os, const string &name, const MovieType &type) const;

    void printMoviesSummary(ostream &os) const;

    void printAvailableMovies(ostream &os) const;

    void printNotAvailableMovies(ostream &os) const;
};


#endif //COURSE_MOVIELIBRARY_H
