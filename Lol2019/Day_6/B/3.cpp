#include <cstdio>
#include <algorithm>

using namespace std;

const int BOUND = 1e4;

int calc(pair<int, int> A, pair<int, int> B) {
    return max(abs(A.first - B.first), abs(A.second - B.second));
}

int main() {
    pair<int, int> A, B, zero = {0, 0};
    scanf("%d%d%d%d", &A.first, &A.second, &B.first, &B.second);
    int best_dist = -1;
    for (int x = -BOUND; x <= BOUND; ++x)
        for (int y = -BOUND; y <= BOUND; ++y) {
            int dist = calc(A, {x, y}) + calc(zero, {x, y}) + calc(B, {x, y});
            if (best_dist == -1 || dist < best_dist)
                best_dist = dist;
        }
    printf("%d", best_dist);
}

