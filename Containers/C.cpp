#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int main() {
    std::string sequence;
    char el;
    std::getline(std::cin, sequence);
    std::istringstream iss(sequence);
    int res;

    std::stack<int> stack;

    while (iss >> el) {
        if (isdigit(el)) {
            stack.push(el-'0'); // Для преобразования char к int по значению
        }
        else {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();

            if (el == '+') {
                res = b+a;
            }
            else if ( el == '-') {
                res = b-a;
            }
            else if ( el == '*') {
                res = b*a;
            }
            else if ( el == '/') {
                res = b/a;
            }
            stack.push(res);
        }
    }
    std::cout << stack.top() << std::endl;
}