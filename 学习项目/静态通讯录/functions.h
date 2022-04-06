#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define maxname 20
#define maxgender 5
#define maxtele 13
#define maxaddr 20
#define max 100
struct messagelist
{
	char name[maxname];
	int age;
	char gender[maxgender];
	char tele[maxtele];
	char addr[maxaddr];
};
typedef struct contact
{
	struct messagelist member[max];
	int size;
}contact;
enum option
{
	add = 1,
	pop=2,
	search=3,
	modify=4,
	sort=5,
	show=6,
	exit=0
};
void initcontact(contact* pp);//≥ı ºªØ
void addcontact(contact* pp);
void destroycontact(contact* pp);
void searchcontact(contact* pp);
void modifycontact(contact* pp);
void showcontact(contact* pp);
void sortcontact(contact* pp);
int compare(const void* e1, const void* e2);