#ifndef COURSE_MOVIETYPE_CPP
#define COURSE_MOVIETYPE_CPP

#include <iostream>
#include "MovieType.h"

std::istream &operator>>(std::istream &is, MovieType &movieType) {
    std::cout << "1. ДиВиДи. 2. Касетка" << std::endl;

    int choice;
    if (is >> choice) {
        movieType = static_cast<MovieType>( choice );
    }
    return is;
}

#endif //COURSE_MOVIETYPE_CPP
