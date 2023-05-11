#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2

void InitBoard(char board[ROWS][COLS], int, int, char);

void DisplayBoard(char board[ROWS][COLS], int, int);

void SetMine(char board[ROWS][COLS], int, int);

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int, int);

int GetMineCount(char mine[ROWS][COLS], int ,int );