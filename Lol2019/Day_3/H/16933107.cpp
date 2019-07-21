#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>

#define eps 1e-6

using namespace std;

int main() {
    long n;
    cin >> n;
    vector <double> w(n);
    vector <double> v(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    double l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        r = r + sum / v[i];
    }
    while (r - l > eps) {
        double m = (l + r) / 2;
        double sum = 0;
        bool flag = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (m * v[i] < sum + w[i]) {
                flag = 1;
                break;
            }
            sum = sum + w[i];
        }
        if (flag == 1)
            l = m;
        else
            r = m;
    }
    cout << fixed;
    cout.precision(5);
    cout << r;
}

