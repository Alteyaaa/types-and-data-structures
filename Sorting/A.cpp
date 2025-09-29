#include <iostream>
#include <vector>
#include <string>
#include <sstream>

void SelectionSort(std::vector<int> &list) {
    int n = list.size();
    for (int i = 0; i < n - 1; i++) {
        int max = list[i];
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (list[j] > max) {
                max = list[j];
                m = j;
            }
        if (m != i) {
            std::swap(list[i], list[m]);
        }
    }
}


int main() {
    std::string input;
    std::getline(std::cin, input); //потоковое заполнение input (читает вместе с пробелами)
    std::istringstream iss(input); //разделение строки на отдельные части, исключая пробелы


    std::vector<int> list;
    int num;
    while (iss >> num) {
        list.push_back(num);
    }

    SelectionSort(list);

    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << ' ';
    }
}
