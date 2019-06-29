#pragma comment(linker, "/STACK:60000000")

#include "testlib.h"    
#include <vector>
#include <set>
#include <string.h>
#include <utility>
#include <stdio.h>
#include <iostream>

using namespace std;

const int MAXN = 252;

string a[MAXN], b[MAXN];
int ja, pa, n;

int main(int argc, char * argv[]) {
	registerTestlibCmd(argc, argv);
	int i, j;
	n = inf.readInt();
	inf.readString();
	for (i = 0; i < n; i++) {
		a[i] = inf.readString();
	}
	for (i = 0; i < n; i++) {
		string s = ans.readString();
		for (j = 0; j < n; j++)
			if (s[j] == '#') ja += a[i][j] - '0';
	}
	int count = 0;
	for (i = 0; i < n; i++) {
		b[i] = ouf.readString();
		for (j = 0; j < n; j++)
			if (b[i][j] == '#') { pa += a[i][j] - '0'; count++; }
			else if (b[i][j] != '-') quitf(_pe, "not # or -");
	}
	if (pa != ja) quitf(_wa, "%d != %d", ja, pa);
	if (count != (2 * n - 1)) quitf(_pe, "count != 2 * n - 1");
	i = 0, j = 0;
	if (b[0][0] != '#') quitf(_pe, "(0, 0) != #");
	while ((i != n - 1) || (j != n - 1)) {
		if (b[i + 1][j] == '#' && b[i][j + 1] == '#')
			quitf(_pe, "(%d + 1, %d) and (%d, %d + 1) is #", i, j, i, j);
		if (b[i + 1][j] == '#') i++;
		else if (b[i][j + 1] == '#') j++;
		else quitf(_pe, "two neibors is -");
	}
	quitf(_ok, "");
}
