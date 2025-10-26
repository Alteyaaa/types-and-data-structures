#include <iostream>
#include <vector>
#include <algorithm>

int Binary_search_with_count(std::vector<int> &seq, int x) {
    int l, r, m;
    l = -1;
    r = seq.size();
    while ((r-l)> 1) {
        m = (l+r)/2;
        if (seq[m] < x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    int left = l;

    l = -1;
    r = seq.size();
    while ((r-l)> 1) {
        m = (l+r)/2;
        if (seq[m] <= x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    int right = r;
    return right - left-1;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> sequence(N);
    for (int i = 0; i < N; i++) {
        std::cin >> sequence[i];
    }

   std::sort(sequence.begin(), sequence.end());

    int K;
    std::cin >> K;
    std::vector<int> nums(K);
    for (int i = 0; i < K; i++) {
        std::cin >> nums[i];
    }

    for (int num:nums) {
        std::cout << Binary_search_with_count(sequence, num) << " ";
    }

}