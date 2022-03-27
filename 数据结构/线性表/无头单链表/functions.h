#pragma once
#include<malloc.h>
#include<stdio.h>
#include<assert.h>
typedef int Elemdata;
typedef struct SListNode
{
	Elemdata e;
	struct SListNode* next;
}SL;
// 动态申请一个节点
SL* BuySListNode(Elemdata x);
// 单链表打印
void SListPrint(SL* plist);
// 单链表尾插
void SListPushBack(SL** pplist, Elemdata x);
// 单链表的头插
void SListPushFront(SL** pplist, Elemdata x);
// 单链表的尾删
void SListPopBack(SL** pplist);
// 单链表头删
void SListPopFront(SL** pplist);
// 单链表查找
SL* SListFind(SL* plist, Elemdata x);
// 单链表在pos位置之前插入x
void SListInsert(SL** pplist, SL* pos, Elemdata x);
// 单链表删除pos位置的值
void SListErase(SL** pplist, SL* pos);