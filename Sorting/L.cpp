#include <iostream>
#include <ratio>
#include <vector>
#include <sstream>
#include <algorithm>


bool compare_increasing(int x, int y) {
    return x > y;
}


bool compare_decreasing(int x, int y) {
    return x < y;
}

int main() {

    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss1(input);

    std::vector<int> kilometers;
    int num;

    while (iss1 >> num) {
        kilometers.push_back(num);
    }

    std::getline(std::cin, input);
    std::istringstream iss2(input);
    std::vector<int> prices;
    int N = kilometers.size();
    int count = 0;

    while (iss2 >> num and count <= N) {
        prices.push_back(num);
        count ++;
    }

    std::sort(kilometers.begin(), kilometers.end(), compare_increasing);
    std::sort(prices.begin(), prices.end(), compare_decreasing);

    int result_sum = 0;

    for (int i = 0; i < N; i++) {
        result_sum += kilometers[i]*prices[i];
    }

    std::cout << result_sum;

}