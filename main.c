// --------------------------------------------------------------
// LBYARCH S12, 
// Group of Mia Bernice Cruz & Jose Mari Victorio Genuino
// 
// --------------------------------------------------------------
// Project Specs: Dot Product Calculator [x86-64 to C interface]
// --------------------------------------------------------------
// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
// Pre-defined Constants 
#define NUM 30
#define MAX 100.0f

// Dot Product Function 1 [x86_64 Assembly]
extern float dotProduct(int n, float* A, float* B);


// Dot Product Function 2 [C lang]
float cDotProduct(int n, float* A, float* B) {
    
    // initialize sdot to 0 float
    float sdot = 0.0f;

    for (int i = 0; i < n; i++) {
        sdot += A[i] * B[i];
    }

    return sdot;
}


// Generate Random Values into Vectors A and B
void generateRandomVector(int n, float* vector) {

    int count = 0;
    int pow = 1;

    for (int i = 0; i < n; i++) {
        vector[i] = ((float)rand() / (float)(RAND_MAX)) * MAX;
        vector[i] = (int)(vector[i] * MAX) / MAX;

        if (rand() % 2 == 0)
            vector[i] /= -1;

        if (i == pow - 1) {
            printf("%i\n", pow);

            count++;
            pow *= 2;
        }
    }
}

double computeAverageTime(double* timesTaken) {

    double average = 0.0;

    for (int i = 0; i < NUM; i++)
        average += timesTaken[i];

    return average / NUM;
}

// Main Function C
int main()
{
    // Initialize Variables
    int n = 0;
    float* A = (float*)malloc((int)pow(2, 28) * sizeof(float));
    float* B = (float*)malloc((int)pow(2, 28) * sizeof(float));
    float sdot = 0;
    float sdotC = 0;
    float sdotAsm = 0;

    // Times
    clock_t startTime;
    double cTimes[NUM];
    double cAverage;
    double asmTimes[NUM];
    double asmAverage;

    // Generate Vector Values
    srand((unsigned int)time(NULL));
    printf("A =\n");
    generateRandomVector((int)pow(2, 28), A);
    printf("\nDone\n\n");
    printf("B =\n");
    generateRandomVector((int)pow(2, 28), B);
    printf("\nDone\n\n");

    printf("\n======================================================\n");
    printf("\n==========Start of Program ...========================\n");
    printf("\n======================================================\n");
    n = (int)pow(2, 20);
    printf("\nN = 2^20 = %i\n\n", n);

    // Time C Function Call
    printf("C Dot Product Function:\n");
    for (int i = 0; i < NUM; i++) {
        startTime = clock();
        sdot = cDotProduct(n, A, B);
        startTime = clock() - startTime;
        cTimes[i] = ((double)startTime) / CLOCKS_PER_SEC;
    }
    sdotC = sdot;
    cAverage = computeAverageTime(cTimes);
    printf("\tsdot Base10: %f\n", sdotC);
    printf("\tsdot Base16: %x\n", *(unsigned int*)&sdotC);
    printf("\tAverage Time: %lf\n\n", cAverage);

    // Time x86_64 Function Call
    printf("x86_64 Dot Product Function:\n");
    for (int i = 0; i < NUM; i++) {
        startTime = clock();
        sdot = dotProduct(n, A, B);
        startTime = clock() - startTime;
        asmTimes[i] = ((double)startTime) / CLOCKS_PER_SEC;
    }
    sdotAsm = sdot;
    asmAverage = computeAverageTime(asmTimes);
    printf("\tsdot Base10: %f\n", sdotAsm);
    printf("\tsdot Base16: %x\n", *(unsigned int*)&sdotAsm);
    printf("\tAverage Time: %lf\n\n", asmAverage);

    // Results
    printf("Results:\n");
    printf("\tSimilarity: %.2f %%\n", sdotC * 100 / sdotAsm);
    if (asmAverage <= 0)
        printf("\tTime Difference: 0 (0 %% faster)\n");
    else {
        printf("\tTime Difference: %lf ", cAverage - asmAverage);

        if (cAverage > asmAverage)
            printf("(x86_64 is faster by %.2lf times)\n", cAverage / asmAverage);
        else
            printf("(C is faster by %.2lf times)\n", asmAverage / cAverage);
    }



    printf("\n======================================================\n");
    printf("\n==========Start of Program 2...=======================\n");
    printf("\n======================================================\n");

    n = (int)pow(2, 24);
    printf("\nN = 2^24 = %i\n\n", n);

    // Time C Function Call
    printf("C Dot Product Function:\n");
    for (int i = 0; i < NUM; i++) {
        startTime = clock();
        sdot = cDotProduct(n, A, B);
        startTime = clock() - startTime;
        cTimes[i] = ((double)startTime) / CLOCKS_PER_SEC;
    }
    sdotC = sdot;
    cAverage = computeAverageTime(cTimes);
    printf("\tsdot Base10: %f\n", sdotC);
    printf("\tsdot Base16: %x\n", *(unsigned int*)&sdotC);
    printf("\tAverage Time: %lf\n\n", cAverage);

    // Time x86_64 Function Call
    printf("x86_64 Dot Product Function:\n");
    for (int i = 0; i < NUM; i++) {
        startTime = clock();
        sdot = dotProduct(n, A, B);
        startTime = clock() - startTime;
        asmTimes[i] = ((double)startTime) / CLOCKS_PER_SEC;
    }
    sdotAsm = sdot;
    asmAverage = computeAverageTime(asmTimes);
    printf("\tsdot Base10: %f\n", sdotAsm);
    printf("\tsdot Base16: %x\n", *(unsigned int*)&sdotAsm);
    printf("\tAverage Time: %lf\n\n", asmAverage);

    // Results
    printf("Results:\n");
    printf("\tSimilarity: %.2f %%\n", sdotC * 100 / sdotAsm);
    if (asmAverage <= 0)
        printf("\tTime Difference: 0 (0 %% faster)\n");
    else {
        printf("\tTime Difference: %lf ", cAverage - asmAverage);

        if (cAverage > asmAverage)
            printf("(x86_64 is faster by %.2lf times)\n", cAverage / asmAverage);
        else
            printf("(C is faster by %.2lf times)\n", asmAverage / cAverage);
    }

    // Free Memory Allocation
    free(A);
    free(B);

    return 0;
}