#include "Money.h"

#include <iostream>
#include "utilities.cpp"

using namespace std;

Money::Money() = default;

Money::Money(double amount, Money::Currency currency) : amount(amount), currency(currency) {}

ostream &operator<<(ostream &os, const Money &money) {
    os << money.amount << " " << money.currency;

    return os;
}

istream &operator>>(istream &is, Money &money) {
    cout << "Цена = ";
    is >> money.amount;
    is >> money.currency;

    return is;
}

istream &operator>>(istream &is, Money::Currency &currency) {
    auto choice = ask<int>(is, "Избери валута: 1) лева, 2) евро, 3) долара");

    switch (choice) {
        case 1:
            currency = Money::Currency::BGN;
            break;
        case 2:
            currency = Money::Currency::EUR;
            break;
        case 3:
            currency = Money::Currency::USD;
            break;
    }

    return is;
}

ostream &operator<<(ostream &os, const Money::Currency &currency) {
    switch (currency) {
        case Money::Currency::EUR:
            os << "евро";
            break;
        case Money::Currency::USD:
            os << "долара";
            break;
        case Money::Currency::BGN:
            os << "лева";
            break;
    }
    return os;
}