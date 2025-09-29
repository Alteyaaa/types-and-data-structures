#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void InsertionSort(std::vector<int> &list) {
    int n = list.size();
    for (int i = 1; i < n; i++) {
        int key = list[i];
        int j = i;
        while (j > 0 && key < list[j - 1]) {
            list[j] = list[j - 1];
            j--;
        }
        list[j] = key;
    }
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);

    std::vector<int> list;
    int num;
    while (iss >> num) {
        list.push_back(num);
    }

    InsertionSort(list);

    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << ' ';
    }
}
