#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		if (i > 0 && i <= row)
		{
			printf("\n");
			printf(" %3d", i);
		}
		for (j = 0; j <= col; j++)
		{
			if (i == 0)
			{
				if (j <= col)
				{
					printf(" %3d", j);
				}
			}

			else
			{
				if (j > 0 && j <= col)
				{
					printf(" %c ", board[i - 1][j - 1]);
				}
				if (j <= col)
				{
					printf("|");
				}
			}
		}
		if (i == 0)
		{
			printf("\n    ");
		}
		for (j = 0; j <= col; j++)
		{
			if (i == 0)
			{
				if (j < col)
				{
					printf("____");
				}
				if (j == col)
				{
					printf("_");
				}
			}
		}
		if (i > 0)
		{
			printf("\n    ");
			if (i < row)
			{
				for (j = 0; j <= col; j++)
				{
					if (j > 0 && j <= col)
					{
						printf("---");
					}
					if (j <= col)
					{
						printf("|");
					}
				}
			}
		}
		for (j = 0; j <= col; j++)
		{
			if (i == row)
			{
				if (j < col)
				{
					printf("^^^^");
				}
				if (j == col)
				{
					printf("^");
				}
			}
		}
		if (i == row)
		{
			printf("\n");
		}
	}
}
//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("����ߡ�\n");
	while (1)
	{
		x = 0, y = 0;
		printf("������Ҫ�µ�����(������ �ո� �����꣩��");
		scanf("%d%d", &x, &y);
		int ch;
		while (ch = getchar() != '\n')
		{
			;
		}
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("�����걻ռ�ã����������룡\n");
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
}
//��������
void ComputerMove(char board[ROW][COL], int row, int col, int count)
{
	printf("�����ߡ�\n");
	int x = 0, y = 0;
	if (count == 1)
	{
		while (1)
		{
			x = rand() % row;
			y = rand() % col;
			if (board[x][y] == ' ')
			{
				board[x][y] = 'O';
				break;
			}
		}
	}
	else
	{
		int i = rand()%2;
		int n = 1;
		if (i % 3 == 0)
		{
			for (x = 0; x < row; x++)
			{
				if (n == 0)
					break;
				for (y = 0; y < col; y++)
				{
					//�жϺ�������
					if (board[x % row][y % col] == board[x % row][(y + 1) % col] && board[x % row][y % col] != ' ' && board[x % row][(y + 2) % col] == ' ')
					{
						board[x % row][(y + 2) % col] = 'O';
						n = 0;
						break;
					}
					//�ж���������
					if (board[y % row][x % col] == board[(y + 1) % row][x % col] && board[y % row][x % col] != ' ' && board[(y + 2) % row][x % col] == ' ')
					{
						board[(y + 2) % row][x % col] = 'O';
						n = 0;
						break;
					}
				}
			}
			//�ж�б������
			if (n == 1)
			{
				for (x = 0; x < row ; x++)
				{
					if (n == 0)
						break;
					for (y = 0; y < col; y++)
					{
						if (board[x % row][y % col] == board[(x + 1) % row][(y + 1) % col] && board[x % row][y % col] != ' ' && board[(x + 2) % row][(y + 2) % col] == ' ')
						{
							board[(x + 2) % row][(y + 2) % col] = 'O';
							n = 0;
							break;
						}
						if (board[x % row][y % col] == board[(x + 2) % row][(y + 2) % col] && board[x % row][y % col] != ' ' && board[(x + 1) % row][(y + 1) % col] == ' ')
						{
							board[(x + 1) % row][(y + 1) % col] = 'O';
							n = 0;
							break;
						}
						if (board[(x+1) % row][(y+1) % col] == board[(x + 2) % row][(y + 2) % col] && board[(x+1) % row][(y+1) % col] != ' ' && board[(x ) % row][y % col] == ' ')
						{
							board[x % row][y % col] = 'O';
							n = 0;
							break;
						}
					}
				}
				for (x = 0; x < row ; x++)
				{
					if (n == 0)
						break;
					for (y = 0; y < col; y++)
					{
						if (board[x % row][(y + 2) % col] == board[(x + 1) % row][(y + 1) % col] && board[x % row][(y + 2) % col] != ' ' && board[(x + 2) % row][y % col] == ' ')
						{
							board[(x + 2) % row][y % col] = 'O';
							n = 0;
							break;
						}
						if (board[(x + 2) % row][y % col] == board[(x + 1) % row][(y + 1) % col] && board[(x + 2) % row][y % col] != ' ' && board[x % row][(y + 2) % col] == ' ')
						{
							board[x % row][(y + 2) % col] = 'O';
							n = 0;
							break;
						}
						if (board[x % row][(y + 2) % col] == board[(x + 2) % row][y % col] && board[(x + 1) % row][(y + 1) % col] != ' ' && board[(x + 1) % row][(y + 1) % col] == ' ')
						{
							board[(x + 1) % row][(y + 1) % col] = 'O';
							n = 0;
							break;
						}
					}
				}
			}
		}
		else if(i%3==1)
		{
			for (x = 0; x < row; x++)
			{
				if (n == 0)
					break;
				for (y = 0; y < col; y++)
				{
					if (board[y % row][x % col] == board[(y + 1) % row][x % col] && board[y % row][x % col] != ' ' && board[(y + 2) % row][x % col] == ' ')
					{
						board[(y + 2) % row][x % col] = 'O';
						n = 0;
						break;
					}
					if (board[x % row][y % col] == board[x % row][(y + 1) % col] && board[x % row][y % col] != ' ' && board[x % row][(y + 2) % col] == ' ')
					{
						board[x % row][(y + 2) % col] = 'O';
						n = 0;
						break;
					}
				}
			}
			if (n == 1)
			{
				for (x = 0; x < row; x++)
				{
					if (n == 0)
						break;
					for (y = 0; y < col; y++)
					{
						if (board[x % row][y % col] == board[(x + 1) % row][(y + 1) % col] && board[x % row][y % col] != ' ' && board[(x + 2) % row][(y + 2) % col] == ' ')
						{
							board[(x + 2) % row][(y + 2) % col] = 'O';
							n = 0;
							break;
						}
						if (board[x % row][y % col] == board[(x + 2) % row][(y + 2) % col] && board[x % row][y % col] != ' ' && board[(x + 1) % row][(y + 1) % col] == ' ')
						{
							board[(x + 1) % row][(y + 1) % col] = 'O';
							n = 0;
							break;
						}
						if (board[(x + 1) % row][(y + 1) % col] == board[(x + 2) % row][(y + 2) % col] && board[(x + 1) % row][(y + 1) % col] != ' ' && board[(x) % row][y % col] == ' ')
						{
							board[x % row][y % col] = 'O';
							n = 0;
							break;
						}
					}
				}
				for (x = 0; x < row; x++)
				{
					if (n == 0)
						break;
					for (y = 0; y < col; y++)
					{
						if (board[x % row][(y + 2) % col] == board[(x + 1) % row][(y + 1) % col] && board[x % row][(y + 2) % col] != ' ' && board[(x + 2) % row][y % col] == ' ')
						{
							board[(x + 2) % row][y % col] = 'O';
							n = 0;
							break;
						}
						if (board[(x + 2) % row][y % col] == board[(x + 1) % row][(y + 1) % col] && board[(x + 2) % row][y % col] != ' ' && board[x % row][(y + 2) % col] == ' ')
						{
							board[x % row][(y + 2) % col] = 'O';
							n = 0;
							break;
						}
						if (board[x % row][(y + 2) % col] == board[(x + 2) % row][y % col] && board[(x + 1) % row][(y + 1) % col] != ' ' && board[(x + 1) % row][(y + 1) % col] == ' ')
						{
							board[(x + 1) % row][(y + 1) % col] = 'O';
							n = 0;
							break;
						}
					}
				}
			}
		}
		else
		{
			if (n == 1)
			{
				for (x = 0; x < row; x++)
				{
					if (n == 0)
						break;
					for (y = 0; y < col; y++)
					{
						if (board[x % row][y % col] == board[(x + 1) % row][(y + 1) % col] && board[x % row][y % col] != ' ' && board[(x + 2) % row][(y + 2) % col] == ' ')
						{
							board[(x + 2) % row][(y + 2) % col] = 'O';
							n = 0;
							break;
						}
						if (board[x % row][y % col] == board[(x + 2) % row][(y + 2) % col] && board[x % row][y % col] != ' ' && board[(x + 1) % row][(y + 1) % col] == ' ')
						{
							board[(x + 1) % row][(y + 1) % col] = 'O';
							n = 0;
							break;
						}
						if (board[(x + 1) % row][(y + 1) % col] == board[(x + 2) % row][(y + 2) % col] && board[(x + 1) % row][(y + 1) % col] != ' ' && board[(x) % row][y % col] == ' ')
						{
							board[x % row][y % col] = 'O';
							n = 0;
							break;
						}
					}
				}
				for (x = 0; x < row; x++)
				{
					if (n == 0)
						break;
					for (y = 0; y < col; y++)
					{
						if (board[x % row][(y + 2) % col] == board[(x + 1) % row][(y + 1) % col] && board[x % row][(y + 2) % col] != ' ' && board[(x + 2) % row][y % col] == ' ')
						{
							board[(x + 2) % row][y % col] = 'O';
							n = 0;
							break;
						}
						if (board[(x + 2) % row][y % col] == board[(x + 1) % row][(y + 1) % col] && board[(x + 2) % row][y % col] != ' ' && board[x % row][(y + 2) % col] == ' ')
						{
							board[x % row][(y + 2) % col] = 'O';
							n = 0;
							break;
						}
						if (board[x % row][(y + 2) % col] == board[(x + 2) % row][y % col] && board[(x + 1) % row][(y + 1) % col] != ' ' && board[(x + 1) % row][(y + 1) % col] == ' ')
						{
							board[(x + 1) % row][(y + 1) % col] = 'O';
							n = 0;
							break;
						}
					}
				}
			}

			for (x = 0; x < row; x++)
			{
				if (n == 0)
					break;
				for (y = 0; y < col; y++)
				{
					if (board[y % row][x % col] == board[(y + 1) % row][x % col] && board[y % row][x % col] != ' ' && board[(y + 2) % row][x % col] == ' ')
					{
						board[(y + 2) % row][x % col] = 'O';
						n = 0;
						break;
					}
					if (board[x % row][y % col] == board[x % row][(y + 1) % col] && board[x % row][y % col] != ' ' && board[x % row][(y + 2) % col] == ' ')
					{
						board[x % row][(y + 2) % col] = 'O';
						n = 0;
						break;
					}
				}
			}
		}
		if (n == 1)
		{
			while (1)
			{
				x = rand() % row;
				y = rand() % col;
				if (board[x][y] == ' ')
				{
					board[x][y] = 'O';
					break;
				}
			}
		}
	}
}
//�ж�ƽ��
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 2;
			}
		}
	}
	return 1;
 }
//�ж���Ӯ
char Iswin(char board[ROW][COL], int row, int col ,int piece)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <= row - piece; j++)
		{
			if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j+2] == board[i][j+3] && board[i][j+3] == board[i][j+4] && board[i][j] != ' ')
				return board[i][j];
			if (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i] && board[j+2][i] == board[j+3][i] && board[j+3][i] == board[j+4][i] && board[j][i] != ' ')
				return board[j][i];
		}
	}
	for (i = 0; i <= row - piece ; i++)
	{
		for (j = 0; j <= col - piece; j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i + 3][j + 3] == board[i + 4][j + 4] && board[i][j] != ' ')
				return board[i][j];
			if (board[i][j+4] == board[i+1][j+3] && board[i+1][j+3] == board[i+2][j + 2] && board[i+2][j + 2] == board[i+3][j + 1] && board[i + 3][j + 1] == board[i + 4][j] && board[i][j+4] != ' ')
				return board[i][j+4];
		}
	}
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Z';
	}
	return 'C';
}