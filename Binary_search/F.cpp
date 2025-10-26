#include <iostream>

bool good(int x, int y, int t, int N) {
    return t / x + t / y >= (N - 1);
}

int main() {
    int N, x, y;
    std::cin >> N >> x >> y;
    if (x > y) {
        std::swap(x, y);
    }

    int l, r, m;
    l = 0;
    r = (N - 1) * y;
    while ((r - l) > 1) {
        m = (r + l) / 2;
        if (!good(x, y, m, N)) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << r + x;
}
