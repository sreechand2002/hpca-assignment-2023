all: data/64.in data/128.in data/2048.in data/4096.in data/1024.in data/8192.in data/16384.in dilated_conv

dilated_conv: main.cpp header/single_thread.h header/multi_thread.h
	g++ main.cpp -o dilated_conv -I ./header -lpthread -mavx -mavx2

data/generate: data/generate.cpp
	g++ ./data/generate.cpp -o ./data/generate

data/64.in: data/generate
	./data/generate 64

data/128.in: data/generate
	./data/generate 128

data/1024.in: data/generate
	./data/generate 1024

data/2048.in: data/generate
	./data/generate 2048

data/4096.in: data/generate
	./data/generate 4096 

data/8192.in: data/generate
	./data/generate 8192 

data/16384.in: data/generate
	./data/generate 16384 

run: data/1024.in data/2048.in data/4096.in data/8192.in data/16384.in dilated_conv
	./dilated_conv -i data/4096.in -k data/1024.in
	./dilated_conv -i data/4096.in -k data/2048.in
	./dilated_conv -i data/8192.in -k data/1024.in
	./dilated_conv -i data/8192.in -k data/2048.in
	./dilated_conv -i data/16384.in -k data/1024.in
	./dilated_conv -i data/16384.in -k data/2048.in

clean:
	rm dilated_conv
