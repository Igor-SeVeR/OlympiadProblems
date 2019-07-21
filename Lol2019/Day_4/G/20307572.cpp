#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[21][2];
    dp[1][0] = 2;
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = 2 * (dp[i - 1][0] + dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[n][0] + dp[n][1] << endl;
    return 0;
}
