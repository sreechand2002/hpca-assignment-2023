// Optimize this function
void singleThread(int N, int *matA, int *matB, int *output)
{
    // Iterate over output elements
    for(int i = 0; i < 2 * N - 1; ++i) {
        int temp = 0;
        // Iterate over diagonal elements
        for(int j = 0; j < min(i + 1, 2 * N - (i + 1); ++j) {
            int rowA = 
            int colA = 
            int rowB = 
            int colB = 
            temp += matA[rowA * N + colA] * matB[rowB * N + colB];
        }
        output[i] = temp;
    }
}
