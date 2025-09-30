#include <iostream>
#include <vector>
#include <string>
#include <deque>

template<typename T>

class StrangeQueue {
private:
    std::deque<T> left;
    std::deque<T> right;

public:
    void equality() {
        if (left.size() < right.size()) {
            left.push_back(right.front());
            right.pop_front();
        } else if (left.size() > right.size() + 1) {
            right.push_front(left.back());
            left.pop_back();
        }
    }
    void ordinary_push(T n) {
        right.push_back(n);
        equality();
    }

    void privilege_push(T n) {
        if (left.size() == right.size()) {
            left.push_back(n);
        } else {
            right.push_front(n);
        }
    }

    void pop() {
        std::cout << left[0] << std::endl;
        left.erase(left.begin());
        equality();
    }

};

int main() {
    int N;
    std::cin >> N;

    StrangeQueue<int> queue;
    std::string command;
    int idx;
    for (int i = 0; i < N; i++) {
        std::cin >> command;
        if (command == "+") {
            std::cin >> idx;
            queue.ordinary_push(idx);
        } else if (command == "*") {
            std::cin >> idx;
            queue.privilege_push(idx);
        } else if (command == "-") {
            queue.pop();
        }
    }
}
