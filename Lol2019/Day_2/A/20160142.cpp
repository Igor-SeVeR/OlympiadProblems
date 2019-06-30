
#include<string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	set<int>a;
	string q;
	getline(cin, q);
	q += " ";
	string n = "";
	for (auto c : q) {
		if (int(c) != 32) {
			n += c;
		}
		else {
			v1.push_back(stoi(n));
			n = "";
		}
	}
	getline(cin, q);
	q += " ";
	for (auto c : q) {
		if (int(c) != 32) {
			n += c;
		}
		else {
			v2.push_back(stoi(n));
			n = "";
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
	a.insert(v3.begin(), v3.end());
	for (auto now : a) {
		cout << now << " ";
	}
}
