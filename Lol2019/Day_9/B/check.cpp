#include "testlib.h"
#include <string>
#include <vector>
using namespace std;
vector<string> teams, tmp;
int n;

bool set_equal(vector<string> tmp) {
	sort(tmp.begin(), tmp.end());
	return (tmp == teams);
}

bool check(InStream& in) {
	tmp[0] = in.readLine();
	if (tmp[0] == "Impossible") return false;
	for (int i = 1; i < n; ++i)
		tmp[i] = in.readLine();
	if (!set_equal(tmp)) in.quitf(_wa, "Incorrect team list (set of team names doesn't correspond to the input data)");
	for (char c = 'A'; c <= 'C'; ++c) {
		int l = -1, r = -1, cnt = 0;
		for (int i = 0; i < n; ++i) {
			string type = tmp[i].substr(0, tmp[i].find(' '));
			if (type.find(c) != string::npos) {
				if (l == -1) l = i;
				r = i;
				cnt++;
			}
		}
		if ((cnt > 0) && (cnt != r - l + 1)) in.quitf(_wa, "problems for league %c are not ordered properly", c);
	}
	return true;
}

int main(int argc, char ** argv) {
	registerTestlibCmd(argc, argv);
	n = inf.readInt();
	inf.readEoln();
	teams = tmp = vector<string>(n);
	for (int i = 0; i < n; ++i)
		teams[i] = inf.readLine();
	sort(teams.begin(), teams.end());
	bool jury_has_answer = check(ans), contestant_has_answer = check(ouf);
	if (jury_has_answer && !contestant_has_answer) quitf(_wa, "Contestant didn't manage to find the solution");
	if (!jury_has_answer && contestant_has_answer) quitf(_fail, "Jury didn't manage to find the solution");
	quitf(_ok, "ok %d names, solution %s", n, jury_has_answer ? "exists" : "doesn't exist");
}

