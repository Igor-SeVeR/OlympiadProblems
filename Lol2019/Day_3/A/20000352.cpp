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
	int n, k, sumn = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		sumn += i;
	cout << k / sumn << endl;
}