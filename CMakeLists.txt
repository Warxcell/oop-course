cmake_minimum_required(VERSION 3.26)
project(course)

set(CMAKE_CXX_STANDARD 23)

add_executable(course main.cpp
        Movie.cpp
        Movie.h
        MovieLibrary.cpp
        MovieLibrary.h
        Money.cpp
        Money.h
        utilities.cpp
        MovieType.cpp
        MovieType.h
)
