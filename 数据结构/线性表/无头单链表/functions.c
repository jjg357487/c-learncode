#include"functions.h"

SL* BuySListNode(Elemdata x)// ��̬����һ���ڵ�
{
	SL* Node = (SL*)malloc(sizeof(SL));
	Node->e = x;
	Node->next = NULL;
	return Node;
}

void SListPrint(SL* plist)// �������ӡ
{
	assert(plist);
	while (plist)
	{
		printf("%d ", plist->e);
		plist = plist->next;
	}

}

void SListPushBack(SL** pplist, Elemdata x)// ������β��
{
	SL* Node = BuySListNode(x);
	if(*pplist==NULL)
	*pplist = Node;
	else
	{
		SL* tail = *pplist;
		while (tail->next)
			tail = tail->next;
		tail->next = Node;
	}
}

void SListPushFront(SL** pplist, Elemdata x)// �������ͷ��
{
	SL* Node = BuySListNode(x);
	if (*pplist == NULL)
		*pplist = Node;
	else
	{
		Node->next = *pplist;
		*pplist = Node;
	}

}

void SListPopBack(SL** pplist)// �������βɾ
{
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SL* tail = *pplist;
		while ((tail->next)->next)
			tail = tail->next;
		free(tail->next);
		tail->next = NULL;
	}
}

void SListPopFront(SL** pplist)// ������ͷɾ
{
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SL* q = *pplist;
		*pplist = (*pplist)->next;
		free(q);
	}
}

SL* SListFind(SL* plist, Elemdata x)// ���������
{
	assert(plist);
	while (plist)
	{
		if (plist->e == x)
			return plist;
		else
			plist = plist->next;
	}
	return NULL;
}

void SListInsert(SL** pplist, SL* pos, Elemdata x)// ��������posλ��֮ǰ����x
{
	assert(pos);
	if (*pplist == NULL)
	{
		pos->next = NULL;
		pos->e = x;
		*pplist = pos;
	}
	else
	{
		Elemdata tmp;
		SL* Node = BuySListNode(x);
		Node->next = pos->next;
		pos->next = Node;
		tmp = pos->e;
		pos->e = Node->e;
		Node->e = tmp;
	}


}

void SListErase(SL** pplist, SL* pos)// ������ɾ��posλ�õ�ֵ
{
	assert(pos);
	assert(*pplist);
	SL* tail = *pplist;
	while ((tail->next)->next)
		tail = tail->next;
	if ((*pplist)->next == NULL && *pplist == pos)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else if (pos==tail->next)
	{
		tail->next = NULL;
		free(pos);
	}
	else
	{
		SL* p = pos->next;
		pos->next = p->next;
		pos->e = p->e;
		free(p);
	}
}