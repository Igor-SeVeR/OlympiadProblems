#include <fstream>
#include <stdio.h>
#include <algorithm>
using namespace std;

class elem
{
 public:
	int vl;
	bool open;
};

bool operator < (const elem& a, const elem& b)
{
	if (a.vl == b.vl)
	{
		return a.open > b.open;
	}
	return a.vl < b.vl;
}

int n;
elem arr[30100] = {0};

int main()
{
	int i, j;
        scanf("%d", &n);
	for (i = 0; i < 2*n; i += 2)
	{
                scanf("%d%d", &arr[i].vl, &arr[i+1].vl);
		arr[i].open = true;
		arr[i+1].open = false;
	}
        sort(arr, arr+2*n);
	int ans = 0;
	j = 0;
	for (i = 0; i < 2*n; ++i)
	{
		if (j > 0)
		{
			ans += (arr[i].vl-arr[i-1].vl);
		}
		if (arr[i].open)
		{
			++j;
		}
		else
		{
			--j;
		}
	}
        printf("%d\n", ans);
	return 0;
}
