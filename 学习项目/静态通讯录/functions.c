#include"functions.h"
void initcontact(contact* pp)
{
	memset(pp->member, 0, sizeof(pp->member));
	pp->size = 0;
}
void showcontact(contact* pp)
{
	int i = 0;
	if (pp->size == 0)
	{
		printf("没有数据");
		return;
	}
	printf("%-20s\t%-6s\t%-5s\t%-13s\t%-20s\n","姓名","年龄","性别","电话","地址");
	for (i = 0; i < pp->size; i++)
		printf("%-20s\t%-6d\t%-5s\t%-13s\t%-20s\n", pp->member[i].name, pp->member[i].age, pp->member[i].gender, pp->member[i].tele, pp->member[i].addr);
	
}
void addcontact(contact* pp)
{
	assert(pp);
	printf("请输入姓名;<");
	scanf("%s", pp->member[pp->size].name);
	printf("请输入年龄;<");
	scanf("%d", &pp->member[pp->size].age);
	printf("请输入性别;<");
	scanf("%s", pp->member[pp->size].gender);
	printf("请输入电话;<");
	scanf("%s", pp->member[pp->size].tele);
	printf("请输入地址;<");
	scanf("%s", pp->member[pp->size].addr);
	pp->size=pp->size+1;
}
void destroycontact(contact* pp)
{
	assert(pp);
	assert(pp->size > 0);
	int i = 0;
	char dname[maxname] = "";
	printf("请输入要删除人的名字");
	scanf("%s", dname);
	for (i = 0; i < pp->size; i++)
	{
		if (strcmp(dname, pp->member[i].name) == 0)
		{
			int j = 0;
			for (j = i; j < pp->size-1; j++)
			{
				pp->member[j] = pp->member[j + 1];
			}
			pp->size--;
			return;
		}
	}
	printf("您输入的名字没有\n");
}
void searchcontact(contact* pp)
{
	assert(pp);
	assert(pp->size > 0);
	char* search_name[maxname] = {0};
	printf("请输入要查找人的姓名:<");
	scanf("%s", search_name);
	for (int i = 0; i < pp->size; i++)
	{
		if (strcmp(pp->member[i].name, search_name) == 0)
		{
			printf("%-20s\t%-6s\t%-5s\t%-13s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-20s\t%-6d\t%-5s\t%-13s\t%-20s\n", pp->member[i].name, pp->member[i].age, pp->member[i].gender, pp->member[i].tele, pp->member[i].addr);
			return;
		}
	}
	printf("输入的找不到\n");
}
void modifycontact(contact* pp)
{
	assert(pp);
	assert(pp->size > 0);
	char* search_name[maxname] = { 0 };
	printf("请输入要修改人的姓名:<");
	scanf("%s", search_name);
	for (int i = 0; i < pp->size; i++)
	{
		if (strcmp(pp->member[i].name, search_name) == 0)
		{
			printf("请输入姓名;<");
			scanf("%s", pp->member[i].name);
			printf("请输入年龄;<");
			scanf("%d", &pp->member[i].age);
			printf("请输入性别;<");
			scanf("%s", pp->member[i].gender);
			printf("请输入电话;<");
			scanf("%s", pp->member[i].tele);
			printf("请输入地址;<");
			scanf("%s", pp->member[i].addr);
			return;
		}
	}
	printf("输入的找不到\n");
}
void sortcontact(contact* pp)
{
	assert(pp);
	assert(pp->size > 0);
	qsort(pp->member, pp->size, sizeof(struct messagelist), compare);
}
int compare(const void* e1, const void* e2)
{
	return strcmp(((struct messagelist*)e1)->name, ((struct messagelist*)e2)->name);
}