#include <stdio.h>
#include <math.h>
#define MAXN 100
#define ORDER 4
void main()
{
    float ax[MAXN + 1], ay[MAXN], diff[MAXN][ORDER + 1], sum, fun, y0, x0, x, p, h, yp;
    int n, i, j, k;
    printf("\nEnter the value of n:\n");
    scanf("%d", &n);
    printf("\nEnter the values in form x,y:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &ax[i], &ay[i]);
    }
    printf("\nEnter the value of x for");
    printf("\nwhich you want the value of y - ");
    scanf("%f", &x);
    h = ax[1] - ax[0];
    for (i = 0; i < n - 1; i++)
    {
        diff[i][1] = ay[i + 1] - ay[i];
    }
    for (j = 2; j <= 4; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }
    i = 0;
    while (!ax[i] > x)
    {
        i++;
    }
    x0 = ax[i];
    sum = 0;
    y0 = ay[i];
    fun = 1;
    p = (x - x0) / h;
    sum = y0;
    for (k = 1; k <= 4; k++)
    {
        fun = (fun * (p - (k - 1))) / k;
        sum = sum + fun * diff[i][k];
    }
    printf("\nwhen x=%0.4f,y=%0.8f", x, sum);
}
