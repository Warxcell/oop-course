#ifndef COURSE_MONEY_H
#define COURSE_MONEY_H

#include <string>
#include <ostream>

using namespace std;

class Money {
private:
    double amount;
    enum class Currency {
        BGN,
        USD,
        EUR,
    } currency;
public:
    friend ostream &operator<<(ostream &os, const Money &money);

    friend ostream &operator<<(ostream &os, const Currency &currency);

    friend istream &operator>>(istream &is, Money &money);

    friend istream &operator>>(istream &is, Currency &currency);

    Money();

    Money(double amount, Money::Currency currency);
};


#endif //COURSE_MONEY_H
