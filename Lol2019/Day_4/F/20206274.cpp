#include <iostream>

using namespace std;

int table[10][10];

int main() {
	int r = 8, c = 8, x, y;
	cin >> x >> y;
	
	table[y][x] = 1;
	
        for (int i = 1; i < r + 1; i++)
        {
                for (int j = 1; j < c + 1; j++)
                {
			table[i][j] += table[i-1][j-1] + table[i-1][j+1];
		}
	}
	
	int res = 0;
	
        for (int i = 1; i < r + 1; i++)
        {
		res += table[8][i];
	}
	
	cout << res;
	
	return 0;
}
