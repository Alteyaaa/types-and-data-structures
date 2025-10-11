#include <iostream>
#include <vector>

bool binary_search(std::vector<int> &sequence_n, int x) {
    int l, r, m;
    l = 0;
    r = sequence_n.size()-1;
    while (l <= r) {
        m = (l+r)/2;
        if (sequence_n[m]==x) {
            return true;
        }
        if (sequence_n[m] < x) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    return false;
}

int main() {
    int N, K, num;
    std::cin >> N >> K;

    std::vector<int> sequence_n;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        sequence_n.push_back(num);
    }

    std::vector<int> sequence_k;
    for (int i = 0; i < K; i++) {
        std::cin >> num;
        sequence_k.push_back(num);
    }

    for (int el: sequence_k) {
        bool answer = binary_search(sequence_n, el);
        if (answer) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std:: endl;
        }
    }
}
// 10 5
// 1 2 3 4 5 6 7 8 9 10
// -2 0 4 9 12
