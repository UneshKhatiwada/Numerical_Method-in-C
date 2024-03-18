#include <stdio.h> 
void BackWard(float x[4], float y[4][4], int n); 
int main() 
{ 
    int i, j; 
    int n = 4; 
    float x[4] = { 0, 1, 2, 3 }; 
    float y[4][4] = { 
        { 5, 0, 0, 0 }, 
        { 8, 0, 0, 0 }, 
        { 6, 0, 0, 0 }, 
        { 10, 0, 0, 0 }, 
    }; 
    BackWard(x, y, n);   
    return 0; 
} 
void BackWard(float x[4], float y[4][4], int n) 
{ 
    int i, j; 
    float a = 0.5;  
    float h, u, sum, p; 
    for (j = 1; j < n; j++) { 
        for (i = j; i < n; i++) { 
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1]; 
        } 
    } 
    printf("\nThe backward difference table is:\n"); 
    for (i = 0; i < n; i++) { 
        printf("\n"); 
        for (j = 0; j <= i; j++) { 
            printf("%f\t", y[i][j]); 
        } 
    } 
  
    p = 1.0; 
    sum = y[n - 1][0]; 
    h = x[1] - x[0]; 
    u = (a - x[n - 1]) / h; 
    for (j = 1; j < n; j++) { 
        p = p * (u + j - 1) / j; 
        sum = sum + p * y[n - 1][j];     } 
  
    printf("\nThe value of y at x=%0.1f is %0.3f", a, sum); 
    }
