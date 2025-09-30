#include <iostream>
#include <vector>
#include <string>

template<typename T>

class Stack {
private:
    std::vector<T> items;

public:
    bool is_empty() {
        return items.size() == 0;
    }

    void push() {
        T n;
        std::cin >> n;
        items.push_back(n);
        std::cout << "ok" << std::endl;
    }

    void pop() {
        if (is_empty()) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << items.back() << std::endl;
            items.pop_back();
        }
    }

    void back() {
        if (is_empty()) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << items.back() << std::endl;
        }
    }

    void size() {
        std::cout << items.size() << std::endl;
    }

    void clear() {
        items.clear();
        std::cout << "ok" << std::endl;
    }

    void exit() {
        std::cout << "bye" << std::endl;
    }
};

int main() {
    Stack<int> stack;
    std::string command;
    while (std::cin >> command) {
        if (command == "push") {
            stack.push();
        }
        else if (command == "pop") {
            stack.pop();
        }
        else if (command == "back") {
            stack.back();
        }
        else if (command == "size") {
            stack.size();
        }
        else if (command == "clear") {
            stack.clear();
        }
        else if (command == "exit") {
            stack.exit();
            break;
        }
    }
}
