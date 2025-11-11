#include <iostream>
#include <cmath>

template<typename T>
class Node {
public:
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
class BinarySearchTree {
public:
    Node<T> *root;

    BinarySearchTree() {
        this->root = nullptr;
    }

    bool search(Node<T> *node, T key) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == key) {
            return true;
        }
        if (key < node->data) {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

    Node<T> *insert(Node<T> *node, T key) {
        if (node == nullptr) {
            return new Node<T>(key);
        }
        if (key < node->data) {
            node->left = insert(node->left, key);
        } else if (key > node->data) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    Node<T> *findMinNode(Node<T> *node, T key) {
        Node<T> *current = node;
        Node<T> *curr_min = nullptr;

        while (current != nullptr) {
            if (current->data >= key) {
                if (curr_min == nullptr || current->data < curr_min->data) {
                    curr_min = current;
                }
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return curr_min;
    }
};

const long long MOD = 1000000000;

int main() {
    BinarySearchTree<long long> bst;

    int n;
    std::cin >> n;

    char command;
    long long num;

    bool isNext = false;

    long long answer = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> command >> num;
        switch (command) {
            case '+':
                if (isNext) {
                    bst.root = bst.insert(bst.root, (num + answer)%MOD);
                    isNext = false;
                } else {
                    bst.root = bst.insert(bst.root, num);
                    isNext = false;
                }
                break;
            case '?':
                Node<long long> *minNode = bst.findMinNode(bst.root, num);
                if (minNode == nullptr) {
                    std::cout << -1 << std::endl;
                } else {
                    answer = minNode->data;
                    std::cout << answer << std::endl;
                }
                isNext = true;
                break;
        }
    }
}
