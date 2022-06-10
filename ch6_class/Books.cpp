#include <cassert>
#include "Books.hpp"

// Overridden default constructor
Books::Books() {
    author = "unspecified";
    title = "unspecified";
    publisher = "unspecified";
    format = "unspecified";
}

// Overridden copy constructor (mimics system version)
Books:Books(const Books& otherBook) {
    author = otherBook.author;
    title = otherBook.title;
    publisher = otherBook.publisher;
    format = otherBook.format;
    price = otherBook.price;
    mYearOfPublication = otherBook.GetYearOfPublication();
}

// Specialised constructor
Books:Books(std::string bookTitle) {
    title = bookTitle;
}

void Books::SetYearOfPublication(int year) {
    assert ((year > 1440) && (year < 2020));
    mYearOfPublication = year;
}

int Books::GetYearOfPublication() const {
    return mYearOfPublication;
}