
#include <cuda_runtime.h>


__global__ void cudaSingleThread(int input_row,
                                  int input_col,
                                  int *input,
                                  int kernel_row,
                                  int kernel_col,
                                  int *kernel,
                                  int output_row,
                                  int output_col,
                                  long long unsigned int *output) {

    int output_i = blockIdx.x * blockDim.x + threadIdx.x;
    int output_j = blockIdx.y * blockDim.y + threadIdx.y;

    if (output_i < output_row && output_j < output_col) {
        long long unsigned int outputValue = 0;

        for (int kernel_i = 0; kernel_i < kernel_row; kernel_i++) {
            for (int kernel_j = 0; kernel_j < kernel_col; kernel_j++) {
                int input_i = (output_i + 2 * kernel_i) % input_row;
                int input_j = (output_j + 2 * kernel_j) % input_col;
                outputValue += input[input_i * input_col + input_j] * kernel[kernel_i * kernel_col + kernel_j];
            }
        }

        output[output_i * output_col + output_j] = outputValue;
    }
}


void launchCudaSingleThread(int input_row,
                             int input_col,
                             int *input,
                             int kernel_row,
                             int kernel_col,
                             int *kernel,
                             int output_row,
                             int output_col,
                             long long unsigned int *output) {

    int *d_input, *d_kernel;
    long long unsigned int *d_output;

    cudaMalloc((void**)&d_input, input_row * input_col * sizeof(int));
    cudaMalloc((void**)&d_kernel, kernel_row * kernel_col * sizeof(int));
    cudaMalloc((void**)&d_output, output_row * output_col * sizeof(long long unsigned int));

   
    cudaMemcpy(d_input, input, input_row * input_col * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_kernel, kernel, kernel_row * kernel_col * sizeof(int), cudaMemcpyHostToDevice);

 
    dim3 blockSize(16, 16);  
    dim3 gridSize((output_row + blockSize.x - 1) / blockSize.x, (output_col + blockSize.y - 1) / blockSize.y);

  
    cudaSingleThread<<<gridSize, blockSize>>>(input_row, input_col, d_input, kernel_row, kernel_col, d_kernel, output_row, output_col, d_output);

   
    cudaMemcpy(output, d_output, output_row * output_col * sizeof(long long unsigned int), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(d_input);
    cudaFree(d_kernel);
    cudaFree(d_output);
}
