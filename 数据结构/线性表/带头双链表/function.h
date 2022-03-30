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
DL* initDList(DL* phead);//��ʼ��
DL* NodeSet(ElemData x);//�����½ڵ�
void DListPrint(DL* phead);//��ӡ˫����Ԫ��
void DListInsert(DL* Node,ElemData x);//��Nodeλ������x
void DListdelete(DL* Node);//ɾ��Nodeλ�õ�Ԫ��
void DListPushFront(DL* phead,ElemData x);//ͷ�巨
void DListPushBack(DL* phead, ElemData x);//β�巨
void DListPopFront(DL* phead);//ͷɾ
void DListPopBack(DL* phead);//βɾ
DL* DListSeek(DL* phead, ElemData x);//����x�ĵ�ַ
