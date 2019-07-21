#include <bits/stdc++.h>

using namespace std;

vector<int> generateSequence(int n)
{
    vector<int> sequence;
    map<int, int> last;
    int prev = 0, current, count = 0;
    while (n--)
    {
        sequence.push_back(prev);
        if (last[prev])
        {
            current = count - last[prev] + 1;
        }
        else
        {
            current = 0;
        }
        count++;
        last[prev] = count;
        prev = current;
    }
    return sequence;
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence = generateSequence(n);
    cout << sequence[n - 1] << endl;
}
