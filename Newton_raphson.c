#include <stdio.h>
#include <math.h>
#define f(x) x *x *x - x - 0001
#define g(x) 3 * x *x - 1
#define e 0.0001
int main()
{
    float x0, x1, f0, f1, g0;
    int i = 0;
    while (f(i) > 0)
    {
        i++;
    }
    int a = i;
    i = 0;
    while (f(i) < 0)
    {
        i++;
    }
    int b = i;
    x0 = (a + b) / 2;
    do
    {
        g0 = g(x0);
        f0 = f(x0);
        x1 = x0 - f0 / g0;
        x0 = x1;
        f1 = f(x1);
        printf("Root is %f\n", x1);
    } while (fabs(f1) > e);
    printf("Root is %f\n", x1);
}
