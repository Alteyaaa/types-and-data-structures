#include <iostream>
#include <vector>
#include <string>

template<typename T>

class Deque {
private:
    std::vector<T> items;

public:
    bool is_empty() {
        return items.size() == 0;
    }

    void push_front() {
        T n;
        std::cin >> n;
        items.insert(items.begin(), n);
        std::cout << "ok" << std::endl;
    }

    void push_back() {
        T n;
        std::cin >> n;
        items.push_back(n);
        std::cout << "ok" << std::endl;
    }

    void pop_front() {
        if (is_empty()) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << items[0] << std::endl;
            items.erase(items.begin());
        }
    }

    void pop_back() {
        if (is_empty()) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << items.back() << std::endl;
            items.pop_back();
        }
    }

    void front() {
        if (is_empty()) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << items[0] << std::endl;
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
    Deque<int> stack;
    std::string command;
    while (std::cin >> command) {
        if (command == "push_front") {
            stack.push_front();
        }
        else if (command == "push_back") {
            stack.push_back();
        }
        else if (command == "pop_back") {
            stack.pop_back();
        }
        else if (command == "pop_front") {
            stack.pop_front();
        }
        else if (command == "front") {
            stack.front();
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
