#ifndef BOOK_H_
#define BOOK_H_
#include <string>
#include <iostream>
using namespace std;

class Book {
private:
	string title;
	string author;
	int year;
	string genre;

public:
	Book() {
		title = "";
		author = "";
		genre = "";
		year = 2016;
	}
	void setTitle(string newTitle) {
		title = newTitle;
	}
	void setAuthor(string newAuthor) {
		author = newAuthor;
	}
	void setYear(int newYear) {
		year = newYear;
	}
	void setGenre(string newGenre) {
		genre = newGenre;
	}
	string getTitle() const {
		return title;
	}
	string getAuthor() const {
		return author;
	}
	int getYear() const {
		return year;
	}
	string getGenre() const {
		return genre;
	}
	void displayBook(std::ostream& out) const {
		out << "Title: " << getTitle() << endl;
		out << "Author: " << getAuthor() << endl;
		out << "Year: " << getYear() << endl;
		out << "Genre: " << getGenre() << endl;
	}
};

#endif