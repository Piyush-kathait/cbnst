#include <stdio.h>
#include <math.h>
#define MAXN 100
#define ORDER 4
void main()
{
    float ax[MAXN + 1], ay[MAXN], diff[MAXN][ORDER + 1], x, p, h, y1, y2, y3, y4, y;
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
    do
    {
        i++;
    } while (ax[i] < x);
    i--;
    p = (x - ax[i]) / h;
    y1 = p * diff[i][1];
    y2 = p * (p - 1) * diff[i - 1][2] / 2;
    y3 = (p + 1) * p * (p - 1) * diff[i - 2][3] / 6;
    y4 = (p + 1) * p * (p - 1) * (p - 2) * diff[i - 3][4] / 24;
    y = ay[i] + y1 + y2 + y3 + y4;
    printf("\nwhen x=%6.4f,y=%6.8f ", x, y);
}
