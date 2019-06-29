#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> f;
    f.push_back(0);
    f.push_back(0);
    for (int i = 2; i <= n; i++)
    {
        f.push_back(f[i - 1] + 1);
        if (i % 2 == 0)
            f[i] = min(f[i], f[i / 2] + 1);
        if (i % 3 == 0)
            f[i] = min(f[i], f[i / 3] + 1);
    }
    cout << f[n] << endl;
    return 0;
}
