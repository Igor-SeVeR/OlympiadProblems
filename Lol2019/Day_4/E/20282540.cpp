#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10001];
    a[1] = 1;
    for (int i = 2; i < n; i++) {
        a[i] = 0;
    }
    for (int i = 2; i < n; i++) {
        if (a[i] == 0) {
            for (int j = i*i; j < n; j++) {
                a[j] = 1;
            }
        }
    }

    int b[10001];
    b[1] = 1;
    b[2] = 1;
    b[3] = 1;
    b[4] = 2;
    for (int i = 5; i <= n; i++) {
        b[i] = 2;
        for (int j = i - 1; j >= i - 3; j--) {
            if (a[j] == 1 && b[j] == 2) {
                b[i] = 1;
                break;
            }
        }
    }
    cout << b[n];
}
