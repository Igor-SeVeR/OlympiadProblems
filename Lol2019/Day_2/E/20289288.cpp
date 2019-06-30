#include <iostream>
#include <cstdio>
#include <string>
#include <map>

typedef long long LL;

using namespace std;

char c;
map <string, int> check;

int main() {
    string s;
    cin >> c;
    while (c != '#') {
            cin >> s;
            if (c == '+')
                    check[s]++;
            else if (c == '-')
                    check[s]--;
            else
                    check[s] ? printf("YES\n") : printf("NO\n");
            cin >> c;
    }
    return 0;
}
