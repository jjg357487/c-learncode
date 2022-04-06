#include"queue.h"
int main()
{
	Q q;
	InitQ(&q);
	PushQ(&q, 1);
	PushQ(&q, 3);
	PushQ(&q, 4);
	PushQ(&q, 2);
	PopQ(&q);
	printf("%d", FrontQ(&q));
	printf("%d", BackQ(&q));
	printf("%d", SizeQ(&q));

	DestroyQ(&q);
	return 0;
}