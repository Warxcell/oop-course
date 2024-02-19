#ifndef COURSE_MOVIE_H
#define COURSE_MOVIE_H

#include <string>
#include <ostream>
#include "Money.h"
#include "MovieType.h"

using namespace std;

class Movie {
private:
    int number = 0;
    string title;
    short unsigned int createdOnYear = 0;

    string director;

    struct RentalPrice {
        Money price = Money();
        int periodDays = 0;
    } rentalPrice;

    friend ostream &operator<<(ostream &os, const RentalPrice &rentalPrice);

    friend istream &operator>>(istream &is, Movie &movie);

    friend bool operator>(const Movie &movie, const int &year);

    MovieType type = DVD;

    bool available = true;

public:
    Movie();

    Movie(int number, string title, unsigned short createdOnYear, const string director,
          const RentalPrice &rentalPrice, MovieType type);

    friend ostream &operator<<(ostream &os, const Movie &movie);

    int getNumber() const;

    const string &getTitle() const;

    unsigned short getCreatedOnYear() const;

    const string getDirector() const;

    const RentalPrice &getRentalPrice() const;

    MovieType getType() const;

    bool isAvailable() const;
};


#endif //COURSE_MOVIE_H
