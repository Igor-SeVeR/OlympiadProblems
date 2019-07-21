#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

bool isValid(int c) {
    return (65 <= c && c <= 90) || (97 <= c && c <= 99);
}

std::map<int, std::set<char>> findOptions(std::string s) {
    int c1 = std::stoi(s.substr(1));
    int c2 = (s[0] - '0') * 10 + s[2] - '0';
    int c3 = std::stoi(s.substr(0, 2));
    std::map<int, std::set<char>> ans;
    if (isValid(c1)) {
        ans[(int)(s[0] - '0')].insert((char)c1);
    }
    if (isValid(c2)) {
        ans[(int)(s[1] - '0')].insert((char)c2);
    }
    if (isValid(c3)) {
        ans[(int)(s[2] - '0')].insert((char)c3);
    }
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;
    std::vector<char> result(s.size() / 3, (char)-1);
    std::vector<std::map<int, std::set<char>>> options(s.size() / 3);
    std::vector<int> used(10, 0);
    bool allThree = true;
    int three = 0;
    for (int i = 0; i < (int)s.size(); i += 3) {
        int c = std::stoi(s.substr(i, 3));
        if (100 <= c && c <= 122) {
            result[i / 3] = (char)c;
            three++;
        } else {
            allThree = false;
            options[i / 3] = findOptions(s.substr(i, 3));
            for (auto p : options[i / 3]) {
                used[p.first]++;    
            }
        }
    }
    if (allThree) {
        std::cout << 1 << '\n';
        return 0;
    }
    std::vector<int> digits;
    for (int i = 0; i < 10; i++) {
        if (used[i] == (int)s.size() / 3 - three) {
            digits.push_back(i);
        }
    }
    int answer = 0;
    for (int d : digits) {
        long long p = 1;
        for (int i = 0; i < (int)s.size() / 3; i++) {
            if (result[i] != -1) {
                continue;
            }
            p = (p * (long long)options[i][d].size()) % MOD;
        }
        answer = (answer + p) % MOD;
    }
    std::cout << answer << '\n';
    return 0;
}
