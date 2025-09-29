#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> nums(N, 0);

    // Базовые случаи
    if (N==1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    nums[0] = 1;
    nums[1] = 2;

    // На каждой итерации ставим предыдущий серединный элемент в текущую позицию i
    // А на его место в середине в [i/2] ставим элемент, который на одно значение больше, тем самым "раздвигая"
    // массив добавлением нового элемента в середину между старыми
    for (int i = 2 ; i < N; i++) {
        nums[i] = nums [i/2];
        nums[i/2] = i+1;
    }


    for (int i = 0; i < N; i++) {
        std::cout << nums[i] << " ";
    }
}