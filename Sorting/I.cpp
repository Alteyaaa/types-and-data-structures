#include <iostream>
#include <string>
#include <unordered_map>

void isAnagram(std::string &first_word, std::string &second_word) {
    std::unordered_map<char, int> first_symb;
    std::unordered_map<char, int> second_symb;
    for (char symb1: first_word) {
        first_symb[symb1]++;
    }
    for (char symb2: second_word) {
        second_symb[symb2]++;
    }

    if (first_symb == second_symb) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}

int main() {
    std::string first_word, second_word;
    std::cin >> first_word;
    std::cin >> second_word;

    isAnagram(first_word, second_word);
}
