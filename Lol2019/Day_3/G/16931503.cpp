#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	long n, now;
	string s = "";
	cin >> n;
	now = n;
	if (n % 3 == 0) {
        cout << 0;
        return 0;
	}
	if (n == 1) {
        cout << 1;
        return 0;
	}
	long sum = 1;
	if (n >= 10) {
        s = "8";
        now = n - 8 - 1;
        sum = 9;
	}
    for (int i = 0; i < now / 9; i++) {
        s = "9" + s;
        sum += 9;
    }
    char x1 = char((n - sum) + '0');
    if (x1 != '0')
        cout << x1;
    cout << s;
    now = n - 1;
    for (int i = 0; i < 1000000; i++) {
        cout << "9";
        if ((now + 9 * (i + 1)) % n == 0)
            break;
    }
}
