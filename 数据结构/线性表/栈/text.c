#include"stack.h"
int main()
{
	ST s;
	bool i;
	InitStack(&s);
	 i = emptyStack(&s);
	if (i == 0)
	{
		printf("сп\n");
	}
	else
		printf("©у\n");
	PushStack(&s, 1);
	PushStack(&s, 2);
	PushStack(&s, 3);
	PushStack(&s, 4);
	PushStack(&s, 5);
	PopStack(&s);
	PopStack(&s);
	printf("%d\n", TopStack(&s));
	printf("%d\n", SizeStack(&s));
	 i = emptyStack(&s);
	if (i == 0)
	{
		printf("сп\n");
	}
	else
		printf("©у\n");
	DestroyStack(&s);
	return 0;
}