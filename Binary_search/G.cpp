#include <iostream>
#include <vector>

bool good(std::vector<int> &ropes, int x, int k) {
    int count = 0;
    for (int rope: ropes) {
        count += rope / x;
    }
    return count >= k;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> ropes;
    int len;
    for (int i = 0; i < N; i++) {
        std::cin >> len;
        ropes.push_back(len);
    }

    int l, r, m;

    l = 0;
    r = 1e7+1;
    while ((r - l) > 1) {
        m = (l + r) / 2;
        if (good(ropes, m, K)) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << l;
}

/*
4 11
802
743
457
539
 */
