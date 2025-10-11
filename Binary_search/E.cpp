#include <iostream>
#include <vector>

bool good(std::vector<int> boxes, int k, int r) {
    int last_box, cows_count;
    last_box = boxes[0];
    cows_count = 1;
    for (int box: boxes) {
        if (box - last_box >=r) {
            last_box = box;
            cows_count++;
        }
    }
    return cows_count >= k;

}

int main() {
    int n, k, num;
    std::vector<int> boxes;

    std::cin >> n >> k;
    for (int i=0; i < n;i++) {
        std::cin >> num;
        boxes.push_back(num);
    }

    int l, r, m;
    l = 0;
    r = boxes.back() - boxes[0] + 1;
    while ((r-l)>1) {
        m = (l+r)/2;
        if (good(boxes, k, m)) {
            l = m;
        }
        else {
            r = m;
        }
    }
    std::cout << l;
}

// 6 3
// 2 5 7 11 15 20