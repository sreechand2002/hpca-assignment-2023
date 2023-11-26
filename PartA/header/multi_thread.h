#include <pthread.h>
#include <iostream>
#include <pthread.h>
 
struct ThreadArgs {
    int input_row;
    int input_col;
    int* input;
    int kernel_row;
    int kernel_col;
    int* kernel;
    int output_row;
    int output_col;
    long long unsigned int* output;
    int thread_id;
    int num_threads;
};
 
void* threadFunction(void* threadArgs) {
    ThreadArgs* args = static_cast<ThreadArgs*>(threadArgs);
 
   
    int chunk_size = args->output_row / args->num_threads;
    int start_row = args->thread_id * chunk_size;
    int end_row = (args->thread_id == args->num_threads - 1) ? args->output_row : (args->thread_id + 1) * chunk_size;
 

    int val1,val2,outputValue=0,input_i,input_j;
    for (int output_i = start_row; output_i < end_row; ++output_i) {
        for (int output_j = 0; output_j < args->output_col; ++output_j) {
         outputValue=0;
            for (int kernel_i = 0; kernel_i < args->kernel_row; ++kernel_i) {
                val1 = output_i + (kernel_i+kernel_i);
                if (val1 < args->input_row)
                    input_i = val1;
                else
                    input_i = val1 - args->input_row * (val1/args->input_row);
                for (int kernel_j = 0; kernel_j < args->kernel_col; kernel_j++) {
                    val2 = output_j + (kernel_j+kernel_j);
                    if(val2 < args->input_col)
                        input_j = val2;
                    else
                        input_j = val2 - args->input_col*(val2/args->input_col);
                    outputValue += args->input[input_i * args->input_col + input_j] * args->kernel[kernel_i * args->kernel_col + kernel_j];
                }
            }
            args->output[output_i * args->output_col + output_j] = outputValue;
        }
    }
 
    pthread_exit(nullptr);
}
 
void parallelThread(int input_row,
                    int input_col,
                    int* input,
                    int kernel_row,
                    int kernel_col,
                    int* kernel,
                    int output_row,
                    int output_col,
                    long long unsigned int* output,
                    int num_threads) {
    pthread_t threads[num_threads];
    ThreadArgs threadArgs[num_threads];
 
   
    for (int i = 0; i < num_threads; ++i) {
        threadArgs[i] = {input_row, input_col, input, kernel_row, kernel_col, kernel, output_row, output_col, output, i, num_threads};
        pthread_create(&threads[i], nullptr, threadFunction, &threadArgs[i]);
    }
 
 
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], nullptr);
    }
}
 
 
void multiThread(int input_row,
                 int input_col,
                 int *input,
                 int kernel_row,
                 int kernel_col,
                 int *kernel,
                 int output_row,
                 int output_col,
                 long long unsigned int *output) {
    const int num_threads = 8;
    std::cout<<"Number of threads : "<<num_threads<<std::endl;
 
    // Call the parallelized function
    parallelThread(input_row, input_col, input, kernel_row, kernel_col, kernel, output_row, output_col, output, num_threads);
 
}


// Fill in this function
// void multiThread( int input_row, 
//                 int input_col,
//                 int *input, 
//                 int kernel_row, 
//                 int kernel_col, 
//                 int *kernel,
//                 int output_row, 
//                 int output_col, 
//                 long long unsigned int *output ) 
// {


    
// }



