#include <iostream>
using namespace std;

long int d, y, days;

int main() {
	cin >> y >> d;

	days = 104;
	if (d == 7) { 
		days--; 
	}
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
		d++;
	}
	if (d >= 6) { days++; }
	if (d == 7) { days++; }

	cout << days;
}
