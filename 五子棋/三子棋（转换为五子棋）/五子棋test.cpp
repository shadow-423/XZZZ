#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("******************************************************\n");
	printf("************       1.Play    0.Exit       ************\n");
	printf("******************************************************\n");
}
void game()
{
	//创建输赢判断变量
	char ret = 0;
	//创建棋子连线数
	int piece = PIECE;
	//创建数组
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//创建回合计数
	int count = 0;
	count = 0;
	//下棋
	while (1)
	{
		count++;
		printf("第%d回合\n", count);
		//玩家走棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家输赢
		if (count >= piece)
		{
			ret = Iswin(board, ROW, COL,piece);
			if (ret != 'C')
			{
				break;
			}
		}
		//电脑走棋
		ComputerMove(board, ROW, COL,count);
		DisplayBoard(board, ROW, COL);
		//判断电脑输赢
		if (count >= piece)
		{
			ret = Iswin(board, ROW, COL,piece);
			if (ret != 'C')
			{
				break;
			}
		}
	}
	if (ret == 'X')
	{
		printf("玩家赢\n");
	}
	else if (ret == 'O')
	{
		printf("电脑赢\n");
	}
	else if(ret=='Z')
	{
		printf("平局\n");
	}

}
void test()
{
	int input = 0;
    //随机数
	srand((unsigned)time(NULL));
	do
	{
		input = 2;
		menu();
		printf("请选择：");
		scanf("%d", &input);
		int ch;
		while(ch=getchar()!='\n')
		{
			;
		}
		switch (input)
		{
		case 1:
			printf("五子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择! >:\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}