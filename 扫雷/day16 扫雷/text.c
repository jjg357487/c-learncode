#define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void mnue()
{
	printf("-----------扫----------雷----------\n");
	printf("-----------------------------------\n");
	printf("-----1.开始游戏    0.结束游戏------\n");
	printf("-----------------------------------\n");
	printf("-----------------------------------\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	initboard(mine, ROWS, COLS,'0');
	initboard(show, ROWS, COLS,'*');
	setmine(mine, ROW, COL);
	system("cls");
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	minesweep(mine,show, ROW, COL);
}
void text()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do {
		mnue();
		printf("请输入选项;<");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			//system("cls");
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			system("cls");
			printf("请重新输入\n");
			Sleep(1000);
			system("cls");
			break;
		}

	} while (input);
}
int main()
{
	text();
	return 0;
}