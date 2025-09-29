#include <iostream>
#include <string>
#include <vector>
#include <sstream>

bool compare(std::string &first_num, std::string &second_num) {
    return (first_num + second_num < second_num + first_num);
}


void bubbleSort(std::vector<std::string> &list) {
    int n = list.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(list[j], list[j + 1])) {
                std::swap(list[j], list[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}


int main() {
    std::string input;
    std::vector<std::string> nums;

    while (std::getline(std::cin, input)) {
        if (input.empty()) {
            break;
        }
        nums.push_back(input);
    }

    bubbleSort(nums);

    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i];
    }
}
