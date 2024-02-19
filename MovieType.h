//
// Created by bozhidar_hristov on 30.01.24.
//

#ifndef COURSE_MOVIETYPE_H
#define COURSE_MOVIETYPE_H

enum MovieType {
    DVD = 1,
    CASETTE = 2,
};

std::istream &operator>>(std::istream &is, MovieType &movieType);


#endif //COURSE_MOVIETYPE_H
