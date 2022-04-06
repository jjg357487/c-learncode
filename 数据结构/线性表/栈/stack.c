#include"stack.h"
void InitStack(ST* p)
{
	assert(p);
	p->i = (ElemData*)malloc(sizeof(ElemData) * 4);
	p->top = 0;
	p->capacity = 4;
}
void DestroyStack(ST* p)
{
	assert(p);
	free(p->i);
	p->top = 0;
	p->capacity = 0;
}
void PushStack(ST* p, ElemData x)
{
	assert(p);
	if (p->top == p->capacity)
	{
		ElemData* tmp = (ElemData*)realloc(p->i, 2 * (p->capacity) * sizeof(ElemData));
		if (tmp == NULL)
		{ 
			printf("%s",strerror(errno));
			return;
		}
		p->capacity *= 2;
		p->i = tmp;
	}
	p->i[p->top] = x;
	p->top++;
}
void PopStack(ST* p)
{
	assert(p);
	assert(p->top > 0);
	p->top--;
}
ElemData TopStack(ST* p)
{
	assert(p);
	assert(p->top > 0);
	return p->i[p->top-1];
}
int SizeStack(ST* p)
{
	assert(p);
	return p->top;
}
bool emptyStack(ST* p)
{
	assert(p);
	return !p->top;
}