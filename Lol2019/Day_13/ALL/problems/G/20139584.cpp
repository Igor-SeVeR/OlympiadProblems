#include <iostream>
using namespace std;

int main()
{
	
	int k, n, n1;
	cin >> n >> k;
	n1 = -1;

	while (k%n!=0) {
		n1 = k % n;
		k = k % n + n;
		n = n1;
		
	}
	cout << n;
}

