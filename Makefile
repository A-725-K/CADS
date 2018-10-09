all:
	g++ binary_search.cpp -o binS.out -O2 -Wall -pedantic
	g++ main.cpp sorting_alg.cpp aux.cpp sorting_alg.h -o sort.out -O2 -Wall -pedantic
	g++ hanoi.cpp -o han.out -O2 -Wall -pedantic
	g++ dutch_flag.cpp -o flag.out -O2 -Wall -pedantic
	g++ main_graph.cpp graph_visit.cpp graph_visit.h -o graph.out -O2 -Wall -pedantic
	g++ sink_node.cpp -o sink.out -O2 -Wall -pedantic
	g++ coffee_grain.cpp -o coffeegrain.out -O2 -Wall -pedantic
	g++ bitonic_seq.cpp -o bitonic.out -O2 -Wall -pedantic
	g++ array_zeros_and_ones.cpp -o zerosones.out -O2 -Wall -pedantic

sort:
	g++ main.cpp sorting_alg.cpp aux.cpp sorting_alg.h -o sort.out -O2 -Wall -pedantic

graph:
	g++ main_graph.cpp graph_visit.cpp graph_visit.h -o graph.out -O2 -Wall -pedantic

oriented_graph:
	g++ main_graph.cpp graph_visit.cpp graph_visit.h -o graph.out -O2 -Wall -pedantic -DORIENTED

lcs:
	g++ main_lcs.cpp longest_common_subsequence.cpp longest_common_subsequence.h -o lcs.out -O2 -Wall -pedantic

clean:
	rm -f *.out
