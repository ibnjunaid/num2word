

all: compile run 

compile:
	g++ -c -std=c++14 -Wall -pedantic -I../.. main.cpp 
	g++ -c -std=c++14 -Wall -pedantic -I../.. printNum.cpp 
	g++ main.o printNum.o -o run.print
run:
	./run.print

clean:
		
	@rm -rf run.print
	@echo "File Cleaned"

file:
	@ls

