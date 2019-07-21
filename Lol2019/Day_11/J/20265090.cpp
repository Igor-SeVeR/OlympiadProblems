#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
using namespace std;

long long fact(long long x) {
	long long temp = 1;
	for (long long i = 2; i <= x; ++i) {
		temp *= i;
	}
	return temp;
}

int main() {
	multiset <char> a;
	set <char> a1;
	string str;
	cin >> str;
	for (auto i : str) {
		a.insert(i);
		a1.insert(i);
	}
	vector <long long> s;
	long long ans;
	ans = fact(str.size());
	for (auto i : a1) {
		ans /= fact(a.count(i));
	}
	cout << ans;
}