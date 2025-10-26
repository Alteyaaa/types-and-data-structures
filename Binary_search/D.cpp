#include <iomanip>
#include <iostream>

double f(double x, double a, double b, double c, double d) {
    return a * x * x * x + b * x * x + c * x + d;
}

double root(double a, double b, double c, double d) {
    double l, r, m;
    l = -1001; // чтобы точно покрыть все возможные варианты
    r = 1001;
    if (a > 0) {
        for (int i = 0; i < 100; i++) {
            m = (l + r) / 2;
            if (f(m, a, b, c, d) < 0) {
                l = m;
            } else {
                r = m;
            }
        }
        return m;
    }
    for (int i = 0; i < 100; i++) {
        m = (l + r) / 2;
        if (f(m, a, b, c, d) < 0) {
            r = m;
        } else {
            l = m;
        }
    }
    return m;
}


int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::cout << std::fixed << std::setprecision(15) << root(a, b, c, d);
}
