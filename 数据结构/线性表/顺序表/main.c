#include"function.h"
void text()
{
	int tmp = 0;
	SL List;
	ListInit(&List);
	ListInsert(&List, 1,5);
	ListInsert(&List, 2,8);
	ListHomeInsert(&List,1);
	ListEndInsert(&List, 5);
	ListDelete(&List, 1);
	ListHomeDelete(&List);
	ListEndDelete(&List);
	ListInsert(&List, 2, 7);
	ListModify(&List, 2, 9);
	tmp = ListSearch_byi(&List, 2);
	printf("%d\n", tmp);
	tmp= ListSearch_byx(&List, 8);
	printf("%d\n", tmp);
	ListPrint(&List);


}
int main()
{;
	text();
	return 0;
}