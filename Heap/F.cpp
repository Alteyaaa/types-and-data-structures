#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main() {
    std::priority_queue<int> time;
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int> > boxes;

    int T, L;
    for (int i = 0; i < N; i++) {
        std::cin >> T >> L;
        boxes.push_back({T, L});
    }

    std::sort(boxes.begin(), boxes.end());

    int in, out, h = 0;

    for (std::pair<int, int> box: boxes) {
        in = box.first;
        out = box.second;

        while (!time.empty() && (-time.top()) <= in) {
            time.pop();
        }

        time.push(-(in + out));

        h = std::max(h, (int) time.size());
    }

    std::cout << h << std::endl;
}
