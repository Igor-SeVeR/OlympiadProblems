#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    ll a, b; cin >> a >> b;
    ll last_open = a+b, last_close = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '+') {
            last_open += a;
            last_close = min(last_open, last_close);
        } else {
            ll tmp = last_open;
            last_open = min(last_open, last_close+a+b);
            last_close = min(last_close+a, tmp);
        }
    }
    cout << min(last_open, last_close);
}
