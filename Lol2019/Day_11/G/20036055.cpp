

#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
#include <queue>
#include <list>

using namespace std;

typedef long long ll;

int fact(int i) {
    if (i == 0) return 1;
    else return i * fact(i-1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    k--;
    int per[n];
    bool was[n];
    for (int i = 0; i < n; ++i)
        was[i] = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!was[j]) {
                if (k < fact(n - i - 1)) {
                    per[i] = j;
                    was[j] = true;
                    break;
                } else {
                    k -= fact(n - i - 1);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << per[i] + 1 << " ";
    }
}