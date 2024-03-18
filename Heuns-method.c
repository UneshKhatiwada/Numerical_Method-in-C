#include <stdio.h>
float f(float x)
{
    return (6 * x + 2);
}
int main()
{
    int i;
    float xf, x, y, ye, h, k1, k2, n;
    printf("Enter x and y values: ");
    scanf("%f %f", &x, &y);
    printf("Enter stepsize: ");
    scanf("%f", &h);
    printf("Enter final x value: ");
    scanf("%f", &xf);
    n = (xf - x) / h;
    for (i = 1; i <= n; i++)
    {
        k1 = f(x);
        printf("k1 = %f\n", k1);
        ye = y + k1 * h;
        k2 = f(x + h);
        y = y + ((k1 + k2) / 2) * h;
        x += h;
        printf("%f %f\n", x, y);
    }
    return 0;
}