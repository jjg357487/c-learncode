#define  _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void mnue()
{
	printf("-----------ɨ----------��----------\n");
	printf("-----------------------------------\n");
	printf("-----1.��ʼ��Ϸ    0.������Ϸ------\n");
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
		printf("������ѡ��;<");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			//system("cls");
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			system("cls");
			printf("����������\n");
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