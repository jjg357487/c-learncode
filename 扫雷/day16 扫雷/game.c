#define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void initboard(char board[ROWS][COLS], int row, int col, char ret)
{
	int x = 0, y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			board[x][y] = ret;
		}
	}
}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	for (x = 0; x <= col; x++)
	{
		printf("%d ", x);
	}
	printf("\n");
	for (x = 1; x <= row; x++)
	{
		printf("%d ", x);
		for (y = 1; y <= col; y++)
		{
			printf("%c ", board[x][y]);
		}
		printf("\n");
	}
}
void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = easy_count;
	int x = 0, y = 0;
	while (count)
	{
	    x = rand() % row + 1;
		y = rand() % row + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}
void minesweep(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int count = row * col - easy_count;
	int win = 0;
	while (count)
	{
		printf("请输入坐标:<");
		get:
		scanf("%d%d", &x, &y);
		system("cls");
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				displayboard(show, row, col);
				printf("%d %d坐标已经输入过，请重新输入:",x,y);
				goto get;
			}
			if (mine[x][y] == '1')
			{
				if (count == row * col - easy_count)
				{
					mine[x][y] = '0';
					resetmine(mine, x, y);
					goto again;
				}
				printf("吊毛，你被炸死了\n");
				displayboard(show, row, col);
				printf("3s后跳转到主页");
				Sleep(3000);
				system("cls");
				break;
			}
			else
			{
				again:
				linkshow(mine, show, x, y);
				displayboard(show, row, col);
				//displayboard(mine, row, col);
				win = iswin(show);
				if (win == 10)
				{
					goto end;
				}
				count--;
			}

		}
		else
		{
		printf("输入错误,请重新输入");
		}
	}
	if (count == 0)
	{
	end:
		printf("牛逼，你赢啦\n");
	}
}
//int detect(char board[ROWS][COLS], int x, int y)
//{
//	return board[x - 1][y - 1] +
//		board[x - 1][y] +
//		board[x - 1][y + 1] +
//		board[x][y - 1] +
//		board[x][y + 1] +
//		board[x + 1][y - 1] +
//		board[x + 1][y] +
//		board[x + 1][y + 1] -
//		8 * '0';
//}
int detect(char mine[ROWS][COLS], int x, int y)
{

	int count = 0;
	int i, j;
	for (i = x - 1; i <= x + 1; i++)
	{

		for (j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] != '0')
			{
				count++;
			}
		}

	}
	return count;
}
void linkshow(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		int ret = detect(mine, x, y);
		if (ret == 0)
		{
			show[x][y] = ' ';
			if (show[x - 1][y - 1] == '*')
				linkshow(mine, show, x - 1, y - 1);
			if (show[x - 1][y] == '*')
				linkshow(mine, show, x - 1, y);
			if (show[x - 1][y + 1] == '*')
				linkshow(mine, show, x - 1, y + 1);
			if (show[x][y - 1] == '*')
				linkshow(mine, show, x, y - 1);
			if (show[x][y + 1] == '*')
				linkshow(mine, show, x, y + 1);
			if (show[x + 1][y - 1] == '*')
				linkshow(mine, show, x + 1, y - 1);
			if (show[x + 1][y] == '*')
				linkshow(mine, show, x + 1, y);
			if (show[x + 1][y + 1] == '*')
				linkshow(mine, show, x + 1, y + 1);

		}
		else
		{
			show[x][y] = ret + '0';

		}
	}
}
void resetmine(char mine[ROWS][COLS], int x, int y)
{
begin:
	int i = rand() % 9 + 1;
	int j = rand() % 9 + 1;
	if (i == x && j == y)
	{
		goto begin;
	}
	else
	{
		mine[i][j] = '1';
	}
}
int iswin(char show[ROWS][COLS])
{
	int count = 0;
	int i = 0, j = 0;
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j<= COL; j++)
		{
			if (show[i][j] == '*')
			{
			count++;
			}
		}
	}
	return count;
}