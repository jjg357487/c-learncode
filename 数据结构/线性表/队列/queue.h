#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
typedef int ElemData;
typedef struct QueueNOde
{
	ElemData data;
	struct queue* next;
}QN;
typedef struct Queue
{
	QN* head;
	QN* tail;
}Q;
void InitQ(Q* p);
void DestroyQ(Q* p);
void PushQ(Q* p, ElemData x);
void PopQ(Q* p);
ElemData FrontQ(Q* p);
ElemData BackQ(Q* p);
int SizeQ(Q* p);
bool EmptyQ(Q* p);