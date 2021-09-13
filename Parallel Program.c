#include <iostream>
#include<stdio.h>
#include<time.h>
#include<sys/time.h>
#include<unistd.h>
#include<stdlib.h>
#include <thread>
#include<bits/stdc++.h>
 
using namespace std; 

// maximum size of matrix
const int N = 500;

// maximum number of threads
const int MAX_THREAD = 500;

int A[N][N];
int B[N][N];
int C[N][N];

void* multi(void* arg)
{
    long block_sz = (N + 1) / MAX_THREAD; //how many rows in each thread to process
    long start = (long) arg * block_sz; //where should I start? row 0 , row 500,???
    long end = start + block_sz; //where should I end 30
    if ( end > N ) end = N;
    
    for (int i = start; i < end; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
}

void init(int A[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            A[i][j] = rand() % 10;
            }
        }
}

void displayMatrices(int mat[N][N])
{
    printf("Matix\n");
    for(inti=0;i<MaxSize;i++){
        for (int j = 0; j < MaxSize; j++)
            cout << mat[i][j] << " ";
            
        cout << endl;
    }
}

int main(int argc, char** argv)
{
    init(A);
    init(B);

    printf("Threads: %d, Matrix Size: %d\n" , MAX_THREAD, N); //starting time interval
    struct timeval timecheck;
    double time_elapsed = 0.0;
    gettimeofday(&timecheck, NULL);
    long timeofday_start = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec /1000;

    // declaring threads
    pthread_t* threads = (pthread_t*) malloc(MAX_THREAD * sizeof(pthread_t)); 
    // Creating threads, each evaluating its own part
    for(longi=0;i< MAX_THREAD; i++) {
        pthread_create(&threads[i], NULL, multi, (void*)(i));
        }
    // joining and waiting for all threads to complete
    for (long i = 0; i < MAX_THREAD; i++) pthread_join(threads[i], NULL);
    
    //finish  time  check
    gettimeofday(&timecheck, NULL);
    long timeofday_end = (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
    
    //getting the time took to complete
    time_elapsed = timeofday_end - timeofday_start;
    printf("time elapsed: %.5f\n", time_elapsed);
    
    return 0;
}
