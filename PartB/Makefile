all: data/input_128.in diag_mult

diag_mult: main.cu header/gpu_thread.h
	nvcc main.cu -o diag_mult -I ./header --cudart shared

data/generate: data/generate.cpp
	g++ ./data/generate.cpp -o ./data/generate

data/input_128.in: data/generate
	./data/generate 128

run: data/input_128.in diag_mult
	./diag_mult data/input_128.in

clean:
	rm diag_mult
