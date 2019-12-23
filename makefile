all: compile run

compile:
	g++ main.cpp -o main -std=c++11

run:
	./main