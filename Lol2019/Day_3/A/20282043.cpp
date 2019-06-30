#include <iostream>

using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int ans = 1;
    for (int i = k+1; i <= n; i++) ans *= i;
    for (int i = 2; i <= n-k; i++) ans /= i;
    cout << ans;
    return 0;
}