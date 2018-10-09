#include <bits/stdc++.h>

#define WHITE 0
#define BLACK 1

using namespace std;

typedef int grain;

vector<grain> pot;

int main(int argc, char **argv) {
	srand(time(NULL));
	if (argc != 2 || atoi(argv[1]) < 2) {
		cerr << "Usage: ./coffeegrain.out <number_of_grains (>= 2)>" << endl;
		exit(EXIT_FAILURE);
	}

	int N = atoi(argv[1]), whites = 0;
	
	for (int i = 0, curr; i < N; i++) {
		if (!(curr = rand() % 2))
			whites++;	
		
		pot.push_back(curr);
	}

	grain fst, snd;
	while (pot.size() > 1) {
		fst = pot.back(); 
		pot.pop_back();
		snd = pot.back();
		pot.pop_back();

		if (fst == snd) 
			pot.push_back(BLACK);
		else
			pot.push_back(WHITE);
	}

	cout << "There are " << whites << " white grains at the beginning." << endl;
	cout << "The last grain is:\t" << (!pot.back() ? "WHITE." : "BLACK.") << endl;

	exit(EXIT_SUCCESS);
}
