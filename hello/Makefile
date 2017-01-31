hello:
	mkdir -p bin
	g++ -g helloworld.cpp -o bin/hello
mkbin:
	mkdir -p bin
combination:	mkbin
	g++ -g combination.cpp -o bin/combination
combination_v2:	mkbin
	g++ -g combination_v2.cpp -o bin/c_v2
permutation:		mkbin
	g++ -g permutation.cpp -o bin/permutation
strchr:
	g++ -g strchr.cpp -o bin/strchr
double_float:	mkbin dump.h
	g++ -g double_float.cpp -o bin/double_float
dijkstra:	mkbin dump.h
	g++ -g dijkstra.cpp -o bin/dijkstra
clean:
	rm -rf bin