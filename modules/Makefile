NAME=main

all:
	em++ main.cpp --std=c++11 -o $(NAME).wasm --no-entry -s WASM=1 -s EXPORT_ALL=1

clear:
	rm -f $(NAME).wasm

re: clear all

.DEFAULT_GOAL := all