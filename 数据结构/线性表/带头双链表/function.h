#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
typedef int ElemData;
typedef struct DLNode
{
	ElemData e;
	struct DLNode* pre;
	struct DLNode* next;
}DL;
DL* initDList(DL* phead);//初始化
DL* NodeSet(ElemData x);//创建新节点
void DListPrint(DL* phead);//打印双链表元素
void DListInsert(DL* Node,ElemData x);//再Node位置增加x
void DListdelete(DL* Node);//删除Node位置的元素
void DListPushFront(DL* phead,ElemData x);//头插法
void DListPushBack(DL* phead, ElemData x);//尾插法
void DListPopFront(DL* phead);//头删
void DListPopBack(DL* phead);//尾删
DL* DListSeek(DL* phead, ElemData x);//查找x的地址
