#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n % 2)
        cout << (long long)pow(n, 3) << endl;
    else
        cout << (long long)pow(n, 2) << endl;
    return 0;
}
