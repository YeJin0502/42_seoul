#include <stdio.h>
#include <stdarg.h>
int sum(int count, ...)
{
	int res = 0;
	va_list ap;
	int i;

	va_start(ap, count);
	for (i = 0; i < count; i++)
	{
		res += va_arg(ap, int);
		printf("res: %d\n", res);
	}
	va_end(ap);
	return (res);
}

int main()
{
	printf("[%d]\n", sum(10, 0,1,2,3,4,5,6,7,8,9));
	return 0;
}