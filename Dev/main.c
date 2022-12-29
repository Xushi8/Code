#include<stdio.h>
#include<stdlib.h>
 
int main()
{
	int a = 3;
	int* p = &a;
	printf("%d\n%p\n%d\n", a, p, sizeof(p));
	for(int i = 0; i<10; i++)
	{
		printf("%d\n", a);
	}
	return 0;
}
