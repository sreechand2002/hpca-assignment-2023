#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    int N; 
    if (argc < 2) 
        N = 8192;
    else 
        N = atoi(argv[1]); 
    ofstream ofile; 
    string file_name = "data/input_" + to_string(N) + ".in";  
    ofile.open(file_name); 

    // Set seed
    srand(1);
    
    // Output square matrix size
    ofile << N << "\n"; 
    // Generate matrix A
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            ofile << rand() % 256 << " ";
        ofile << "\n";
    }
    
    // Generate matrix B
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            ofile << rand() % 256 << " ";
        ofile << "\n";
    }
}
