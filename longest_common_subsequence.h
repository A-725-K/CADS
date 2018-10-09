#include <bits/stdc++.h>

#define DIAG 'd'
#define LEFT 'l'
#define UP 'u'
#define NONE ' '

using namespace std;

typedef char direction;
typedef pair<int, direction> info;
typedef pair<int, string> solution;

//code of error in case there isn't a common subsequence
extern solution ERROR_SOL;

//Functions that compute the solutions of the problem
solution longestCommonSubsequence(string, const int, string, const int);
solution buildSolution(info**, const int&, const int&, const string);

//Functions that operate on matrices
info** createMatrix(const int, const int);
void destroyMatrix(info**&, const int);
void printMatrix(info**, int, int, string, string);

//Auxiliary functions
void max(info, info, info&);
