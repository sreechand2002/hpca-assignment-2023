#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std;

#include "single_thread.h"
#include "multi_thread.h"

int main()
{
    // Input size of square matrices
    int N;
    cin >> N;
    cout << "Input matrix of size " << N << "\n";
    
    // Input matrix A
    int *matA = new int[N * N];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> matA[i * N + j];

    // Input matrix B
    int *matB = new int[N * N];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> matB[i * N + j];

    clock_t begin, end; 
    
    // Execute single thread
    int *output_single = new int[2 * N - 1];
    begin = clock();
    singleThread(N, matA, matB, output_single);
    end = clock();
    cout << "Single thread execution time: " << double(end - begin) / (double)CLOCKS_PER_SEC << " seconds\n";
    
    // Execute multi-thread
    int *output_multi = new int[2 * N - 1];
    begin = clock();
    multiThread(N, matA, matB, output_multi);
    end = clock();
    cout << "Multi-threaded execution time: " << double(end - begin) / (double)CLOCKS_PER_SEC << " seconds\n";
    
    for(int i = 0; i < 2 * N - 1; ++i)
        if(output_single[i] != output_multi[i]) {
            printf("Mismatch at %d\n", i);
            exit(1);
        }
}
