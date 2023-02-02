#include "minesweeper.h"

void minesweeper(string input, string output)
{
	ifstream myfile;
	string a, b;
	myfile.open(input);
	myfile >> a;
	myfile >> b;
	char board[SIZE][SIZE];
	initBoard(board, b);
	int bombnum[SIZE][SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == '*') {
				if (i - 1 >= 0) {
					bombnum[i - 1][j]++;
					if (j - 1 >= 0)
						bombnum[i - 1][j - 1]++;
					if (j + 1 < SIZE)
						bombnum[i - 1][j + 1]++;
				}
				if (i + 1 < SIZE) {
					bombnum[i + 1][j]++;
					if (j - 1 >= 0)
						bombnum[i + 1][j - 1]++;
					if (j + 1 < SIZE) {
						bombnum[i + 1][j + 1]++;
					}
				}
				if (j - 1 >= 0)
					bombnum[i][j - 1]++;
				if (j + 1 < SIZE)
					bombnum[i][j + 1]++;
			}
		}
	}
	int touch[SIZE][SIZE] = { 0 };
	string findtouch;
	int x1, y1, x, y, count = 0;
	ofstream myfi;
	myfi.open(output);
	myfi << "Command: load " << b << endl;
	while (true) {
		myfile >> findtouch;
		if (findtouch == "display") {
			myfi << "Command: display" << endl;
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					myfi << ".";
				}
				myfi << endl;
			}
			myfi << endl;
		}
		if (findtouch == "display") {
			break;
		}
		myfile >> x1;
		x = x1;
		myfile >> y1;
		y = y1;
		touchBoard(touch, x, y);
		if (myfile.eof()) {
			break;
		}
		displayBoard(myfi, findtouch, x, y);
		count++;
		if (board[x - 1][y - 1] == '*') {
			break;
		}
	}
	myfi << "Game Over" << endl;
	myfi << "~~~~~~~~~" << endl;
	myfi << "Final Board" << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (touch[i][j] == 1 && board[i][j] == '.') {
				myfi << bombnum[i][j];
			}
			if (touch[i][j] == 1 && board[i][j] == '*') {
				myfi << "*";
			}
			if (touch[i][j] == 0 && board[i][j] == '.') {
				myfi << ".";
			}
			if (touch[i][j] == 0 && board[i][j] == '*') {
				myfi << "@";
			}
		}
		myfi << endl;
	}
	myfi << endl;
	myfi << "Spaces touched: " << count << endl;
	myfile.close();
	myfi.close();
}

void initBoard(char board[][SIZE], string file)
{
	ifstream fi;
	fi.open(file);
	char space;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			fi >> space;
			board[i][j] = space;
		}
	}
	fi.close();
}

void displayBoard(ostream& out, string findtouch, int x, int y)
{
	if (findtouch == "touch") {
		out << "Command: touch " << x << " " << y << endl;
	}
}


void touchBoard(int touch[][SIZE], int x, int y)
{
	int tx = x - 1;
	int ty = y - 1;
	touch[tx][ty] = 1;
}

int main() {
	cout << "Testing minesweeper" << endl;
	minesweeper(".\\test1commands.txt", "test1_output_mine.txt");
	minesweeper(".\\test2commands.txt", "test2_output_mine.txt");
	minesweeper(".\\test3commands.txt", "test3_output_mine.txt");
	minesweeper(".\\test4commands.txt", "test4_output_mine.txt");
	minesweeper(".\\test5commands.txt", "test5_output_mine.txt");
	minesweeper(".\\test6commands.txt", "test6_output_mine.txt");
	minesweeper(".\\test7commands.txt", "test7_output_mine.txt");
	minesweeper(".\\test8commands.txt", "test8_output_mine.txt");
	minesweeper(".\\test9commands.txt", "test9_output_mine.txt");
	minesweeper(".\\test10commands.txt", "test10_output_mine.txt");
	return 0;
}