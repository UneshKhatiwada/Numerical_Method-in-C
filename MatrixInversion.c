#include<stdio.h>
#include<math.h>
#define SIZE 10
int main()	
{
    float a[SIZE][SIZE * 2], ratio;
    int i, j, k, n;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    printf("Enter coefficients of Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    /* Augmenting Identity Matrix of Order n */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {           if (i == j)
            {
                a[i][j + n] = 1;
            }
            else
            {
                a[i][j + n] = 0;
            }
        }
    }
    /* Applying Gauss Jordan Elimination */
    for (i = 0; i < n; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            return 1;
        }
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < 2 * n; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }      }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = n; j < 2 * n; j++)
        {
            a[i][j] = a[i][j] / a[i][i];
        }
    }
    printf("\nInverse Matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = n; j < 2 * n; j++)
        {
            printf("%0.3f\t", a[i][j]);
        }
        printf("\n");
    }
return 0;
}
