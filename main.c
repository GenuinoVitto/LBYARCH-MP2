#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

extern void dotProduct(float* A, float* B, int n, float* sdot);

int main() {
    int n = 0;
    printf("Enter the length of the vectors: ");
    scanf_s("%d", &n);

    float* A = (float*)malloc(n * sizeof(float));
    float* B = (float*)malloc(n * sizeof(float));

    printf("Enter the elements of vector A:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%f", &A[i]);
    }

    printf("Enter the elements of vector B:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%f", &B[i]);
    }

    // Allocate memory to store the result
    float sdot;

    // Time measurement
    clock_t start, end;
    start = clock();

    // Call the assembly function
    dotProduct(A, B, n, &sdot);

    end = clock();

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Dot Product: %f\n", sdot);
    printf("Time taken: %f seconds\n", time_taken);

    free(A);
    free(B);

    return 0;
}
