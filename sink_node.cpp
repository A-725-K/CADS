#include <bits/stdc++.h>

#define INPUT "sink_in.txt"
#define MAXN 100

using namespace std;

bool graph[MAXN][MAXN];	//graph
vector<int> candidate;	//auxiliary structure

/*
 * A SINK node in a graph is a vertex that has out-degree = 0
 * and in-degree = N-1. We assume to have an oriented graph
 * represented in the form of an adjacent matrix.
 *
 * This algorithm works in O(N) assuming that pop_back(), back(),
 * and push_back() functions of vectors work in O(1).
 */
bool find_sink(int &sinkN, const int N) {
	int fst, snd, el;

	if (N < 2)
		return false;

	while(candidate.size() > 1) {
		fst = candidate.back();
		candidate.pop_back();
		snd = candidate.back();
		candidate.pop_back();

		/* 
		 * If graph[fst][snd] == TRUE then fst couldn't be a SINK node
		 * If graph[fst][snd] == FALSE then snd couldn't be a SINK node
		 */
		if (graph[fst][snd])
			candidate.push_back(snd);
		else
			candidate.push_back(fst);
	}	

	el = candidate.front();
	candidate.pop_back();
	
	//Check if the remained vertex is effectively a SINK node
	for (int i = 0; i < N; i++) {
		if (i == el)
			continue;	
		if (graph[el][i] || !graph[i][el])
			return false;
	}

	sinkN = el;	
	return true;
}

int main(int argc, char **argv) {
	FILE *file_in;
	int N, M, from, to, sinkN;

	if(!(file_in = fopen(INPUT, "r"))) {
		perror("Error in fopen()");
		exit(EXIT_FAILURE);
	}

	//Reading from file
	assert(fscanf(file_in, "%d %d", &N, &M) == 2);
	for (int i = 0; i < M; i++) {
		assert(fscanf(file_in, "%d %d", &from, &to) == 2);
		graph[from][to] = true; //adding the edge to the graph
	}

	//Printing the graph
	cout << "The graph is:" << endl;
	for (int i = 0; i < N; i++) {
		candidate.push_back(i);
		for (int j = 0; j < N; j++) 
			cout << graph[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	if (find_sink(sinkN, N))
		cout << "The SINK node is:\t" << sinkN << endl;
	else
		cout << "There isn't a SINK node" << endl;

	if(fclose(file_in) != 0) {
		perror("Error in fclose()");
		exit(EXIT_FAILURE);
	}
 
	return 0;
}
