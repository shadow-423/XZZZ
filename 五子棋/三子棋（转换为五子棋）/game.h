#pragma once
#define ROW 15
#define COL 15
#define PIECE 5

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘
void PlayerMove(char board[ROW][COL], int row, int col);	//玩家走棋
void ComputerMove(char board[ROW][COL], int row, int col, int count);	//电脑走棋
char Iswin(char board[ROW][COL], int row, int col,int piece);//判断输赢