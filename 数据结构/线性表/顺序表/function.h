#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef int Elemtype;//��������
typedef struct SeqList
{
	Elemtype* date;
	int size;
	int capacity;
}SL;
void ListInit(SL* List);//��ʼ��˳���
void ListDestroy(SL* List);//����
void Addcapacity(SL* List);//����
void ListPrint(SL* List);//��ӡ


//��
void ListInsert(SL* List, int i, Elemtype x);//���뺯��
void ListHomeInsert(SL* List,Elemtype x);//ͷ�巨
void ListEndInsert(SL* List, Elemtype x);//β�巨


//ɾ
void ListDelete(SL* List, int i);//ɾ��
void ListHomeDelete(SL* List);//ͷɾ��
void ListEndDelete(SL* List);//βɾ��


//��
Elemtype ListSearch_byi(SL* List, int i);//��λ����
int ListSearch_byx(SL* List, Elemtype x);//��ֵ����


//��
void ListModify(SL* List, int i, Elemtype x);//�޸ĵ�i����Ϊx