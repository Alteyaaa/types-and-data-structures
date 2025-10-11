#include <iostream>
#include <vector>

int approximate_binary_search(std::vector<int> &sequence, int x) {
    int l, r, m;
    l = -1;
    r = sequence.size();
    while ((r-l)>1) {
        m = (l+r)/2;
        if (sequence[m] < x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    if (l == -1) {
        return sequence[r];
    }
    if (abs(sequence[l]-x) <= abs(sequence[r]-x)) {
        return sequence[l];
    }
    return sequence[r];
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
        int answer = approximate_binary_search(sequence_n, el);
        std::cout << answer << std::endl;
    }
}

// 5 5
// 1 3 5 7 9
// 2 4 8 1 6