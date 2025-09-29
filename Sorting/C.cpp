#include <iostream>
#include <string>
#include <sstream>
#include <vector>


void BubbleSort(std::vector<int> &list) {
    int n = list.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j] < list[j+1]) {
                std::swap(list[j], list[j+1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}

// 1 4 2 3 4

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);

    std::vector<int> list;
    int num;

    while (iss >> num) {
        list.push_back(num);
    }

    BubbleSort(list);

    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << ' ';
    }
}
