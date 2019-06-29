#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int h(char x) {
	switch (x) {
	case 'N':
		return 0;
		break;
	case 'S':
		return 1;
		break;
	case 'W':
		return 2;
		break;
	case 'E':
		return 3;
		break;
	case 'U':
		return 4;
		break;
	case'D':
		return 5;
		break;
	default:
		break;
	}
}

long long D[101][6];


int main() {
	string n, s, w, e, u, d;
	getline(cin, n);
	getline(cin, s);
	getline(cin, w);
	getline(cin, e);
	getline(cin, u);
	getline(cin, d);
	string r[6] = { n, s, w, e, u, d };
	char X;
	int L;
	cin >> X >> L;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j <= L; ++j) {
			D[j][i] = 1;
		}
	}

	for (int i = 2; i <= L; ++i) {
		for (int j = 0; j < 6; ++j) {
			for (int k = 0; k < r[j].size(); ++k) {
				D[i][j] += D[i - 1][h(r[j][k])];
			}
		}
	}
	cout << D[L][h(X)];
	cin >> X;
	return 0;
}