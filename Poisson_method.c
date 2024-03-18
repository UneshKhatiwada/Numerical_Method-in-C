#include <stdio.h>
#include <math.h>
#define NX 4   // Number of grid points in x direction (including boundaries)
#define NY 4   // Number of grid points in y direction (including boundaries)
#define MAX_ITER 10000 // Maximum number of iterations
#define TOLERANCE 1e-5 // Tolerance for convergence

double f(double x, double y) {
    // Source term function
    return -81 * x * y;
}

int main() {
    double dx = 1.0 / (NX - 1);
    double dy = 1.0 / (NY - 1);
    double h = dx * dy;

    double u[NX][NY]; // Solution array
    double u_old[NX][NY]; // Previous solution array

    // Initialize solution arrays
    for (int i = 0; i < NX; i++) {
        for (int j = 0; j < NY; j++) {
            u[i][j] = 0.0;
            u_old[i][j] = 0.0;
        }
    }

    // Boundary conditions
    for (int j = 0; j < NY; j++) {
        u[0][j] = 0.0;  // Left boundary condition
        u[NX - 1][j] = 100.0;  // Right boundary condition
    }

    for (int i = 0; i < NX; i++) {
        u[i][0] = 0.0;  // Bottom boundary condition
        u[i][NY - 1] = 100.0;  // Top boundary condition
    }

    // Iterative solution using finite difference method
    int iter = 0;
    double error = 1.0;
    while (iter < MAX_ITER && error > TOLERANCE) {
        error = 0.0;
        // Jacobi iteration
        for (int i = 1; i < NX - 1; i++) {
            for (int j = 1; j < NY - 1; j++) {
                u_old[i][j] = u[i][j];
                u[i][j] = 0.25 * (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1] - h * f(i * dx, j * dy));
                error += fabs(u[i][j] - u_old[i][j]);
            }
        }
        error /= (NX - 2) * (NY - 2);
        iter++;
    }
    printf("Interior Points:\n");
    printf("x\t\t y\t\t u(x, y)\n");
    for (int j = NY - 2; j > 0; j--) { 
        for (int i = 1; i < NX - 1; i++) { 
            printf("%.5f\t %.5f\t %.5f\n", i * dx, j * dy, u[i][j]);
        }
    }

    return 0;
}
