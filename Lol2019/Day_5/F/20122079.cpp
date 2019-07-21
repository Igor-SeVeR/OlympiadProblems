#include <bits/stdc++.h>
using namespace std;
#define pb  push_back
#define ll  long long
#define vi  vector<ll >
#define vvi vector<vi >
#define all(x) x.begin(), x.end()

int n;
vector<double> f;
vector<string> s;
double l =   30;
double r = 4000;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    f.resize(n); s.resize(n);
    cin >> f[0];
    for (int i = 1; i < n; ++i)
        cin >> f[i] >> s[i];

    for (int i = 1; i < n; ++i) {
        double a = f[i - 1];
        double b = f[i];
        if (s[i] != "closer")
            swap(a, b);
        if (abs(a - b) < 1e-8)
            continue;
        if (b > a)
            l = max(l, (a + b) / 2);
        else
            r = min(r, (a + b) / 2);
    }
    cout << fixed << setprecision(8) << l << " " << r;

    return 0;
}
