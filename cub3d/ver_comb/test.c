#include <stdio.h>
#include "cub3d.h"

// #define PI 3
double norm_Angle(double angle)
{
	// angle = angle % (2 * PI);
	if (angle < 0)
		angle = angle + 2 * PI;
	while (angle >= 2 * PI)
		angle = angle - 2 * PI;
	return (angle);
}


double point_distance(int x1, int y1, int x2, int y2)
{
	return (sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)));
}

int main()
{
	// printf("%f\n", norm_Angle(1.5*PI));
	printf("%f\n", point_distance(0,0,3,4));
}