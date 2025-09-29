#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

class Point {
    int x;
    int y;

    // конструктор
public:
    Point(int a, int b) : x(a), y(b) {
    }

    // геттеры
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int getDistance() {
        int distance = pow(x, 2) + pow(y, 2);
        return distance;
    }
};

std::vector<Point> pointQuickSort(std::vector<Point> &arr) {
    int n = arr.size();
    if (n <= 1) {
        return arr;
    }
    int middle = arr[n / 2].getDistance();
    std::vector<Point> left, right, mid;
    for (int i = 0; i < n; i++) {
        if (arr[i].getDistance() < middle) {
            left.push_back(arr[i]);
        } else if (arr[i].getDistance() > middle) {
            right.push_back(arr[i]);
        } else {
            mid.push_back(arr[i]);
        }
    }
    left = pointQuickSort(left);
    right = pointQuickSort(right);
    std::vector<Point> result;
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), mid.begin(), mid.end());
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Point> arr;
    int x, y;

    for (int i = 0; i < n; i++) {
        std::cin >> x >> y;
        arr.push_back(Point(x, y));
    }

    arr = pointQuickSort(arr);


    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i].getX() << ' ' << arr[i].getY() << std::endl;
    }
}
