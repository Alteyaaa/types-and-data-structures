#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void CountSort(std::vector<int> &list) {
    int max = list[0];
    for (int i = 1; i < list.size(); i++) {
        if (list[i] > max) {
            max = list[i];
        }
    }
    std::vector<int> counter(max + 1);
    for (int i = 0; i < list.size(); i++) {
        counter[list[i]]++;
    }
    list.clear();
    // Перебираем числа от 1 до max
    for (int i = 0; i < max+1; i++) {
        for (int j = 0; j < counter[i]; j++) {
            list.push_back(i);
        }
    }
}

// 7 3 4 2 5

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);


    std::vector<int> list;
    int num;
    while (iss >> num) {
        list.push_back(num);
    }

    CountSort(list);

    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << ' ';
    }
}