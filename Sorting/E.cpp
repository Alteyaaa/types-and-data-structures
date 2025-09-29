#include <iostream>
#include <vector>
#include <string>
#include <sstream>


std::vector<int> Merge(std::vector<int> &left, std::vector<int> &right) {
    int i = 0, j =0;
    std::vector<int> result;
    while (i < left.size() && j < right.size()) {
        if (left[i] <right[j]) {
            result.push_back(left[i]);
            i++;
        }
        else {
            result.push_back(right[j]);
            j++;
        }
    }
    result.insert(result.end(), left.begin() + i, left.end());
    result.insert(result.end(), right.begin() + j, right.end());

    return result;
}

std::vector<int> MergeSort(std::vector<int> &list) {
    int n = list.size();
    if (n <= 1) {
        return list;
    }
    int middle = n / 2;
    std::vector<int> left;
    std::vector<int> right;
    for (int i = 0; i < n; i++) {
        if (i < middle) {
            left.push_back(list[i]);
        }
        else {
            right.push_back(list[i]);
        }
    }
    left = MergeSort(left);
    right = MergeSort(right);

    return Merge(left,right);
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

    list = MergeSort(list);

    for (int i = 0; i < n; i++) {
        std::cout << list[i] << ' ';
    }
}