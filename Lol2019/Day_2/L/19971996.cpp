#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k_vid;
	cin >> k_vid;
	vector<deque<int>> sklad(k_vid + 1);
	if (k_vid > 2) {
		for (int i = 1; i <= k_vid; i++) {
			int k_cont, dop;
			cin >> k_cont;
			for (int j = 0; j < k_cont; j++) {
				cin >> dop;
				sklad[i].push_back(dop);
			}
			if (i != 1) {
				while (!sklad[i].empty()) {
					cout << i << " " << 1 << "\n";
					sklad[1].push_back(sklad[i].back());
					sklad[i].pop_back();
				}
			}
		}
		while (!sklad[1].empty()) {
			if (sklad[1].back() != 1) cout << 1 << " " << sklad[1].back() << "\n";
			else cout << "1 2\n";
			if (sklad[1].back() == 1) sklad[2].push_back(sklad[1].back());
			else sklad[sklad[1].back()].push_back(sklad[1].back());
			sklad[1].pop_back();
		}
		while (!sklad[2].empty()) {
			if (sklad[2].back() == 1) {
				cout << "2 1\n";
				sklad[1].push_back(sklad[2].back());
			}
			else {
				cout << "2 3\n";
				sklad[3].push_back(sklad[2].back());
			}
			sklad[2].pop_back();
		}
		while (!sklad[3].empty() && sklad[3].back() == 2) {
			cout << "3 2\n";
			sklad[3].pop_back();
		}
	}
	else if (k_vid > 1) {
		vector<pair<int, int>> vivod;
		for (int i = 1; i <= k_vid; i++) {
			int k_cont, dop;
			cin >> k_cont;
			for (int j = 0; j < k_cont; j++) {
				cin >> dop;
				sklad[i].push_back(dop);
			}
			if (i != 1) {
				while (!sklad[i].empty()) {
					vivod.push_back({ i, 1 });
					sklad[1].push_back(sklad[i].back());
					sklad[i].pop_back();
				}
			}
		}
		vector<int> dop1, dop2;
		for (int i = 0; i < sklad[1].size(); i++) {
			dop1.push_back(sklad[1][i]);
			dop2.push_back(sklad[1][i]);
		}
		sort(dop2.begin(), dop2.end());
		if (dop1 != dop2) cout << 0;
		else {
			for (int i = 0; i < vivod.size(); i++) {
				pair<int, int> x = vivod[i];
				cout << x.first << " " << x.second << "\n";
			}
			while (!sklad[1].empty() && sklad[1].back() == 2) {
				cout << 1 << " " << sklad[1].back() << "\n";
				if (sklad[1].back() == 1) sklad[2].push_back(sklad[1].back());
				else sklad[sklad[1].back()].push_back(sklad[1].back());
				sklad[1].pop_back();
			}
		}
	}
	else {
		for (int i = 1; i <= k_vid; i++) {
			int k_cont, dop;
			cin >> k_cont;
			for (int j = 0; j < k_cont; j++) {
				cin >> dop;
				sklad[i].push_back(dop);
			}
		}
	}
	return 0;
}