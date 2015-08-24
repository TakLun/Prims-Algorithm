all: submission

submission: prim.o
	g++ -g -Wall prim.o -o submission
	
prim.o: prim.cpp
	g++ -g -Wall -c prim.cpp
	
clean:
	rm -f *.o submission
