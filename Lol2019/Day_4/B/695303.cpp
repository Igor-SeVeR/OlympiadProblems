#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int A[n+1];
    for (int i = 0; i <= n; ++i)
    {
        A[i] = 0;
    }
    for (int i = 2; i <= n; ++i)
    {
        A[i] = A[i-1];
        if (i % 2 == 0)
        {
            A[i] = min(A[i], A[i/2]);
        }
        if (i % 3 == 0)
        {
            A[i] = min(A[i], A[i/3]);
        }
        A[i]++;
    }
    int i = n;
    string S;
    while (i != 1)
    {
        if (i % 3 == 0 && A[i/3] == A[i] - 1)
        {
            S += '3';
            i = i / 3;
        }
        else if (i % 2 == 0 && A[i/2] == A[i] - 1)
        {
            S += '2';
            i = i / 2;
        }
        else
        {
            S += '1';
            i--;
        }
    }
    for (i = S.size() - 1; i >= 0; --i)
    {
        cout << S[i];
    }
    return 0;
}
