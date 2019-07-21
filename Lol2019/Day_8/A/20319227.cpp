#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<vector<char> > map;

void map_init() {
	for (int i = 0; i < m + 2; i++) {
		vector<char> line;
		for (int j = 0; j < n + 2; j++) {
			line.push_back('0');
		}
		map.push_back(line);
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			char x; cin >> x;
			map[i][j] = x;
		}
	}
}


void dfs(int i, int j) {
	map[i][j] = '!';
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};

	for (int s = 0; s < 4; s++) {
		int x = i + dx[s]; int y = j + dy[s];
		if (map[x][y] == '#') dfs(x, y);
	}
}

int main() {
	cin >> m >> n;
	map_init();
	int counter = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == '#') {
				counter++;
				dfs(i, j);
			}
		}
	}

	cout << counter;
	return 0;
}