
#include <stdio.h>

void pp(int i)
{
	printf("%d\n",i);
}

int main()
{
	static int a = 1;

	pp(a);
}