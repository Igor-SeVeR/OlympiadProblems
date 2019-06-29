#define _GLIBCXX_DEBUG
#define DEBUG 1

#include "testlib.h"
using namespace std;

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);

        // Read input
        int n = inf.readInt(1, 1000);
        inf.readLine();
        vector<int> dist(n);
        dist[0] = inf.readInt(1, 1000);
        for (int i = 1; i < n; ++i)
        {
            inf.readSpace();
            dist[i] = inf.readInt(1, 1000);
        }
        inf.readLine();
        vector<int> cost(n);
        cost[0] = inf.readInt(1, 10000);
        for (int i = 1; i < n; ++i)
        {
            inf.readSpace();
            cost[i] = inf.readInt(1, 10000);
        }
        inf.seekEof();

        // Calculate participant's answer
        long long pa = 0;
        int num = ouf.readInt(1, 1000);
        pa += dist[0] * cost[num - 1];
        for (int i = 1; i < n; ++i)
        {
            ouf.readSpace();
            num = ouf.readInt(1, 1000);

            pa += dist[i] * cost[num - 1];
        }
        ouf.seekEof();

        // Calculate jury's answer
        long long ja = 0;
        num = ans.readInt(1, 1000);
        ja += dist[0] * cost[num - 1];
        for (int i = 1; i < n; ++i)
        {
            ans.readSpace();
            num = ans.readInt(1, 1000);

            ja += dist[i] * cost[num - 1];
        }
        ans.seekEof();

        if (ja == pa)
            quitf(_ok, "OK");
        else if (ja < pa)
            quitf(_wa, "WA");
        else // ja > pa
            quitf(_fail, "test error");
}
