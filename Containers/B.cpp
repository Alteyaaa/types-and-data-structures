#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>


int main() {
    std::stack<char> stack;
    std::unordered_map<char, char> brackets = {{')', '('},
                                            {']','['},
                                            {'}','{'}};
    std::string sequence;
    std::cin >> sequence;
    bool right = true;
    for (char el: sequence) {
        if (el == '(' || el == '[' || el == '{') {
            stack.push(el);
            continue;
        }
        if ( el == ')' || el == ']' || el == '}') {
            if (stack.empty()==true) {
                right = false;
                break;
            }
            if (stack.top() == brackets[el]) {
                stack.pop();
            }
            else {
                right = false;
            }
        }
    }
    if (stack.empty() == false) {
        right = false;
    }

    if (right) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "no" << std::endl;
    }
}