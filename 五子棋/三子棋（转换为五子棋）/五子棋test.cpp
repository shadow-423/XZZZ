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
	//������Ӯ�жϱ���
	char ret = 0;
	//��������������
	int piece = PIECE;
	//��������
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//�����غϼ���
	int count = 0;
	count = 0;
	//����
	while (1)
	{
		count++;
		printf("��%d�غ�\n", count);
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж������Ӯ
		if (count >= piece)
		{
			ret = Iswin(board, ROW, COL,piece);
			if (ret != 'C')
			{
				break;
			}
		}
		//��������
		ComputerMove(board, ROW, COL,count);
		DisplayBoard(board, ROW, COL);
		//�жϵ�����Ӯ
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
		printf("���Ӯ\n");
	}
	else if (ret == 'O')
	{
		printf("����Ӯ\n");
	}
	else if(ret=='Z')
	{
		printf("ƽ��\n");
	}

}
void test()
{
	int input = 0;
    //�����
	srand((unsigned)time(NULL));
	do
	{
		input = 2;
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		int ch;
		while(ch=getchar()!='\n')
		{
			;
		}
		switch (input)
		{
		case 1:
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��! >:\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}