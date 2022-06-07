#include <cassert>
#include "Books.hpp"

void Books::SetYearOfPublication(int year) {
    assert ((year > 1440) && (year < 2020));
    mYearOfPublication = year;
}

int Books::GetYearOfPublication() const {
    return mYearOfPublication;
}