#include <iostream>
#include <vector>
#include <stack>


int main() {
    std::vector<int> enter;
    std::vector<int> exit;
    std::stack<int> middle;

    int N, num;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> num;
        enter.push_back(num);
    }

    int current_idx = 1;
    for (int i = 0; i < N; i++) {
        while (!middle.empty() && middle.top() == current_idx) {
            exit.push_back(middle.top());
            middle.pop();
            current_idx++;
        }
        middle.push(enter[i]);

        while (!middle.empty() && middle.top() == current_idx) {
            exit.push_back(middle.top());
            middle.pop();
            current_idx++;
        }
    }
    bool correct = true;
    if (!middle.empty()) {
        correct = false;
    }
    if (exit.size() == N ) {
        for (int i = 0; i < N; i++) {
            if (exit[i] != i + 1) {
                correct = false;
                break;
            }
        }
    }
    if (correct) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}