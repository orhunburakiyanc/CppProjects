#pragma once
// Book.h

#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
public:
    Book(); // create a Book object and initialize the member variables at the same time. , for instance, an empty string for title and author, and zero for publicationYear.
    Book(const string& title, const string& author, int publicationYear); // create a Book object and initialize the member variables at the same time.

    string getTitle() const; // It does not modify any values and returns the current title of the Book object.
    string getAuthor() const; // It returns the current author of the Book object.
    int getPublicationYear() const; // It returns the current publicationYear of the Book object.

    void setTitle(const string& book_title);//It sets the title of the Book object to the value provided in the argument
    void setAuthor(const string& book_author); // It sets the author of the Book object to the value provided in the argument.
    void setPublicationYear(int book_publicationYear);//. It sets the publicationYear of the Book object to the value provided in the argument.

    string getAuthorLastName() const; // returns the last name of the author of the book. 
    void display() const;  // New function

private:
    string title;
    string author;
    int publicationYear;
};

#endif // BOOK_H