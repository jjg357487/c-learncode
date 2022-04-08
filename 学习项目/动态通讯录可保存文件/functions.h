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
void initcontact(contact* pp);//��ʼ��
void addcontact(contact* pp);//��
void destroycontact(contact* pp);//����
void popcontact(contact* pp);//ɾ
void searchcontact(contact* pp);//��
void modifycontact(contact* pp);//��
void showcontact(contact* pp);//��ʾ
void sortcontact(contact* pp);//����
int compare(const void* e1, const void* e2);//�Ƚ�
void addcapacity(contact* pp);
void savecontact(contact* pp);//�����ļ�
void downcontact(contact* pp);//�����ļ�