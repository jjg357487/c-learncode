#include"queue.h"
void InitQ(Q* p)
{
	assert(p);
	p->head = p->tail = NULL;

}
void DestroyQ(Q* p)
{
	assert(p);
	QN* cur = p->head;
	while (cur)
	{
		QN* nex = cur->next;
		free(cur);
		cur=nex;
		if(nex)
		nex=nex->next;
	}
	p->head = p->tail = NULL;
}
void PushQ(Q* p, ElemData x)
{
	assert(p);
	QN* new = (QN*)malloc(sizeof(QN));
	if (new == NULL)
		printf("%s", strerror(errno));
	new->data = x;
	new->next = NULL;
	if (p->head == NULL)
	{
		p->head = p->tail = new;
	}
	else
	{
		p->tail->next = new;
		p->tail = new;
	}
	
}
void PopQ(Q* p)
{
	assert(p);
	assert(p->tail);
	if (p->head == p->tail)
	{
		free(p->tail);
		p->head = p->tail = NULL;
	}
	else
	{
		QN* waste = p->head;
		p->head = p->head->next;
		free(waste);
		waste = NULL;
	}
}
ElemData FrontQ(Q* p)
{
	assert(p&&p->head);
	return p->head->data;
}
ElemData BackQ(Q* p)
{
	assert(p&&p->tail);
	return p->tail->data;
}
int SizeQ(Q* p)
{
	assert(p);
	QN* tmp = p->head;
	int i=0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return i;
}
bool EmptyQ(Q* p)
{
	assert(p);
	if (p->head == NULL)
	return 1;
	else
	{
		return 0;
	}
}