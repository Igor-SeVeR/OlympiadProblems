#define _CRT_SECURE_NO_DEPRECATE
#define NOFOOTER
#include "testlib.h"

void check(bool v)
{
	if (!v) quit(_fail, "check error");
}

int main(int argc, char ** argv)
{
    registerTestlibCmd(argc, argv);
    int N = inf.readInt();
    int a = inf.readInt();
    int b = inf.readInt();
    check(1 <= N && N <= 100 && 10000 <= a && a <= 30000 && b >= 0 && b < 100);
    check(b*N % 100 == 0);

    {
    	int s = 0;
    	for (int i = 0; i < N; ++i)
    	{
    		int x = ouf.readInt();
    		if (x < 500 || x > 100000) quit(_wa, "too small or too big salary found");
            s += x;
    	}
        if (s != (a*N + b*N / 100)) quit(_wa, "wrong mean salary");
        quit(_ok, "");
    }

    return 0;   
}
