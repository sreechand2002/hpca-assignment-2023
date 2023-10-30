# HPCA Assignment
Optimize dilated convolution using hardware counters.
Contained are two folders:
* PartA: Contains setup for single-threaded and multi-threaded program.
* PartB: Contains setup for GPU program.

Each folder contains two sub-folders, a Makefile, and a main program.
* Makefile: Contains commands necessary to compile, generate inputs, and run the program.
* data folder: Contains program that generates input, and will contain input once generated.
* header folder: Files containing the function that performs the operation. Modify the files in this folder.
* main.cpp: Program that takes inputs and executes the functions. DO NOT MODIFY THIS.

Navigate to each folder to begin setting up the system.
Inside each folder do the following:
### Compiling and generating input
Use the following command to compile the programs and generate required input:
```
make
```
## PART A
### Running program
You can use make to run the executable with the following command:
```
make run
```
Alternatively, you can manually run the program for the different input sets using the following commands:
```
./dilated_conv -i data/4096.in -k data/1024.in
./dilated_conv -i data/8192.in -k data/1024.in
./dilated_conv -i data/16384.in -k data/1024.in
```
Note: the `-i` flag is for the input matrix and `-k` flag is for the kernel matrix.
## PART B
To compile the code for use on native GPU use the following command:
```
make server
```
For use with GPGPU-Sim, additional flags are required during compilation, which can be done with the following command:
```
make sim
```

You can use make to run the executable with the following command for native execution:
```
make run_server
```
When running on GPGPU-Sim, use the following command instead:
```
make run_sim
```
