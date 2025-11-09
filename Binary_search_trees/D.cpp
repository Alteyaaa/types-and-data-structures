#include <iostream>
#include <vector>

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

    Node<T> *findSecondMaxNode(Node<T> *node) {
        Node<T> *parent = nullptr;
        Node<T> *current = node;
        while (current->right != nullptr) {
            parent = current;
            current = current->right;
        }
        if (current->left != nullptr) {
            current = current->left;
            while (current->right != nullptr) {
                current = current->right;
            }
            return current;
        }
        return parent;
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
    std::cout << bst.findSecondMaxNode(bst.root)->data;
}
