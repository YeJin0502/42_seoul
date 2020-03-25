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
int main()
{
	// printf("%f\n", norm_Angle(1.5*PI));
	printf("%f, %f, %f\n", (double)FOV_ANGLE, (double)NUM_RAYS, (double)((double)FOV_ANGLE / (double)NUM_RAYS));
}
