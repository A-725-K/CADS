#include "longest_common_subsequence.h"

int main(int argc, char **argv) {
	if (argc != 3) {
		cerr << "Usage: ./lcs.out <char_sequence_1> <char_sequence_2>" << endl;
		return -1;
	}
	
	string seq1 = argv[1], seq2 = argv[2];

	cout << "The first sequence is " << seq1 << " and its lenght is " << seq1.size() << "." << endl;
	cout << "The second sequence is " << seq2 << " and its length is " << seq2.size() << "." << endl << endl;

	solution lcs = longestCommonSubsequence(seq1, seq1.size(), seq2, seq2.size());

	if (lcs != ERROR_SOL)
		cout << "The longest common subsequence has length: " << lcs.first << endl
			 << "It is: " << lcs.second << endl;
	else
		cout << "There isn't a common subsequence !" << endl;

	return 0;
}
