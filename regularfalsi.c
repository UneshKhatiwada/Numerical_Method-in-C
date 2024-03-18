#include<stdio.h>
#include<math.h>
#define f(x) cos(x) - x * exp(x)
void main()
{
    float x0,x1,x2,f0,f1,f2,e;
    int step=1;
    up:
    printf("\nEnter the Initial Guesses:\n");
    scanf("%f%f",&x0,&x1);
    printf("Enter tolerable error:\n");
    scanf("%f",&e);
    f0 = f(x0);
    f1 = f(x1);
    if(f0 * f1 > 0)
    {
        printf("Incorrect Initial guesses.");
        goto up;
    }
    printf("\nstep\t\tx0\t\tx1\t\tx2\t\tf2\n");

    do
    {
        x2 = (x0*f1 - x1*f0) / (f1 - f0);
        f2 = f(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n",step, x0, x1, x2, f2);
        if(f0 * f1 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        step=step+1;
    } while (fabs(f2)>e);
    printf("\nThe Root is:%f",x2);
}

