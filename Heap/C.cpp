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

    std::string Extract() {
        if (heap.empty()) {
            return "CANNOT";
        }
        int removed = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        shiftDown(0);
        return std::to_string(removed);
    }

    void Clear() {
        heap.clear();
    }
};


int main() {
    Heap heapMin;
    std::string command;
    int num;
    while (std::cin >> command) {
        if (command == "ADD") {
            std::cin >> num;
            heapMin.Insert(num);
        } else if (command == "EXTRACT") {
            std::cout << heapMin.Extract() << std::endl;
        } else if (command == "CLEAR") {
            heapMin.Clear();
        }
    }
}
