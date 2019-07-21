#include <iostream>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() 
{
	int n, t, r = 0;
	cin >> n;
	while (n--) 
	{
		cin >> t;
		t -= r;
		if (0 > t)
			break;
		r = t % 2;
	}
	if (r)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}