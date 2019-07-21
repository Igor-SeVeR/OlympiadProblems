#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <deque>

using namespace std;

struct list {
	int num;
	int dest;
	int v;
	double t;
};

bool compareByTime(const list &a, const list &b)
{
	return a.dest*b.v < b.dest*a.v;
}

int main()
{
	int n, v;
	cin >> n >> v;
	int a, b;
	vector<list> pupil;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
                pupil.push_back({ i + 1, a, b, (double)a / b });
	}
	sort(pupil.begin(), pupil.end(), compareByTime);
	double ansTime = 0;
	double ansCount = 0;
	vector<int> ansNum;
	vector<double> ansDest;
	double totalDest = 0;
	while (pupil.size())
	{
		list curPupil = pupil.back();
		pupil.pop_back();
                if (totalDest*curPupil.v >= curPupil.dest * v)
			break;
                double destToScool = (curPupil.dest * v - totalDest * curPupil.v)/(v + curPupil.v);
		totalDest += 2 * destToScool;
		ansCount++;
		ansNum.push_back(curPupil.num);
		ansDest.push_back(destToScool);
	}
	cout.precision(20);
        cout << totalDest / v << ' ' << ansCount << '\n';
	for (int i = 0; i < ansNum.size(); i++)
                cout << ansNum[i] << ' ' << ansDest[i] << '\n';
	
	return 0;
}
