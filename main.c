#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

extern float dotProduct(float* A, float* B, int n);

int main() {
    int n;
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

    // time
    clock_t start, end;
    start = clock();

    float sdot = dotProduct(A, B, n);

    end = clock();

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Dot Product: %f\n", sdot);
    printf("Time taken: %f seconds\n", time_taken);

    free(A);
    free(B);

    return 0;
}
