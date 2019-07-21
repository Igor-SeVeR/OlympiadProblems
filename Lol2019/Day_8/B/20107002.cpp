#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <math.h> 
#include <algorithm> 
#include <string> 
#include <string.h> 
#include <vector> 
#include <stdio.h> 
#include <stdlib.h> 
#include <stack> 
#include <queue> 
#include <set> 
#include <deque> 
using namespace std;

int k = 0, n1, t, ch, i, j, l;
int n, m, a, b;
vector <int> colors[100100];
vector<short> g[5050];
short u[5050];
bool cycle;

void dfs(int v) {
	if (u[v] == 2 || cycle)
		return;
	if (u[v] == 1) {
		cycle = 1;
		return;
	}
	u[v] = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		dfs(g[v][i]);
	}
	u[v] = 2;
}

int main() {
        string s;
	cin >> n;
	for (int f = 0; f < n - 1; ++f) {
		cin >> s;
		for (int f2 = f + 1; f2 < n; ++f2) {
			if (s[f2 - f - 1] == 'B') {
				g[f2].push_back(f);
			}
			else 
				g[f].push_back(f2);
		}
	}
	for (int i = 0; i < n; ++i) {
		dfs(i);
	}
	if (cycle == 1)
		cout << "NO" << '\n';
	else
		cout << "YES";
	return 0;
}
