#define _GLIBCXX_DEBUG
#define DEBUG 1

#include "testlib.h"
#include <string>
using namespace std;

int operate(string command)
{
    long long x = 1;
    for (char c : command)
    {
        if (c == 1)
            x++;
        else if (c == 2)
            x *= 2;
        else if (c == 3)
            x *= 3;
    }
    return x;
}

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);

        int a = inf.readInt(1, 1000000);
        string pa = ouf.readString("[1-3]*");
        string ja = ans.readString("[1-3]*");

        if (a == 1)
        {
            if (ja == "0" || ja == "")
            {
                if (pa == "")
                    quitf(_ok, "OK");
                quitf(_wa, "wa");
            }
            quitf(_fail, "Test error");
        }

        long long jx = operate(ja);
        long long px = operate(pa);

        if (jx != a)
            quitf(_fail, "Test error");

        if (jx == px)
        {
            if (ja.length() < pa.length())
                quitf(_wa, "wa");
            else if (ja.length() == pa.length())
                quitf(_ok, "OK");
            else // ja.length() > pa.length()
                quitf(_fail, "Participant has better answer: %s < %s", pa, ja);
        }
        else
            quitf(_wa, "wa");
}
