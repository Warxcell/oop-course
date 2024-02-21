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
    std::vector<Movie> found;
    for (const auto &movie: this->movies) {
        if (movie.second.isAvailable() && movie.second.getDirector() == name && movie.second.getType() == type) {
            found.push_back(movie.second);
        }
    }

    if (found.empty()) {
        os << "Няма намерен!";
        return;
    }

    std::ranges::sort(found, [](const Movie &a, const Movie &b) {
        return a.getCreatedOnYear() > b.getCreatedOnYear();
    });

    os << found[0];
}

void MovieLibrary::printMovieByNumber(ostream &os, const int &number) const {
    auto movie = this->movies.find(number);

    if (movie == this->movies.end()) {
        cout << "Филм " << number << "не е намерен!" << endl;
    } else {
        cout << movie->second;
    }
}

void MovieLibrary::printNotAvailableMovies(ostream &os) const {
    for (const auto &[key, value]: this->movies) {
        if (!value.isAvailable()) {
            os << value;
        }
    }
}

MovieLibrary::MovieLibrary() = default;