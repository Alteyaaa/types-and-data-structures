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

    void order_up(Node<T> *node) {
        if (node == nullptr) {
            return;
        }
        order_up(node->left);
        if (node->right == nullptr && node->left == nullptr) {
            std::cout << node->data << std::endl;
        }
        order_up(node->right);
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
    bst.order_up(bst.root);
}