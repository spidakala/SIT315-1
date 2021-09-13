#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <thread>
#include <string>

using namespace std;

#define N 500

int A[N][N];

int B[N][N];

int C[N][N];

void init()
{
    for (i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }
}

void displayMatrices(int mat[N][N])
{
    printf("Matrix\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << mat[i][j] << " ";
        cout  <<  endl;
    }
}

void multiply()
{
    for(int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B [k][j];

}
int main(int argc, char** argv){
    printf ("Matrix Size: %d\n", N);

    struct timeval timecheck;
    double time_elapsed = 0.0;
    gettimeofday(&timecheck, NULL);
    long timeofday_start = (long)timecheck.tv_sec * 1000 +
        (long)timecheck.tv_usec / 1000;

        multiply();

    gettimeofday(&timecheck, NULL);
    long timeofday_end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec
        / 1000; 

    time_elapsed = timeofday_end - timeofday_start;
    printf("time elapsed: %.5f\n", time_elapsed);

    return 0; 
}