#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> invers(n);
    vector <int> possible(n);
    vector <int> an(n);
    iota(possible.begin(), possible.end(), 1);
    for (int i = 0; i < n; ++i) {
        cin >> invers[i];
    }
    for (int i = n - 1; i > -1; --i) {
        an[i] = possible[possible.size() - invers[i] - 1];
        possible.erase(possible.begin() + possible.size() - invers[i] - 1);
    }
    for (int i = 0; i < n; ++i) {
        cout << an[i] << ' ';
    }
}
