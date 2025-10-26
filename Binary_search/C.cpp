#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

double f(double x) {
    return x*x+sqrt(x);
}

double root(double c) {
    double l, r, m, current;
    l = 0;
    r = c;
    for (int i = 0; i < 100; i++) {
        m = (l+r)/2;
        current = f(m);
        if (current == c) {
            return m;
        }
        if (current < c) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return m;
}

int main() {
    double c;
    std::cin >> c;


    std::cout << std::fixed << std::setprecision(6) << root(c);
}