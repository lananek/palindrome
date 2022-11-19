#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");


	string S;
	fin >> S;
	int length = S.length();
	vector <char> A(length);
	for ( int i = 0; i < length; ++i) {
		A[i] = S[i];
	}
	vector <char> B(length);
	int k = 0;
	for (int i = length - 1; i >= 0; --i) {
		B[k] = S[i];
		k++;
	}

	vector <vector <long long>> f(length + 1, vector <long long>(length + 1));
	for (int i = 0; i < length + 1; i++) {
		for (int j = 0; j < length + 1; j++) {
			if ((i == 0) || (j == 0)) {
				f[i][j] = 0;
			}
			else if ((A[i - 1] == B[j - 1]) && (i != 0)) {
				f[i][j] = f[i - 1][j - 1] + 1;
			}
			else {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	fout << f[length][length] << endl;

	//восстановление
	vector <char> Aa;
	int t = length;
	for (int i = length; i > 0; i--) {
		for (int j = t; j > 0; j--) {
			if (A[i - 1] == B[j - 1]) {
				Aa.push_back(A[i - 1]);
				t = j - 1;
				break;
			}
			else if (f[i][j] == f[i][j - 1]) {
				continue;
			}
			else break;
		}
	}

	 
	for (int i = 0; i < Aa.size(); i++) {
		cout << Aa[i];
	}

	fin.close();
	fout.close();
	return 0;
}