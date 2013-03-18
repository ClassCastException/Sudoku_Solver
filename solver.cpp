#include "solver.h"
#include<iostream>

using std::cout;
using std::endl;

int solved = 0;
bool backtrack = false;
int grid[9][9] = {
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0},
				};
bool initial[9][9] = {
						{false, false, false, false, false, false, false, false, false},
						{false, false, false, false, false, false, false, false, false},
						{false, false, false, false, false, false, false, false, false},
						{false, false, false, false, false, false, false, false, false},
						{false, false, false, false, false, false, false, false, false},
						{false, false, false, false, false, false, false, false, false},
						{false, false, false, false, false, false, false, false, false},
						{false, false, false, false, false, false, false, false, false},
						{false, false, false, false, false, false, false, false, false},
					 };
					 
void solve(int& row, int& col){

	if(grid[row][col] != 0 && backtrack == false)
		move(row, col, true);
		
	backtrack = false;	
	int num;
	
	for(num = grid[row][col]+1; num <= 9; num++){
		if(checkRow(num, row) && checkCol(num, col) && checkBlock(num, row, col)){
			grid[row][col] = num;
			break;
		}	
	}
	if(num > 9)
		grid[row][col] = 0;
	move(row, col, num <= 9);
}
void move(int& row, int& col, bool next){
	if(next){
		while(grid[row][col] != 0){
			if(col < 8)
				col++;
			else{
				col = 0;
				row++;
			}
			if(row > 8){
				solved = 1;
				break;
			}
		}
	}
	else{
		do{
				if(col > 0)
					col--;
				else{
					col = 8;
					row--;
				}
				if(row < 0){
					solved = -1;
					break;
				}
		} while(initial[row][col]);
		backtrack = true;
	}
}
bool checkRow(int num, int row){
	for(int col = 0; col < 9; col++){
		if(grid[row][col] == num)
			return false;
	}
	return true;
}
bool checkCol(int num, int col){
	for(int row = 0; row < 9; row++){
		if(grid[row][col] == num)
			return false;
	}
	return true;
}
bool checkBlock(int num, int row, int col){
	row = (row/3)*3;
	col = (col/3)*3;
	
	int r, c;
	for(r = 0; r < 3; r++){
		for(c = 0; c < 3; c++){
			if(grid[row+r][col+c] == num)
				return false;
		}
	}
	return true;
}
bool invalid(int row, int col, int num){
	return !(row >= 1 && row <= 9 && col >= 1 && col <= 9 && num >= 1 && row <= 9);
}
void print(){
	for(int row = 0; row < 9; row++){
		for(int col = 0; col < 9; col++){
			cout << grid[row][col] << " ";
		}
		cout << endl;
	}
}