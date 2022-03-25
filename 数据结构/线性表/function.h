#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef int Elemtype;//数据类型
typedef struct SeqList
{
	Elemtype* date;
	int size;
	int capacity;
}SL;
void ListInit(SL* List);//初始化顺序表
void ListDestroy(SL* List);//销毁
void Addcapacity(SL* List);//增容
void ListPrint(SL* List);//打印


//增
void ListInsert(SL* List, int i, Elemtype x);//插入函数
void ListHomeInsert(SL* List,Elemtype x);//头插法
void ListEndInsert(SL* List, Elemtype x);//尾插法


//删
void ListDelete(SL* List, int i);//删除
void ListHomeDelete(SL* List);//头删除
void ListEndDelete(SL* List);//尾删除


//查
Elemtype ListSearch_byi(SL* List, int i);//按位查找
int ListSearch_byx(SL* List, Elemtype x);//按值查找


//改
void ListModify(SL* List, int i, Elemtype x);//修改第i个数为x