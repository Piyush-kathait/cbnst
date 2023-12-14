#include <stdio.h>
#include <math.h>
#define f(x) cos(x) - x *exp(x)
#define e 0.0001
int main()
{
    float x0, x1, x2, f0, f1, f2;
    int step = 1;
    int i = 0;
    while (f(i) > 0)
    {
        i++;
    }
    x0 = i;
    f0 = f(x0);
    i = 0;
    while (f(i) < 0)
    {
        i++;
    }
    x1 = i;
    f1 = f(x1);
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\t(x2)\n");
    do
    {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);
        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }

        step = step + 1;
    } while (fabs(f2) > e);
    printf("\nRoot is: %f", x2);
    return 0;
}
