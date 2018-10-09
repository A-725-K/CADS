#include "graph_visit.h"

vector<pair<int, int>> adj_list[MAXN + 1];
bool visited[MAXN + 1];
int N;
int counter = 1;

#ifdef ORIENTED
int start_tm[MAXN];
int end_tm[MAXN];
#endif

/********************************************************************************\
*								Visits  										*
\********************************************************************************/

//DFS
void DFS_visit(int start) {
	stack<int> s;
	int u;
	vector<pair<int, int>>::iterator it;

	s.push(start);

	while(!s.empty()) {
		u = s.top();
		s.pop();

		if (!visited[u]) {
			cout << u << ((counter++ != N) ? " -> " : "\n\n\n");	//visit node
			it = adj_list[u].begin();
			while (it != adj_list[u].end()) {
				if (!visited[(*it).first])
					s.push((*it).first);
				it++;
			}
			visited[u] = true;
		}
	}
}

//BFS
void BFS_visit(int start) {
	queue<int> q;
	int u;
	vector<pair<int, int>>::iterator it;

	q.push(start);

	while(!q.empty()) {
		u = q.front();
		q.pop();

		if (!visited[u]) {
			cout << u << ((counter++ != N) ? " -> " : "\n\n\n");	//visit node
			it = adj_list[u].begin();
			while (it != adj_list[u].end()) {
				if (!visited[(*it).first]) 
					q.push((*it).first);
				it++;
			}
			visited[u] = true;
		}	
	}
}

#ifdef REC
//Recursive visit DFS
void DFS_rec_aux(int start) {
	visited[start] = true;
	vector<pair<int, int>>::iterator it = adj_list[start].begin();

	cout << start << ((counter++ != N) ? " -> " : "\n\n\n"); //visit node
	while(it != adj_list[start].end()) {
		if (!visited[(*it).first])
			DFS_rec_aux((*it).first);
		it++;
	}
}

//DFS Recursive
void DFS_rec(int start) {
	for (int i = 0; i < N; i++) 
		if (!visited[i])
			DFS_rec_aux(i);
}

//Recursive visit BFS
void BFS_rec_aux(queue<int> curr) { 
	int u; 

	if (curr.empty())
		return;

	u = curr.front();
	curr.pop();

	if (!visited[u]) {
		cout << u << ((counter++ != N) ? " -> " : "\n\n\n");
		visited[u] = true;

		for (auto v : adj_list[u]) 
			if (!visited[v.first]) 
				curr.push(v.first);
	}

	BFS_rec_aux(curr);
}

//BFS recursive
void BFS_rec(int start) {
	queue<int> q;

	q.push(start);
	BFS_rec_aux(q);
}
#endif

//DIJKSTRA
void print_dijkstra_result(int dist[], int par[], int s) {
	int path[MAXN];

	for (int i = 0, p = i, j = 0; i < N; p = ++i, j = 0) {
		if (i == s)
			continue;

		cout << i << ") ";
		while (par[p] != NONE) {
			path[j++] = par[p];
			p = par[p];
		}

		for (int k = j-1; k >= 0; k--)
			cout << path[k] << " -> ";
		cout << i;

		cout << "\t\t\t\tTotal distance:\t" << dist[i] << endl;
	}

	cout << endl << endl;
}

void dijkstra_visit(int start) {
	int distance[MAXN + 1];
	int parent[MAXN + 1];
	priority_queue<pair<int, int>> q;

	cout << "Starting from:\t" << start << endl << endl;

	for (int i = 0; i < N; i++) {
		distance[i] = INF;
		parent[i] = NONE;
	}

	distance[start] = 0;
	q.push({start, 0});	

	int from, to, weight, alt;
	while(!q.empty()) {
		from = q.top().first;
		q.pop();

		if (visited[from])
			continue;

		visited[from] = true;

		for (auto u : adj_list[from]) {
			to = u.first;
			weight = u.second;
			alt = distance[from] + weight;
			if (alt < distance[to]) {
				distance[to] = alt;
				parent[to] = from;
				q.push({to, -distance[to]});
			}
		}
	}

	print_dijkstra_result(distance, parent, start);
}

//PRIM
void print_prim_tree(int dist[], int par[], int start) { 
	vector<int> sons[MAXN];

	for (int i = 0; i < N; i++) {
		if (par[i] == NONE)
			continue;
		sons[par[i]].push_back(i);
	}

#ifdef DEBUG
print_parent(par);
cout << "*****************************************\n\n\n\n";
print_sons(sons);
cout << "*****************************************\n\n\n\n";
#endif

	print_tree(true, "", sons, start);

	cout << endl << endl;
}

void prim_visit(int start) {
	int distance[MAXN + 1];
	int parent[MAXN + 1];
	priority_queue<pair<int, int>> q;

	cout << "Starting from:\t" << start << endl << endl;

	for (int i = 0; i < N; i++) {
		distance[i] = INF;
		parent[i] = NONE;
	}

	distance[start] = 0;
	q.push({start, 0});	

	int from, to, weight;
	while(!q.empty()) {
		from = q.top().first;
		q.pop();

		if (visited[from])
			continue;

		visited[from] = true;

		for (auto u : adj_list[from]) {
			to = u.first;
			weight = u.second;
			if (!visited[to] && weight < distance[to]) {
				distance[to] = weight;
				parent[to] = from;
				q.push({to, -distance[to]});
			}
		}
	}

	print_prim_tree(distance, parent, start);
}

#ifdef ORIENTED
//Prints out the topological order 
void print_topol_visit_result(vector<int> ordered) {
	vector<int>::iterator it_list;
	
	for(it_list = ordered.begin(); it_list != ordered.end(); it_list++, counter++)
		cout << *it_list << ((counter != N) ? " < " : "");

	cout << endl;
}

//Prints out the topological order obtained by timestamps
void print_topol_tstamps_order() {
	priority_queue<pair<int, int>> aux;
	for (int i = 0; i < N; i++)
		aux.push({-end_tm[i], i});

	int u;
	while (!aux.empty()) {
		u = aux.top().second;
		aux.pop();
		cout << counter << ")\t" << u << " ---> start[" << u << "] = " << start_tm[u] 
		 	 << "\tend[" << u << "] = " << end_tm[u] << endl;
		counter++;
	}

	cout << endl;
}

//TOPOLOGICAL SORTING
void topological_sorting() {
	stack<int> s;
	vector<int> ordered;
	int in_deg_nodes[MAXN];

	for (int i = 0; i < N; i++) {
		in_deg_nodes[i] = in_degree(i);
		if (in_deg_nodes[i] == 0)
			s.push(i);
	}

	int u;
	while (!s.empty()) {
		u = s.top();
		s.pop();

		for (auto v : adj_list[u]) {
			in_deg_nodes[v.first]--;
			if (in_deg_nodes[v.first] == 0)
				s.push(v.first);
		}
		
		ordered.push_back(u);
	}

	print_topol_visit_result(ordered);
}

//TIMESTAMP TOPOLOGICAL SORTING
void tstamps_aux(int &time, int from) {
	//visit(from); -- do in case some operation
	
	time++;
	start_tm[from] = time;
	visited[from] = true;

	for (auto x : adj_list[from]) {
		if (!visited[x.first])
			tstamps_aux(time, x.first);
	}

	time++;
	end_tm[from] = time;
}

void tstamps_topological_sorting() {
	int time = 0;

	reset_visited();
	for (int i = 0; i < N; i++)
		if (!visited[i])
			tstamps_aux(i, time);

	print_topol_tstamps_order();
}
#endif

/********************************************************************************\
*								Utils	  										*
\********************************************************************************/
//This function print in a pretty way the spanning tree
void print_tree(bool last, string ind, vector<int> sons[], int n) {
	cout << ind;

	if (last) {
		cout << "\\-";
		ind += "  ";
	} else {
		cout << "|-";
		ind += "| ";
	}

	cout << n << endl;

	for (unsigned int i = 0; i < sons[n].size(); i++)
		print_tree(i == (sons[n].size() - 1), ind, sons, sons[n][i]);
}

//Check whether the program have been launched correctly by the user
bool check_cli_args(int argc, char **argv) {
	if (argc == 2) {
		int argv1 = atoi(argv[1]);
		if(argv1 > 0 && 
			#ifdef ORIENTED
				argv1 < 7) 
			#else
				argv1 < 5)
			#endif
			return true;
	}
	
	cerr << "Usage ./graph.out <number> " << endl
		 << "1 --> DFS visit" << endl
		 << "2 --> BFS visit" << endl
		 << "3 --> Dijkstra visit" << endl
		 << "4 --> Prim visit" << endl
	#ifdef ORIENTED
		 << "5 --> Topological sorting" << endl
		 << "6 --> Time stamps topological sorting" << endl
	#endif
		 ;

	return false;
}

//Initialize the graph reading from file input.txt
void initialize_graph() {
	FILE *file_in;
	int n_edges;

	if (!(file_in = fopen(INPUT, "r"))) {
		perror("Error in fopen()");
		exit(EXIT_FAILURE);
	}

	assert(fscanf(file_in, "%d %d", &N, &n_edges) == 2);	
	for (int i = 0, from, to, weight; i < n_edges; i++) {
		assert(fscanf(file_in, "%d %d %d", &from, &to, &weight) == 3);
		adj_list[from].push_back({to, weight});	
	#ifndef ORIENTED
		adj_list[to].push_back({from, weight});	
	#endif
	}

	fclose(file_in);
#ifdef DEBUG
	print_graph();
#endif
}

#ifdef DEBUG
//Print on the stdout the structure of the graph
void print_graph() {
	for (int i = 0; i < N; i++) {
		cout << "[" << i << "] ---> ";
		for (unsigned int j = 0; j < adj_list[i].size(); j++)
			cout << adj_list[i][j].first << "(" << adj_list[i][j].second << ") ++ " ;
		cout << endl << endl;
	}
}

//Prints all the sons of a node in the tree
void print_sons(vector<int> sons[]) {
	for (int i = 0; i < N; i++)	{
		cout << i << ":\t";
		for (unsigned int j = 0; j < sons[i].size(); j++)
			cout << sons[i][j] << " -> ";
		cout << endl;
	}
}

//Prints the array which contains the father of each node
void print_parent(int par[]) {
	for (int i = 0; i < N; i++)
		cout << "i = " << i << "\tpar[i] = " << par[i] << endl;
}
#endif

//Reset all checks before starting a visit
void reset_visited() {
	for (int i = 0; i < N; i++)
		visited[i] = false;
}

//Returns the number of edges incident in a node
int in_degree(int node) {
	int in_deg = 0;
	for (auto ls : adj_list) 
		for(auto x : ls)
			if (x.first == node)
				in_deg++;
	
	return in_deg;
}
