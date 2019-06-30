#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
	    long long int n;
	    cin >> n;
	    long long int may_use = (((long long int) 1) << 60) - 1;
        long long int result = 0;
        long long int temp = n;
        for (int j = 59; j >= 0; --j)
        {
            long long int st = (((long long int) 1) << j);
	        if ((3 * st <= n) && (((n - 3 * st) & may_use) <= 3 * (st - 1)))
	        {
	            result += st;
	            n -= 3 * st;
	        }
	        else may_use = st - 1;
        }
        n = temp;
	    n -= 3 * result;
	    long long int otv[3] = {result, result, result};
	    for (int k = 59; k >= 0; k--)
	    {
	        if (result & (((long long int) 1) << k)) continue;
	        for (int m = 0; m < 3; ++m)
	        {
		        if (n >= (((long long int) 1) << k))
		        {
		            otv[m] += ((long long int) 1) << k;
		            n -= ((long long int) 1) <<  k;
		        }
	        }
	    }
	    cout << otv[0] << " " << otv[1] << " " << otv[2] << "\n";
    }
}
