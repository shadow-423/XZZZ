#pragma once
#define ROW 15
#define COL 15
#define PIECE 5

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������
void DisplayBoard(char board[ROW][COL], int row, int col);//��ӡ����
void PlayerMove(char board[ROW][COL], int row, int col);	//�������
void ComputerMove(char board[ROW][COL], int row, int col, int count);	//��������
char Iswin(char board[ROW][COL], int row, int col,int piece);//�ж���Ӯ