#include"functions.h"
void initcontact(contact* pp)
{
	assert(pp);
	pp->data = (body*)malloc(4 * sizeof(body));
	if (pp->data == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	pp->size = 0;
	pp->capacity = 4;
	downcontact(pp);
}
void downcontact(contact* pp)
{
	assert(pp);
	FILE* pf = fopen("contactmember.dat", "r");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	while (fread(&pp->data[pp->size],sizeof(body),1,pf))
	{
		addcapacity(pp);
		pp->size++;
	}
	fclose(pf);
	pf = NULL;
}
void destroycontact(contact* pp)
{
	assert(pp);
	free(pp->data);
	pp->data = NULL;
	pp->size = pp->capacity = 0;
}
void showcontact(contact* pp)
{
	int i = 0;
	if (pp->size == 0)
	{
		printf("没有数据\n");
		return;
	}
	printf("%-20s\t%-6s\t%-5s\t%-13s\t%-20s\n","姓名","年龄","性别","电话","地址");
	for (i = 0; i < pp->size; i++)
		printf("%-20s\t%-6d\t%-5s\t%-13s\t%-20s\n", pp->data[i].name, pp->data[i].age, pp->data[i].gender, pp->data[i].tele, pp->data[i].addr);
	
}
void addcapacity(contact* pp)
{
	assert(pp);
	if (pp->size == pp->capacity)
	{
		body* tmp = (body*)realloc(pp->data, 2 * pp->capacity * sizeof(body));
		if (tmp == NULL)
		{
			printf("%s", strerror(errno));
			return;
		}
		pp->data = tmp;
		pp->capacity *= 2;
		printf("扩容成功\n");
	}
}
void addcontact(contact* pp)
{
	assert(pp);
	addcapacity(pp);
	printf("请输入姓名;<");
	scanf("%s", pp->data[pp->size].name);
	printf("请输入年龄;<");
	scanf("%d", &pp->data[pp->size].age);
	printf("请输入性别;<");
	scanf("%s", pp->data[pp->size].gender);
	printf("请输入电话;<");
	scanf("%s", pp->data[pp->size].tele);
	printf("请输入地址;<");
	scanf("%s", pp->data[pp->size].addr);
	pp->size=pp->size+1;
}
void popcontact(contact* pp)
{
	assert(pp);
	assert(pp->size > 0);
	int i = 0;
	char dname[maxname] = "";
	printf("请输入要删除人的名字");
	scanf("%s", dname);
	for (i = 0; i < pp->size; i++)
	{
		if (strcmp(dname, pp->data[i].name) == 0)
		{
			int j = 0;
			for (j = i; j < pp->size-1; j++)
			{
				pp->data[j] = pp->data[j + 1];
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
		if (strcmp(pp->data[i].name, search_name) == 0)
		{
			printf("%-20s\t%-6s\t%-5s\t%-13s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-20s\t%-6d\t%-5s\t%-13s\t%-20s\n", pp->data[i].name, pp->data[i].age, pp->data[i].gender, pp->data[i].tele, pp->data[i].addr);
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
		if (strcmp(pp->data[i].name, search_name) == 0)
		{
			printf("请输入姓名;<");
			scanf("%s", pp->data[i].name);
			printf("请输入年龄;<");
			scanf("%d", &pp->data[i].age);
			printf("请输入性别;<");
			scanf("%s", pp->data[i].gender);
			printf("请输入电话;<");
			scanf("%s", pp->data[i].tele);
			printf("请输入地址;<");
			scanf("%s", pp->data[i].addr);
			return;
		}
	}
	printf("输入的找不到\n");
}
void sortcontact(contact* pp)
{
	assert(pp);
	assert(pp->size > 0);
	qsort(pp->data, pp->size, sizeof(struct messagelist), compare);
}
int compare(const void* e1, const void* e2)
{
	return strcmp(((struct messagelist*)e1)->name, ((struct messagelist*)e2)->name);
}
void savecontact(contact* pp)
{
	assert(pp);
	int i = 0;
	FILE* pf = fopen("contactmember.dat","w");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	for (i = 0; i < pp->size; i++)
	{
		fwrite(&(pp->data[i]), sizeof(body), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}