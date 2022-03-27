#include"functions.h"
void text()
{
	SL* phead = NULL;
	SL* two;
	SL* three;
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 1);
	SListPopBack(&phead);
	SListPopFront(&phead);
	two= SListFind(phead, 2);
	SListInsert(&phead, two, 5);
	three = SListFind(phead, 3);
	SListErase(&phead, three);
	SListPrint(phead);

}
int main()
{
	
	text();

	return 0;
}