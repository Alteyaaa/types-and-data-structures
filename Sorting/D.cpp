#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int BubbleSort(std::vector<int> &list) {
    int counter = 0;
    int n = list.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 1; j < n; j++) {
            if (list[j - 1] > list[j]) {
                std::swap(list[j - 1], list[j]);
                counter++;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
    return counter;
}

// 1 4 2 3 4

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // игнорируем следующий символ /n, чтобы его потом не считал getline()


    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);

    std::vector<int> list;
    int num;

    while (iss >> num && list.size() < n) {
        list.push_back(num);
    }

    std::cout << BubbleSort(list);
}
