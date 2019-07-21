#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int s, a, b, n, k;
    cin >> s >> n >> k >> a >> b;
    int ballons = n;
    s -= n * a;
    int candies = min(s / b, k);
    s -= candies * b;
    ballons += s / a;
    cout << ballons << " " << candies << "\n";
    return 0;
}
