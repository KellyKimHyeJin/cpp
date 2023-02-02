#ifndef BOOKLIST_H_
#define BOOKLIST_H_
#include "Book.h"

using namespace std;

class BookList {
private:
	Book books[10];
	int count;
	int size;

public:
	BookList() {
		count = 0;
		size = 0;
	}
	void addBookAt(Book b, int location) {
		if (location <= 0) {
			for (int i = count - 1; i >= 0; i--) {
				books[i + 1] = books[i];
			}
			books[0] = b;
			count++;
		}
		if (location > count) {
			books[location] = b;
			size++;
		}
		if (location > 0 && location < count) {
			for (int i = count - 1; i >= location; i--) {
				books[i + 1] = books[i];
			}
			books[location] = b;
			count++;
		}
	}
	void addBook(Book b) {
		books[count] = b;
		count++;
	}
	Book findBook(int location) const {
		if (location >= 0 && location < count) {
			return books[location];
		}
		else {
			return Book();
		}
	}
	void removeBook(int location) {
		if (location >= 0 && location < count) {
			for (int i = location; i < count - 1; i++) {
				books[i] = books[i + 1];
			}
		}
		count--;
	}
	void displayBooks(std::ostream& out) const {
		out << "Books in my list:" << endl;
		for (int i = 0; i < count; i++) {
			out << "Title: " << books[i].getTitle() << endl;
			out << "Author: " << books[i].getAuthor() << endl;
			out << "Year: " << books[i].getYear() << endl;
			out << "Genre: " << books[i].getGenre() << endl;
		}
		if (size > 0) {
			for (int i = 9; i > 9 - size; i--) {
				out << "Title: " << books[i].getTitle() << endl;
				out << "Author: " << books[i].getAuthor() << endl;
				out << "Year: " << books[i].getYear() << endl;
				out << "Genre: " << books[i].getGenre() << endl;
			}
		}
	}

};

#endif