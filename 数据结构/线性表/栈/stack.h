#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
typedef int ElemData;
typedef struct stack
{
	ElemData* i;
	int top;
	int capacity;
}ST;
void InitStack(ST* p);
void DestroyStack(ST* p);
void PushStack(ST* p, ElemData x);
void PopStack(ST* p);
ElemData TopStack(ST* p);
int SizeStack(ST* p);
bool emptyStack(ST* p);