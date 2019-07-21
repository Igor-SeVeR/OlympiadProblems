//#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

//ifstream fin ("knight2.in");
//ofstream fout ("knight2.out");

int main()
{
    int i, n, m, j, k;
    cin >> n >> m;
    int A[n][m];
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            A[i][j] = 0;
        }
    }
    A[0][0] = 1;
    for (k = 2; k < n + m; ++k)
    {
        for (i = 0; i < n; ++i)
        {
            j = k - i;
            if (i > 1 && j > 0 && j < m)
                A[i][j] += A[i - 2][j - 1];
            if (j > 1 && i > 0 && j < m)
                 A[i][j] += A[i - 1][j - 2];
            if (j >= 0 && j < m - 1 && i > 1)
                A[i][j] += A[i - 2][j + 1];
            if (j > 1 && j < m && i < n - 1)
                A[i][j] += A[i + 1][j - 2];
        }
    }
    cout << A[n - 1][m - 1] << endl;
    return 0;
}
