#include "Movie.h"
#include "utilities.cpp"
#include <iostream>

ostream &operator<<(ostream &os, const Movie &movie) {
    os << "Номер: " << movie.number << endl;
    os << "Година на създаване: " << movie.createdOnYear << endl;
    os << "Режисьор: " << movie.director << endl;
    os << "Вид на носителя: " << movie.type << endl;
    os << "Такса: " << movie.rentalPrice << endl;
    os << "Наличен: " << (movie.isAvailable() ? "Да" : "Не") << endl;

    return os;
}

Movie::Movie(int number, const string title, unsigned short createdOnYear, const string director,
             const Movie::RentalPrice &rentalPrice, MovieType type) : number(number), title(title),
                                                                      createdOnYear(createdOnYear),
                                                                      director(director), rentalPrice(rentalPrice),
                                                                      type(type) {}

bool operator>(const Movie &movie, const int &year) {
    return movie.createdOnYear > year;
}

ostream &operator<<(ostream &os, const Movie::RentalPrice &rentalPrice) {
    os << "Такса за наем: " << rentalPrice.price << " за период от " << rentalPrice.periodDays << " дни";
    return os;
}

bool Movie::isAvailable() const {
    return this->available;
}

istream &operator>>(istream &is, Movie &movie) {
    movie.number = ask<int>(is, "Въведи номер");
    movie.title = ask<string>(is, "Въведи заглавие");
    movie.createdOnYear = ask<int>(is, "Въведи година на създаване");
    movie.director = ask<string>(is, "Въведи директор");
    movie.available = ask<bool>(is, "Наличен ли е?");

    movie.type = ask<MovieType>(is, "Избери тип носител");

    movie.rentalPrice.price = ask<Money>(is, "Цена наем");
    movie.rentalPrice.periodDays = ask<int>(is, "за дни");

    return is;
}

int Movie::getNumber() const {
    return number;
}

const string &Movie::getTitle() const {
    return title;
}

unsigned short Movie::getCreatedOnYear() const {
    return createdOnYear;
}

const string Movie::getDirector() const {
    return director;
}

const Movie::RentalPrice &Movie::getRentalPrice() const {
    return rentalPrice;
}

MovieType Movie::getType() const {
    return type;
}

Movie::Movie() = default;
