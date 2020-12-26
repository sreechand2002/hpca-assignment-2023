all: generate diag_mult

diag_mult: main.cpp header/single_thread.h header/multi_thread.h
	g++ main.cpp -o diag_mult -I ./header

generate: data/generate.cpp
	g++ ./data/generate.cpp -o ./data/generate
	./data/generate 8192 

run:
	./diag_mult data/input_8192.in

clean:
	rm diag_mult
