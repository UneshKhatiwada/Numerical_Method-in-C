#include <stdio.h>
#include <math.h>
float f(float x, float y, float z) {
    return z; 
}
float g(float x, float y, float z) {
    return y;
}
float rk4(float x0, float y0, float z0, float h, float xf) {
    float k1, k2, k3, k4, l1, l2, l3, l4;
    float x = x0, y = y0, z = z0;

    while (x < xf) {
        k1 = h * f(x, y, z);
        l1 = h * g(x, y, z);
        k2 = h * f(x + h / 2, y + k1 / 2, z + l1 / 2);
        l2 = h * g(x + h / 2, y + k1 / 2, z + l1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2, z + l2 / 2);
        l3 = h * g(x + h / 2, y + k2 / 2, z + l2 / 2);
        k4 = h * f(x + h, y + k3, z + l3);
        l4 = h * g(x + h, y + k3, z + l3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        z = z + (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        x += h;
    }
    return y; 
}
int main() {
    float x0, xf, h, y0, yn, y_guess, z0, z_guess, tol;
    
    printf("Enter initial value of x: ");
    scanf("%f", &x0);
    
    printf("Enter final value of x: ");
    scanf("%f", &xf);
    
    printf("Enter step size h: ");
    scanf("%f", &h);
    
    printf("Enter initial y(0) guess: ");
    scanf("%f", &y_guess);

    printf("Enter initial y'(0) guess: ");
    scanf("%f", &z_guess);

    printf("Enter tolerance: ");
    scanf("%f", &tol);

    int iter = 0;
    float error;

    do {
        y0 = rk4(x0, y_guess, z_guess, h, xf);
        error = y0 - yn;
        z_guess -= error / (y0 - y_guess) * z_guess;

        iter++;
    } while (fabs(error) > tol && iter < 1000);

    printf("Solution found after %d iterations:\n", iter);
    printf("y(%f) = %f\n", xf, y0);

    return 0;
}

