all: ptr.ih.gch main

ptr.ih.gch: ptr.ih
	g++ -std=c++14 -Wall -x c++-header ptr.ih

main: *.cc *.h
	g++ -std=c++14 -Wall -o main *.cc *.h
