#include <iostream>
#include "Money.h"
#include "MovieLibrary.h"
#include "MovieType.h"
#include "Movie.h"
#include "utilities.cpp"

using namespace std;


int main() {
    short unsigned int numberOfMovies;
    string name;
    cout << "Стартиране на програма за управление на видеотека" << endl;
    cout << "Въведете име на видеотеката = ";
    getline(cin, name);
    cout << "Въведете брой филми = ";
    cin >> numberOfMovies;

    MovieLibrary movieLibrary = MovieLibrary(name);

    for (int i = 0; i < numberOfMovies; i++) {
        Movie movie = Movie();

        cin >> movie;

        movieLibrary.addMovie(movie);
    }

    short unsigned int choice;
    do {
        cout << "0) Изход" << endl;
        cout << "1) Добави филм" << endl;
        cout << "2) Премахни филм" << endl;
        cout << "3) Отпечатай филмите" << endl;
        cout << "4) Отпечатай филм " << endl;
        cout << "5) Намери последният наличен филм по режисьор и вид на носителят " << endl;
        cout << "6) Налични филми" << endl;

        cin >> choice;

        switch (choice) {
            case 0:
                return 0;
            case 1: {
                Movie movie = Movie();

                cin >> movie;

                movieLibrary.addMovie(movie);
                break;
            }
            case 2:
                movieLibrary.printMoviesSummary(cout);

                if (!movieLibrary.removeMovieByNumber(ask<int>(cin, "Въведи номер на филм който искате да изтриете"))) {
                    cout << "Филмът не е намерен!";
                } else {
                    cout << "Филмът е премахнат";
                }
                break;
            case 3:
                for (const auto &m: movieLibrary.getMovies()) {
                    cout << m.second << endl;
                }
                break;
            case 4: {
                movieLibrary.printMoviesSummary(cout);

                movieLibrary.printMovieByNumber(cout, ask<int>(cin, "Въведи номер на филм който искате да отпечатате"));

                break;
            }
            case 5:
                movieLibrary.printLatestAvailableMovieByDirectorAndType(cout,
                                                                        ask<string>(cin, "Въведи име на директор"),
                                                                        ask<MovieType>(cin, "Избери тип носител")
                );
                break;
            case 6:
                movieLibrary.printAvailableMovies(cout);
                break;
            default:
                cout << "Невалиден избор !!";
        }

        cout << endl;
    } while (true);

//    try {
//        throw std::invalid_argument("test");
//    } catch (invalid_argument &exception) {
//        cout << exception.what() << endl;
//    }
}
