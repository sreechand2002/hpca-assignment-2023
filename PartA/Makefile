all: generate diag_mult

diag_mult: main.cpp header/single_thread.h header/multi_thread.h
	g++ main.cpp -o diag_mult -I ./header

generate: data/input1024.in

data/input1024.in: data/generate.cpp
	g++ ./data/generate.cpp -o ./data/generate
	./data/generate > data/input1024.in

run:
	./diag_mult < data/input1024.in

clean:
	rm diag_mult
