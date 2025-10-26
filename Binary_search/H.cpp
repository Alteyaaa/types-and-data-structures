#include <algorithm>
#include <iostream>

bool good(long long a, long long w, long long h, long long n) {
    return (a / w) * (a / h) >= n;
}

int main() {
    long long w, h, n;
    std::cin >> w >> h >> n;

    long long l, r, m;
    l = 0;
    r = n*std::max(w, h);
    while ((r - l) > 1) {
        m = (l + r) / 2;
        if (good(m, w, h, n)) {
            r = m;
        } else {
            l = m;
        }
    }
    std::cout << r;
}
