#include <stdio.h>

#include "cub3d.h"
double norm_angle(double angle)
{
	if (angle < 0)
		angle = angle + 2 * PI;
	if (angle > 2 * PI)
		angle = remainder(angle, 2 * PI); // 이거 다른 함수들 살펴봐야.
	return (angle); // 맞나?
}


int main()
{
	double a;
	a = -0.5*PI;
	printf("(%f, %f)\n", a, norm_angle(a));
}