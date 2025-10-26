#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> heap;

    void shiftUp(int idx) {
        int p = (idx - 1) / 2;
        while (heap[idx] < heap[p]) {
            std::swap(heap[idx], heap[p]);
            idx = p;
            p = (idx - 1) / 2;
        }
    }

    void shiftDown(int idx) {
        while ((idx * 2 + 1) < heap.size()) {
            int left = idx * 2 + 1;
            int right = idx * 2 + 2;
            if (right == heap.size()) {
                right = left;
            }
            int m = heap[left] < heap[right] ? left : right;
            if (heap[m] < heap[idx]) {
                std::swap(heap[idx], heap[m]);
            }
            idx = m;
        }
    }

public:
    void Insert(int num) {
        heap.push_back(num);
        shiftUp(heap.size() - 1);
    }

    int getMin() {
        int removed = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        shiftDown(0);
        return removed;
    }
};

int main() {
    Heap heap;

    int N, num;
    std::cin >> N;

    std::vector<int> sequence;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        sequence.push_back(num);
    }

    for (int i = 0; i < N; i++) {
        heap.Insert(sequence[i]);
    }

    std::vector<int> result;
    for (int i = 0; i < N; i++) {
        int min = heap.getMin();
        result.push_back(min);
        std::cout << result[i] << " ";
    }
}
