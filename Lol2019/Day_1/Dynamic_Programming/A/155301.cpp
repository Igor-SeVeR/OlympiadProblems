#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> din(n+1);
	din[0] = 1;
	din[1] = 2;
	din[2] = 4;
        for (int i = 3; i <= n; i++)
		din[i] = din[i-2]+din[i-1]+din[i-3];
	cout << din[n];
	return 0;
}
