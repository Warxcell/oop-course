//
// Created by bozhidar_hristov on 19.01.24.
//

#include "MovieLibrary.h"
#include <algorithm>
#include <iostream>

using namespace std;

MovieLibrary::MovieLibrary(string name) : name(name) {

}

void MovieLibrary::addMovie(const Movie &movie) {
    this->movies[movie.getNumber()] = movie;
}

bool MovieLibrary::removeMovieByNumber(const int &number) {
    return this->movies.erase(number) > 0;
}

map<int, Movie> MovieLibrary::getMovies() const {
    return this->movies;
}

void MovieLibrary::printAvailableMovies(ostream &os) const {
    for (const auto &[key, value]: this->movies) {
        if (value.isAvailable()) {
            os << value;
        }
    }
}

void MovieLibrary::printMoviesSummary(ostream &os) const {
    for (const auto &[key, value]: this->movies) {
        os << value.getNumber() << " (" << value.getTitle() << ")" << endl;
    }
}

void
MovieLibrary::printLatestAvailableMovieByDirectorAndType(ostream &os, const string &name, const MovieType &type) const {
    auto found = find_if(this->movies.rbegin(), this->movies.rend(),
                         [&name, &type](auto &item) {
                             return item.second.isAvailable() && item.second.getDirector() == name &&
                                    item.second.getType() == type;
                         });

    if (found != this->movies.rend()) {
        os << found->second;
    } else {
        os << "Няма намерен!";
    }
}

void MovieLibrary::printMovieByNumber(ostream &os, const int &number) const {
    auto movie = this->movies.find(number);

    if (movie == this->movies.end()) {
        cout << "Филм " << number << "не е намерен!" << endl;
    } else {
        cout << movie->second;
    }
}

MovieLibrary::MovieLibrary() = default;