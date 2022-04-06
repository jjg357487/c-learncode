#include"functions.h"
void menu()
{
	printf("*************Contact**************\n");
	printf("*******1.add     2.pop************\n");
	printf("*******3.search   4.modify********\n");
	printf("*******5.sortbyname  0.exit*******\n");
	printf("*******      6.show       ********\n");
	printf("**********************************\n");
}
void text()
{
	contact s;
	int i=99;
	initcontact(&s);
	
	while (i)
	{
		menu();
		printf("请选择;<");
		scanf("%d", &i);
		switch (i)
		{
		case add:
			addcontact(&s);
			break;
		case pop:
			destroycontact(&s);
			break;
		case search:
			searchcontact(&s);
			break;
		case modify:
			modifycontact(&s);
			break;
		case sort:
			sortcontact(&s);
			break;
		case show:
			showcontact(&s);
			break;
		case exit:
			printf("Exit Contact!");
			break;
		default:
			printf("输入错误，请重新输入;\n");
			break;
		}
	}
}

int main()
{
	
	text();
	return 0;
}