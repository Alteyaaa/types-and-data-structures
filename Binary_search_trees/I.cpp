#include <iostream>


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

    int checkBalance(Node<T> *node) {
        if (node == nullptr) return 0;

        int left, right;

        left = checkBalance(node->left);
        if (left == -1) return -1; // Левое дерево не сбалансировано

        right = checkBalance(node->right);
        if (right == -1) return -1; // Правое дерево не сбалансировано

        if (abs(left - right) > 1) return -1; //Дерево не сбалансировано

        return std::max(left, right) + 1;
    }
};


int main() {
    int num;
    BinarySearchTree<int> bst;
    std::cin >> num;
    while (num != 0) {
        bst.root = bst.insert(bst.root, num);
        std::cin >> num;
    }
    if (bst.checkBalance(bst.root) == -1) {
        std::cout << "NO";
    } else {
        std::cout << "YES";
    }
}
