#include <stdio.h>
#include <math.h>

# define PI 3.1415926535

double norm_angle(double angle)
{
	while (angle < 0)
		angle = angle + 2 * PI;
	if (angle > 2 * PI)
		angle = fmod(angle, 2 * PI); // 이거 다른 함수들 살펴봐야.
	return (angle); // 맞나?
}


int main()
{
	double view;
	view = 540 * PI / 180;
	double norm;
	norm = norm_angle(view);
	printf("%f\n", norm);
}