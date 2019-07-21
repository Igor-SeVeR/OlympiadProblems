#include <iostream>
#include <vector>

using namespace std;

int main() {
	int x, y, z, m;
	cin >> x >> y >> z >> m;
	int next_x = 15 - m % 15;
	if (next_x == 15) {
		next_x = 0;
	}
	int next_y = 10 - m % 10;
	if (next_y == 10) {
		next_y = 0;
	}
	int next_z = 5 - m % 5;
	if (next_z == 5) {
		next_z = 0;
	}
	int min = 0;
	if (next_x + x < next_y + y) {
		min = next_x + x;
	}
	else {
		min = next_y + y;
	}
	if (min > next_z + z) {
		min = next_z + z;
	}
	cout << min;
	return 0;
}