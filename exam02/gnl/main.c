
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char *line;

	while (get_next_line(&line) > 0)
	{
		printf("[[ %s ]]\n", line);
		free(line);
	}
}
