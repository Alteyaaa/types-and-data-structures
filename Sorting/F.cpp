#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> QuickSort(std::vector<int> &list) {
    if (list.size() <= 1) {
        return list;
    }
    int pivot = list[list.size() / 2];
    std::vector<int> left, right, middle;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] < pivot) {
            left.push_back(list[i]);
        } else if (list[i] > pivot) {
            right.push_back(list[i]);
        } else {
            middle.push_back(list[i]);
        }
    }

    left = QuickSort(left);
    right = QuickSort(right);

    std::vector<int> result;
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), middle.begin(), middle.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);

    int num;
    std::vector<int> list;

    while (iss >> num && list.size() < n) {
        list.push_back(num);
    }

    list = QuickSort(list);

    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << ' ';
    }
}
