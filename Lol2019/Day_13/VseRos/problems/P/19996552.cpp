#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int lineWidth, abstractStart;
    cin >> lineWidth >> abstractStart;
    cin.ignore();

    vector<string> text;
    string s, buf;
    while (1) {
        getline(cin, buf);
        if (!buf.empty()) {
            s += buf;
            s += " ";
        } else {
            if (!s.empty()) {
                text.push_back(s);
                s = "";
            }
        }
        if (cin.eof())
            break;
    }

    for (int ti = 0; ti < text.size(); ti++) {
        string &s = text[ti];

        string abstract, line, word;
        for (int i = 0; i < abstractStart; i++)
            line += " ";
        enum State { IN, OUT } state = IN;
        for (int i = 0; i < s.size(); i++) {
            if (state == IN) {
                if (isalnum(s[i])) {
                    word += s[i];
                } else {
                    state = OUT;
                    i--;
                }
            } else {
                if (!isalnum(s[i])) {
                    if (s[i] != ' ')
                        word += s[i];
                } else {
                    if ((line.empty() || line[line.size() - 1] == ' ') && line.size() + word.size() <= lineWidth) {
                        line += word;
                    } else if (!line.empty() && line[line.size() - 1] != ' ' && line.size() + 1 + word.size() <= lineWidth) {
                        line += " ";
                        line += word;
                    } else {
                        abstract += line;
                        abstract += "\n";
                        line = word;
                    }
                    word = "";
                    state = IN;
                    i--;
                }
            }
        }

        if ((line.empty() || line[line.size() - 1] == ' ') && line.size() + word.size() <= lineWidth) {
            line += word;
        } else if (!line.empty() && line[line.size() - 1] != ' ' && line.size() + 1 + word.size() <= lineWidth) {
            line += " ";
            line += word;
        } else {
            abstract += line;
            abstract += "\n";
            line = word;
        }

        if (!line.empty()) {
            abstract += line;
            abstract += "\n";
        }

        cout << abstract;
    }

}