#include "graph_visit.h"

int main(int argc, char **argv) {
	if (!check_cli_args(argc, argv))
		exit(EXIT_FAILURE);

	srand(time(NULL));

	initialize_graph();
	reset_visited();

	switch(atoi(argv[1])) {
		case 1:
			cout << "*** DFS VISIT ***" << endl;
		#ifndef REC
			DFS_visit(rand() % N);
		#else
			DFS_rec(rand() % N);
		#endif
			break;
		case 2:
			cout << "*** BFS VISIT ***" << endl;
		#ifndef REC
			BFS_visit(rand() % N);
		#else
			BFS_rec(rand() % N);
		#endif
			break;
		case 3:
			cout << "*** DIJKSTRA VISIT ***" << endl;
			dijkstra_visit(rand() % N);
			break;
		case 4:
			cout << "*** PRIM VISIT ***" << endl;
			prim_visit(rand() % N);
			break;
		#ifdef ORIENTED
		case 5:
			cout << "*** TOPOLOGICAL SORTING ***" << endl;
			topological_sorting();
			break;
		case 6:
			cout << "*** TIMESTAMP SORTING ***" << endl;
			tstamps_topological_sorting();
			break;
		#endif
	}

	exit(EXIT_SUCCESS);
}
