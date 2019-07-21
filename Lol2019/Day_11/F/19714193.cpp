#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector <int> v;

void rec(int n, int m) {
    if (n == 1) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ((i == v.size() - 1) ? "" : "*");
        }
        cout << endl;
        return;
    }
    for (int i = m; i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            rec(n / i, i);
            v.pop_back();
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    rec(n, m);
    return 0;
}
