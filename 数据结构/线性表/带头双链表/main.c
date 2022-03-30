#include"function.h"
void text1()
{
	DL* phead = NULL;
	phead=initDList(phead);
	DListInsert(phead, 1);
	DListInsert(phead, 2);
	DListInsert(phead, 3);
	DListdelete(phead->pre);

	DListPrint(phead);
	printf("\n");

}
void text2()
{
	DL* phead = NULL;
	DL* Node;
	phead = initDList(phead);
	DListPushBack(phead, 1);
	DListPushBack(phead, 2);
	DListPushFront(phead, 3);
	DListPushFront(phead, 4);
	DListPopBack(phead);
	DListPopFront(phead);
	DListPrint(phead);
	Node = DListSeek(phead, 1);
	printf("%p", Node);
}
int main()
{
	text2();
	return 0;
}