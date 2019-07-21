#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s += x;
    }

    cout << s / 100 << endl;
}
