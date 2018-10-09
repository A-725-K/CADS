#include <bits/stdc++.h>

#define INPUT "input.txt"
#define MAXN 20
#define INF INT_MAX
#define NONE -1

using namespace std;

/* Graph */
extern vector<pair<int, int>> adj_list[MAXN + 1];	//first: adj vertex, second: cost
extern bool visited[MAXN + 1];
extern int N;

/* Visits */
void DFS_visit(int);
void BFS_visit(int);
void dijkstra_visit(int);
void prim_visit(int);

/* Utils */
bool check_cli_args(int, char**);
void initialize_graph();
void reset_visited();
void print_tree(bool, string, vector<int>[], int);
int in_degree(int);

#ifdef DEBUG
void print_graph();
void print_sons(vector<int>[]);
void print_parent(int[]);
#endif

#ifdef REC
void BFS_rec(int);
void DFS_rec(int);
#endif

#ifdef ORIENTED
void topological_sorting();
void tstamps_topological_sorting();
#endif
