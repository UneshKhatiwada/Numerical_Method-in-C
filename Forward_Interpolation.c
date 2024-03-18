#include <stdio.h> 
void forward(float x[4], float y[4][4], int n); 
int main() 
{ 
    int i, j; 
    int n = 4;  
    float x[4] = { 0, 1, 2, 3 }; 
    float y[4][4] = { 
        { 1, 3, 0, 0 }, 
        { 0, 0, 0, 0 }, 
        { 1, 4, 0, 0 }, 
        { 9, 0, 0, 0 },     };

  
    forward(x, y, n);   
    return 0; 
} 
void forward(float x[4], float y[4][4], int n) 
{ 
    int i, j; 
    float a = 0.5; 
    float h, u, sum, p; 
    for (j = 1; j < n; j++) { 
        for (i = 0; i < n - j; i++) { 
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1]; 
        } 
    } 
    printf("\n The forward difference table is:\n"); 
    for (i = 0; i < n; i++) { 
        printf("\n"); 
        for (j = 0; j < n - i; j++) { 
            printf("%f\t", y[i][j]); 
        } 
    } 
    p = 1.0; 
    sum = y[0][0]; 
    h = x[1] - x[0]; 
    u = (a - x[0]) / h; 
    for (j = 1; j < n; j++) { 
        p = p * (u - j + 1) / j; 
        sum = sum + p * y[0][j]; 
    } 
 printf("\nThe value of y at x=%0.1f is %0.3f", a, sum); 
 } 
