#include <iostream>
using namespace std;
int main ()
{
    int N, i, j = 0, fl = 1;
    cin >> N;
    int A[N];
    for ( i = 0; i < N; i++ ) cin >> A[i];
    while ( fl == 1 )
    {
        fl = 0;
        for ( i = 0; i < N - 1; i++ )
        {
            if (A[i] > A[i + 1])
            {
                j++;
                swap (A[i], A[i + 1]);
                fl = 1;
                break;
            }
        }
    }
    cout << j;
}
