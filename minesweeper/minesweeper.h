#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cassert>

using std::endl;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::setfill;
using std::string;
using std::ostream;

const int SIZE = 8;

void minesweeper(string input, string output);

void initBoard(char board[][SIZE], string file);

void displayBoard(ostream& out, string findtouch, int x, int y);

void touchBoard(int touch[][SIZE], int x, int y);