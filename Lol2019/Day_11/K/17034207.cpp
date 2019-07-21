#include <iostream>

std::string add_character(std::string& str, char ch, int count) {
    for (; count > 0; --count) {
        str += ch;
    }

    return str;
}

int main() {
    int N = 0;
    std::cin >> N;

    std::string braces;
    add_character(braces, '(', N);
    add_character(braces, ')', N);
    std::cout << braces << std::endl;

    int open = 0;
    int close = 0;
    int pairs = 1;
    while (pairs > 0) {
        pairs = 0;
        for (int i = braces.size() - 1; i >= 0; --i) {
            if (braces[i] == ')') {
                ++pairs;
            }
            else {
                --pairs;
            }

            if (braces[i] == '(' && pairs > 0) {
                braces[i] = ')';

                for (open = (2 * N - i - 1 - pairs + 1) / 2; open > 0; --open, ++i) {
                    braces[i + 1] = '(';
                }
                for (close = 2 * N - i - 1 - open; close > 0; --close, ++i) {
                    braces[i + 1] = ')';
                }
                std::cout << braces << std::endl;
                break;
            }
        }
    }
}
