#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
typedef long long ll;
#define pb push_back

ll n, a, b;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> a >> b;
    ll p = n;
    if (b * n  % 100 != 0) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < b * n / 100; ++i) {
        cout << a + 1 << '\n';
        --p;
    }
    for (int i = 0; i < p; ++i) {
        cout << a << '\n';
    }
    return 0;
}
	