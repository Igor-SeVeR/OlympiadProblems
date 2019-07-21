#include "testlib.h"
#include <vector>
#include <algorithm>

const int maxn = 1e5;

const std::vector<int> MAXN = {100000, 30, 100000, 1000, 100000};

bool isValid(int c, int group) {
    return (65 <= c && c <= 90) || (97 <= c && c <= 99);
}

std::vector<int> removePossibleDigits(std::string s, int group) {
    int c1 = std::stoi(s.substr(1));
    int c2 = (s[0] - '0') * 10 + s[2] - '0';
    int c3 = std::stoi(s.substr(0, 2));
    std::set<int> ans;
    if (isValid(c1, group)) {
        ans.insert(s[0] - '0');
    }
    if (isValid(c2, group)) {
        ans.insert(s[1] - '0');
    }
    if (isValid(c3, group)) {
        ans.insert(s[2] - '0');
    }
    std::vector<int> answer(ans.begin(), ans.end());
    return answer;
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int group = group = atoi(validator.group().c_str());
    std::string s = inf.readLine();
    ensuref(3 <= s.size() && s.size() <= MAXN[group], format("s.length should be in [3, %d]", MAXN[group]).c_str());
    ensuref(s.size() % 3 == 0, format("s.length = %d should be divisible by 3", (int)s.size()).c_str());
    for (int i = 0; i < s.size(); i++) {
        ensuref('0' <= s[i] && s[i] <= '9', format("s[%d] should be a digit", i + 1).c_str());
    }
    if (group == 1 || group == 2) {
        for (int i = 0; i < (int)s.size(); i += 3) {
            std::string t = s.substr(i, 3);
            bool found = false;
            for (int j = 0; j < 3; j++) {
                found |= t[j] == '1';
            }
            ensuref(found, "s was encoded incorrectly");
        }
    }
    /*std::vector<int> cnt(10, 0);
    int cntok = 0;
    for (int i = 0; i < (int)s.size(); i += 3) {
        int c = std::stoi(s.substr(i, 3));
        if (c >= 100 && c <= 122) {
            cntok++;
            continue;
        }
        std::vector<int> possible = removePossibleDigits(s.substr(i, 3), group);
        for (int d : possible) cnt[d]++;
    }
    int found = false;
    int mind = (group == 1 || group == 2) ? 1 : 0;
    int maxd = (group == 1 || group == 2) ? 1 : 9;
    for (int i = mind; i <= maxd; i++) {
        found |= (cnt[i] == (int)s.size() / 3 - cntok);
    }
    ensuref(found, "s was encoded incorrectly");*/
    inf.readEof();
    return 0;
}
