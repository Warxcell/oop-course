#include <iostream>

using namespace std;

template<typename T>
T ask(istream &is, const string &title = "") {
    if (!title.empty()) {
        cout << title << " = ";
    }

    T choice;
    is >> choice;

    return choice;
}
