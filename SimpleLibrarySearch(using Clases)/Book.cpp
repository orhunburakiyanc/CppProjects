#include "Book.h"
#include <iostream>




Book::Book() {
	title = "";
	author = "";
	publicationYear = 0;
}
Book::Book(const string& title, const string& author, int publicationYear) {
	setTitle(title);
	setAuthor(author);
	setPublicationYear(publicationYear);
}

string Book::getTitle() const {
	return title;
}
string Book::getAuthor() const {
	return author;
}
int Book::getPublicationYear() const {
	return publicationYear;
}

void Book::setTitle(const string& book_title) {
	title = book_title;
}
void Book::setAuthor(const string& book_author) {
	author = book_author;
}
void Book::setPublicationYear(int book_publicationYear) {
	publicationYear = book_publicationYear;
}

string Book::getAuthorLastName() const {
	return author.substr(author.rfind(" ") + 1);
}
void Book::display() const {
	cout << title << ", " << author << ", " << publicationYear << endl;
}