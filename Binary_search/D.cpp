#include <iomanip>
#include <iostream>

double f(double x, double a, double b, double c, double d) {
    return a * x * x * x + b * x * x + c * x + d;
}

double root(double a, double b, double c, double d) {
    double l, r, m;
    l = -1001; // чтобы точно покрыть все возможные варианты
    r = 1001;
    for (int i = 0; i < 30; i ++) {
        m = (l+r)/2;
        if (f(l, a, b, c, d)*f(m, a, b, c, d) <= 0) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return (l+r)/2;
}

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::cout << std::fixed << std::setprecision(15) << root(a, b, c, d);
}
