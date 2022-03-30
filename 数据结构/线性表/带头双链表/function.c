#include"function.h"
DL* initDList(DL* phead)
{
	phead = (DL*)malloc(sizeof(DL));
	phead->e = 0;
	phead->next = phead;
	phead->pre = phead;
	return phead;
}
DL* NodeSet(ElemData x)
{
	DL* NewNode= (DL*)malloc(sizeof(DL));
	NewNode->e = x;
	NewNode->next = NULL;
	NewNode->pre = NULL;
}
void DListInsert(DL* Node, ElemData x)
{
	assert(Node);
	DL* NewNode = NodeSet(x);
	/*DL* prve = Node->pre;
	prve->next = NewNode;
	NewNode->pre = prve;
	NewNode->next = Node;
	Node->pre = NewNode;*/
	Node->pre->next = NewNode;
	NewNode->pre = Node->pre;
	NewNode->next = Node;
	Node->pre = NewNode;
}
void DListPrint(DL* phead)
{
	assert(phead->next!=phead);
	DL* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ",cur->e);
		cur=cur->next;
	}
}
void DListdelete(DL* Node)
{
	assert(Node && Node->next != Node);
	DL* P = Node;
	Node->pre->next = Node->next;
	Node->next->pre = Node->pre;
	free(P);
}
void DListPushFront(DL* phead, ElemData x)//头插法
{
	assert(phead);
	DListInsert(phead->next,x);
}
void DListPushBack(DL* phead, ElemData x)//尾插法
{
	assert(phead);
	DListInsert(phead, x);
}
void DListPopFront(DL* phead)//头删
{
	assert(phead);
	DListdelete(phead->next);
}
void DListPopBack(DL* phead)//尾删
{
	assert(phead);
	DListdelete(phead->pre);
}
DL* DListSeek(DL* phead, ElemData x)//查找x的地址
{
	assert(phead);
	DL* cur = phead->next;
	while (cur != phead)
	{
		if (cur->e == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
