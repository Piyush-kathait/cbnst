#include <stdio.h>
#include <math.h>
#define e 0.02
#define f(x) x *x *x - 4 * x - 9
int main()
{
    float a, b, m, f0, f2, f1;
    int i = 1;
    while (f(i) > 0)
    {
        i++;
    }
    a = f(i);
    i = 1;
    while (f(i) < 0)
    {
        i++;
    }
    b = f(i), i = 0;
    printf("a = %f\nb = %f", a, b);
    do
    {
        f0 = f(a);
        f1 = f(b);
        m = (a + b) / 2;
        f2 = f(m);
        if (f0 * f2 < 0)
        {
            b = m;
        }
        else if (f(m) * f(b) < 0)
        {
            a = m;
        }
        i++;
        printf("step %d\n", i);
        printf("Roots are %f\n", m);
        printf("Value of Function is %f\n", f2);
    } while (fabs(f2) > e);
    return 0;
}
