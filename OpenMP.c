#include  <iostream>
#include<stdio.h>
#include<time.h>
#include<sys/time.h>
#include<unistd.h>
#include<stdlib.h>
#include<thread>
#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

// maximum size of matrix
const int N = 1000;

// maximum number of threads
const int MAX_THREAD = 1000;

int A[N][N]; 
int B[N][N]; 
int C[N][N];


void init(int A[N][N]) 
{
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N{
            A[i][j] = rand() % 10;
        }
    }   
}


void multi_omp()
{
{
    #pragma omp parallel
    {
        #pragma omp for
        for(inti=0;i<N;i++){
            for (int j = 0; j < N; j++){
                for (int k = 0; k < N; k++) {
    }
    C[i][j]  +=  A[i][k]  *  B[k][j];
}

void displayMatrices(int mat[N][N])
{
    printf("Matix\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";    
        cout << endl;
    }
}

int main(int argc, char** argv)
{
    // Generating random values in A and B
    
    init(A);
    init(B);
    
    printf("Threads: %d , Matrix Size: %d\n" , MAX_THREAD , N);
    //starting time interval
    struct timeval timecheck;
    double time_elapsed = 0.0;
    gettimeofday(&timecheck, NULL);
    long timeofday_start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
    
    multi_omp(); 
    
    gettimeofday(&timecheck, NULL);
    long timeofday_end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000; 91
    
    //getting the time took to complete
    time_elapsed = timeofday_end - timeofday_start;
    printf("time elapsed: %.5f\n", time_elapsed);
    
    
    return 0;
}