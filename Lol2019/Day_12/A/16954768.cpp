#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, i, j, a = 0, b = 0;
    string s, s1;
    cin >> s;
    n = s.size();
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            a++;
        else
            b += a;
    }
    cout << b;
}
