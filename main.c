#include <stdio.h>
#include <stdlib.h>

float const Pi = 3.1415;

int main()
{
	float x=0,y=0,r=0,P=0,S=0;

	printf("Insert coordinates of center and radius of circle,line by line\n");
	scanf("%f",&x);
	scanf("%f",&y);
	scanf("%f",&r);

	P = 2 * Pi * r;
	S = Pi * r * r;

	printf("P = %f\n",P);
	printf("S = %f\n",S);
}
