// Optimize this function

void singleThread(register int input_row,
                  register int input_col,
                  register int *input,
                  register int kernel_row,
                  register int kernel_col,
                  register int *kernel,
                  register int output_row,
                  register int output_col,
                  register long long unsigned int *output) {

    register int input_i,input_j,val1,val2;
    int *inputPtr = input;
    long long unsigned int *outputPtr = output,outputValue=0;

    for (int output_i = 0; output_i < output_row; output_i++) {
        for (int output_j = 0; output_j < output_col; output_j++) {
            outputValue = 0;
            for (int kernel_i = 0; kernel_i < kernel_row; kernel_i++) {
                val1 = output_i + (kernel_i+kernel_i);
                input_i = val1 - input_row * (val1/input_row);
                for (int kernel_j = 0; kernel_j < kernel_col; kernel_j++) {

                    
                    val2 = output_j + (kernel_j+kernel_j);
                    input_j = val2 - input_col*(val2/input_col);

                    
                    outputValue += inputPtr[input_i * input_col + input_j] * kernel[kernel_i * kernel_col + kernel_j];
                }
            }
            outputPtr[output_i * output_col + output_j] = outputValue;
        }
    }
}
