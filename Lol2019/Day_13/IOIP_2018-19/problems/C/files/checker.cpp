#include <bits/stdc++.h>
#include "testlib.h"

int diff(int a, int b) {
    std::string sc = std::to_string(a), tc = std::to_string(b);
    std::sort(sc.begin(), sc.end());
    std::sort(tc.begin(), tc.end());
    tc.push_back('z' + 1);
    for (int i = 0, j = 0; i < (int)sc.size() && j < (int)tc.size(); i++, j++) {
        if (sc[i] != tc[i]) {
            return sc[i] - '0';
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    std::string inps = inf.readLine();
    int pn = ouf.readInt();
    ouf.readLine();
    int jn = ans.readInt();
    if (pn < jn) {
        quitf(_wa, format("Expected %d strings, but found %d", jn, pn).c_str());
    }
    std::set<std::string> alls;
    for (int it = 0; it < pn; it++) {
        std::string s = ouf.readLine();
        if (s.size() != inps.size() / 3) {
            quitf(_wa, format("output[%d].length should be %d, but is %d", it + 1, (int)inps.size() / 3, (int)s.size()).c_str());
        }
        for (int i = 0; i < (int)s.size(); i++) {
            if (!(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))) {
                quitf(_wa, format("output[%d][%d] expected to be in a..z or A..Z, but is %c", it + 1, i + 1, s[i]).c_str());
            }
        }
        if (alls.find(s) != alls.end()) {
            quitf(_wa, format("output[%d] is duplicate", it + 1).c_str());
        }
        alls.insert(s);
        int alld = -1;
        for (int i = 0, j = 0; i < (int)inps.size() && j < (int)s.size(); i += 3, j++) {
            if (100 <= s[j]) {
                if ((int)s[j] != std::stoi(inps.substr(i, 3))) {
                    quitf(_wa, format("input[%d..%d] expected to be equal to output[%d][%d], but it isn't", i + 1, i + 3, it + 1, j + 1).c_str());
                }
            } else {
                int d = diff(std::stoi(inps.substr(i, 3)), (int)s[j]);
                if (alld == -1 || alld == d) {
                    alld = d;
                } else {
                    quitf(_wa, format("output[%d] is incorrect", it + 1).c_str());
                }
            }
        }
    }
    if (pn > jn) {
        quitf(_fail, format("Participant has found %d decodings while jury only %d", pn, jn).c_str());
    }
    quitf(_ok, format("%d possible decodings", jn).c_str());
    return 0;
}
