#include<stdio.h>
#include<math.h>
#define e 0.0002
#define f(x) x*x*x - x*x - 1
#define g(x) 1/pow((1+x),0.5)
int main()
{
	float x0,x1,x2,x,m;
	int i=0;
	int a = pow(2,3);
	while(f(i)>0)
	{
		i++;
	}
	x0 = i;
	i=0;
	while(f(i)<0)
	{
		i++;
	}
	x1 = 1,x2 = (x1+x0)/2;
	do
	{	m = x;
		x = g(x2);
		printf("Root is  %f\n",x);
		x2 = x;
	}while(m!=x);
	printf("Final Root is  %f\n",x);
}
