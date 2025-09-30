#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::cin.ignore();

    std::string sequence;
    std::getline(std::cin, sequence);
    std::istringstream iss(sequence);
    int num;

    std::vector<int> seq;

    while (iss >> num && seq.size() < N) {
        seq.push_back(num);
    }

    std::vector<int> result;

    std::deque<int> idx;

    for (int i = 0; i < N; i++) {
        if (idx.empty() == false && idx.front() <= i-K) {
            idx.pop_front();
        }
        while (idx.empty() == false && seq[idx.back()] >= seq[i]) {
            idx.pop_back();
        }
        idx.push_back(i);

        if (i >= K-1) {
            result.push_back(seq[idx.front()]);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << std::endl;
    }
}
