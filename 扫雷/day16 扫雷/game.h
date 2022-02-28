#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define easy_count 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void initboard(char board[ROWS][COLS], int row, int col, char ret);
void displayboard(char board[ROWS][COLS], int row, int col);
void setmine(char board[ROWS][COLS], int row, int col);
void minesweep(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);
int detect(char mine[ROWS][COLS], int x, int y);
void linkshow(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
void resetmine(char mine[ROWS][COLS], int x, int y);
int iswin(char show[ROWS][COLS]);