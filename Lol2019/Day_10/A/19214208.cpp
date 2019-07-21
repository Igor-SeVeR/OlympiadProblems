#include <iostream>

using namespace std;

int main()
{
        int n, k, a, b;
        cin >> n >> k >> a >> b;
	k--;
        if (n > k)
            cout << a / (k * b) * (k + 1) + (a % (k * b)) / b;
	else 
            cout << a / (n * b) * (n + 1) + (a % (n * b)) / b;
	return 0;
}

