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
	string s, a;
	char now = 'a';
	int ans = 0;
	cin >> s;
	a += '*';
	for (int i = 0; i < 3; i++)
		for (char j = 'a'; j <= 'z'; j++)
			a += j;

	for (int i = 0; i < s.size(); i++)
	{
		int s1 = 0, s2 = 0;
		for (int j = 26 + now - 'a' + 1; j <= 26 * 3; j++, s1++)
			if (a[j] == s[i])
				break;
		for (int j = 26 + now - 'a' + 1; j >= 1; j--, s2++)
			if (a[j] == s[i])
				break;
		ans += min(s1, s2);
		now = s[i];
	}
	cout << ans << endl;
	return 0;
}