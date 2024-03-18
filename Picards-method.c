#include <stdio.h>
#include <math.h>
#define y1(x) 1 + x *y
#define y2(x) 1 + x + pow(x, 2) / 2
#define y3(x) 1 + x + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 8
#define y4(x) 1 + x + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 8 + pow(x, 5) / 15 + pow(x, 6) / 48
void main()
{
    int n, i;
    float h, x0, y0, f1, f2, f3;
    printf("\nIVP:y'=1+x*y\t,y(0)=1\n");
    printf("\nFirst approximation to y=1+x+(1/2)*x^2");
    printf("\nSecond approximation to y=1+x+(1/2)*x^2+(1/3)*x^3+(1/8)*x^4");
    printf("\nThird approximation to y=1+x+(1/2)*x^2+(1/3)*x^3+(1/8)*x^4(1/15)*x^5+(1/48)*x^6");
    printf("\nEnter x:");
    scanf("%f\n", &x0);
    printf("\nEnter step length h:");
    scanf("\n%f", &h);
    printf("Enter number of steps n:");
    scanf("%d\n", &n);
    printf("\nx\t\ty<1st approx>\t\ty<2nd approx>\t\ty<3rd approx>\n");
    for (i = 0; i < n; i++)
    {
        f1 = y2(x0);
        f2 = y3(x0);
        f3 = y4(x0);
        printf("%f\t%f\t%f\t%f\t\n", x0, f1, f2, f3);
        x0 = x0 + h;
    }
}