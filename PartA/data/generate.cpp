#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define N 1024

int main()
{
    // Set seed
    srand(1);
    
    // Output square matrix size
    cout << N << "\n";
    
    // Generate matrix A
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            cout << rand() % 256 << " ";
        cout << "\n";
    }
    
    // Generate matrix B
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            cout << rand() % 256 << " ";
        cout << "\n";
    }
}
