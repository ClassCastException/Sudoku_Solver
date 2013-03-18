#ifndef SOLVER_H
#define SOLVER_H

extern int solved;
extern bool backtrack;
extern int grid[9][9];
extern bool initial[9][9];

bool checkRow(int num, int row);
bool checkCol(int num, int col);
bool checkBlock(int num, int row, int col);
bool invalid(int row, int col, int num);
void solve(int& row, int& col);
void move(int& row, int& col, bool next);
void print();

#endif