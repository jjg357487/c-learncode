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
// ��̬����һ���ڵ�
SL* BuySListNode(Elemdata x);
// �������ӡ
void SListPrint(SL* plist);
// ������β��
void SListPushBack(SL** pplist, Elemdata x);
// �������ͷ��
void SListPushFront(SL** pplist, Elemdata x);
// �������βɾ
void SListPopBack(SL** pplist);
// ������ͷɾ
void SListPopFront(SL** pplist);
// ���������
SL* SListFind(SL* plist, Elemdata x);
// ��������posλ��֮ǰ����x
void SListInsert(SL** pplist, SL* pos, Elemdata x);
// ������ɾ��posλ�õ�ֵ
void SListErase(SL** pplist, SL* pos);