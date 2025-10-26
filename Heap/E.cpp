#include <iostream>
#include <queue>
#include <iomanip>


int main() {
    std::priority_queue<int> heapMin;

    int N, num;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        heapMin.push(-num);
    }
    int a, b, sum;
    double price = 0;
    while (heapMin.size() > 1) {
        a = -heapMin.top();
        heapMin.pop();
        b = -heapMin.top();
        heapMin.pop();
        sum = a + b;
        price += sum * 0.05;
        heapMin.push(-sum);
    }
    std::cout << std::fixed << std::setprecision(2) << price << std::endl;
}
