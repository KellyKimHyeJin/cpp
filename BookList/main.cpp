#include <iostream>
#include <fstream>
#include <sstream>
#include "BookList.h"

using namespace std;

int main() {
	BookList myBooklist;
	Book tempBook;
	string command, line;
	ifstream in("book_data.txt");
	ofstream out("output.txt");
	size_t pos = 0;
	int year, location;

	while (getline(in, line)) {
		if ((pos = line.find("Command: ")) != string::npos) {
			command = line.substr(9);
			if (command == "add") {
				getline(in, line);
				tempBook.setTitle(line);
				getline(in, line);
				tempBook.setAuthor(line);
				in >> year;
				tempBook.setYear(year);
				in.get(); // eats new line
				getline(in, line);
				tempBook.setGenre(line);
				myBooklist.addBook(tempBook);
			}
			else if ((pos = command.find("addBookAt")) != string::npos) {
				pos = command.find(" ");
				string tmp = command.substr(pos + size_t(1));
				istringstream ss(tmp);
				ss >> location;
				getline(in, line);
				tempBook.setTitle(line);
				getline(in, line);
				tempBook.setAuthor(line);
				in >> year;
				tempBook.setYear(year);
				in.get(); // eats new line
				getline(in, line);
				tempBook.setGenre(line);
				myBooklist.addBookAt(tempBook, location - 1);
			}
			else if ((pos = command.find("removeBook")) != string::npos) {
				pos = command.find(" ");
				string tmp = command.substr(pos + size_t(1));
				istringstream  ss(tmp);
				ss >> location;
				myBooklist.removeBook(location - 1);
			}
			else if ((pos = command.find("findBook")) != string::npos) {
				pos = command.find(" ");
				string tmp = command.substr(pos + size_t(1));
				istringstream  ss(tmp);
				ss >> location;
				tempBook = myBooklist.findBook(location - 1);
				tempBook.displayBook(out);
			}
			else if ((pos = command.find("displayBooks")) != string::npos) {
				myBooklist.displayBooks(out);
			}
		}
	}

	out.close();
	in.close();

	return 0;
}