#include "longest_common_subsequence.h"

solution ERROR_SOL = solution(-1, "ERROR_ERROR_ERROR");

/* --- MATRICES FUNCTIONS --- */

//This function allocate a dynamic bidimensional matrix
info** createMatrix(const int cols, const int rows) {
	info **matrix = new info*[rows];
	
	for(int i = 0; i < rows; i++)
		matrix[i] = new info[cols];

	return matrix;
}

//This function free the memory once the computation is finished
void destroyMatrix(info **&matrix, const int rows) {
	for (int i = 0; i < rows; i++)
	    delete [] matrix[i];
	delete [] matrix;
}

//This function print in a pretty way the matrix with lengths and directions
void printMatrix(info **m, int rows, int cols, string s1, string s2) {
	cout << "      €      ";
	for (int i = 0; i < cols; i++)
		cout << s1[i] << "      ";
	cout << endl;

	for (int i = 0; i < rows; i++) {
		if (i == 0)
			cout << "€ | ";
		else
			cout << s2[i-1] << " | ";

		for (int j = 0; j < cols; j++)
			cout << m[i][j].first << "(" << m[i][j].second << ") | ";
		cout << endl;
	}
	
	cout << endl;
}

/* --- END OF MATRICES FUNCTIONS --- */

/* --- COMPUTING FUNCTIONS --- */

//This funcions, thanks to dynamic programming, computes the longest common subsequence
solution longestCommonSubsequence(string seq1, const int cols, string seq2, const int rows) {
	solution sol;
	info **greekPi = createMatrix(cols+1, rows+1);	//there is an empty column and an empty row to simplify the computation

	for (int j = 0; j < cols+1; j++)
		greekPi[0][j] = {0, NONE};

	for (int i = 0; i < rows+1; i++)
		greekPi[i][0] = {0, NONE};

	for (int i = 1; i < rows+1; i++) {
		for (int j = 1; j < cols+1; j++) {
#ifdef DEBUG
cout << "seq2[i] = " << seq2[i-1] << "\tseq1[j] = " << seq1[j-1];
#endif
			if (seq1[j-1] == seq2[i-1]) {
				greekPi[i][j].first = greekPi[i-1][j-1].first + 1;
				greekPi[i][j].second = DIAG;
#ifdef DEBUG
cout << "\t1" << "\ti = " << i << ", j = " << j << endl;
#endif
			} else {
				max(greekPi[i][j-1], greekPi[i-1][j], greekPi[i][j]);
#ifdef DEBUG
cout << "\t2" << "\ti = " << i << ", j = " << j << endl;
#endif
			}
		}
	}

	printMatrix(greekPi, rows+1, cols+1, seq1, seq2);

	sol = buildSolution(greekPi, rows, cols, seq2);

	destroyMatrix(greekPi, rows);

	return sol;
}

//This function built a string starting from info matrix
solution buildSolution(info** m, const int& rows, const int& cols, const string seq) {
	int i = rows, j = cols;
	solution sol;
	
	if(m[i][j].first == 0)
		return ERROR_SOL;

	sol.first = m[i][j].first;	

	string subSeq = "";
	while(m[i][j].second != NONE) {
#ifdef DEBUG
cout << "i = " << i << ", j = " << j << endl;
#endif
		switch(m[i][j].second) {
			case UP:
				i--;
				break;
			case LEFT:
				j--;
				break;
			case DIAG:
				subSeq += seq[i-1]; 
				i--;
				j--;
				break;
		}
	}

	cout << endl;

	reverse(subSeq.begin(), subSeq.end());
	sol.second = subSeq;

	return sol;
}

/* --- END OF COMPUTING FUNCTIONS --- */

/* --- AUXILIARY FUNCTIONS --- */

void max(info left, info up, info& res) {
	if (up.first >= left.first) {
		res.first = up.first;
		res.second = UP;
		return;
	}
	res.first = left.first;
	res.second = LEFT;
}

/* --- END OF AUXILIARY FUNCTIONS --- */
