#include <iostream>


template<typename T>
class Node {
public:
    T data;
    Node<T> *left;
    Node<T> *right;
    int clone_count;

    Node(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        clone_count = 1;
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
        else {
            node->clone_count +=1;
        }
        return node;
    }

    void order_up(Node<T> *node) {
        if (node == nullptr) {
            return;
        }
        order_up(node->left);
        std::cout << node->data << " " << node-> clone_count << std::endl;
        order_up(node->right);
    }
};


int main() {
    int num;
    BinarySearchTree<int> bst;
    std::cin >> num;
    while (num != 0) {
        if (bst.search(bst.root, num)) {

        }
        bst.root = bst.insert(bst.root, num);
        std::cin >> num;
    }
    bst.order_up(bst.root);
}
