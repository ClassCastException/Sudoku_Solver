#include<iostream>
#include<fstream>
#include<cstdlib>
#include "solver.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;

int main(int argNum, char* args[]){
	int row = 0, col = 0;
	int r, c, n;
	char response;
	ifstream file;
	int foo;
	foo = 0;
	
	if(argNum > 1){
		int number;
		int numbers[81];
		int ndx = 0;
		file.open(args[1]);
		if(file.is_open()){
			while(!file.eof()){
				number = file.get();
				if(ndx < 81 && number != 10){
					numbers[ndx] = number-48;
					ndx++;
				}	
			}
		}
		else{
			cerr << "Error opening textfile. Program is now terminating." << endl;
			exit(0);
		}
		file.close();
		ndx = 0;
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j){
				grid[i][j] = numbers[ndx++];
				initial[i][j] = (grid[i][j] != 0);
			}
		}
	}
	else{
		while(true){
			cout << "Would you like to enter some values into the Sudoku puzzle? [y/n]" << endl;
			cin >> response;
			if(response != 'y')
				break;
			cout << "Enter all the row, column, and number values that you need." << endl;
			cin >> r >> c >> n;
			if(cin.fail() || invalid(r, c, n)){
				cout << "You entered an invalid value. Please try again." << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else{
				grid[r-1][c-1] = n;
				initial[r-1][c-1] = true;
			}
		}
	}
	cout << endl << "Initial Puzzle Configuration" << endl << endl;
	print();
	while(solved == 0){
		solve(row, col);
		foo++;
	}
	if(solved == -1)
		cout << endl << "Puzzle is unsolvable." << endl;
	else{
		cout << endl << "Puzzle Solution" << endl << endl;
		print();
	}
	cout << endl << foo;
}