#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>
#define maxname 20
#define maxgender 5
#define maxtele 13
#define maxaddr 20
typedef struct messagelist
{
	char name[maxname];
	int age;
	char gender[maxgender];
	char tele[maxtele];
	char addr[maxaddr];
}body;
typedef struct contact
{
	body* data;
	int size;
	int capacity;
}contact;
enum option
{
	add = 1,
	pop=2,
	search=3,
	modify=4,
	sort=5,
	show=6,
	save=7,
	Exit=0
};
void initcontact(contact* pp);//初始化
void addcontact(contact* pp);//增
void destroycontact(contact* pp);//销毁
void popcontact(contact* pp);//删
void searchcontact(contact* pp);//查
void modifycontact(contact* pp);//改
void showcontact(contact* pp);//显示
void sortcontact(contact* pp);//排序
int compare(const void* e1, const void* e2);//比较
void addcapacity(contact* pp);
void savecontact(contact* pp);//保存文件
void downcontact(contact* pp);//加载文件