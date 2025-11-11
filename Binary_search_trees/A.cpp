#include <iostream>
#include <string>

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

    Node<T> *findMaxNode(Node<T> *node) {
        if (node->right == nullptr) {
            return node;
        }
        return findMaxNode(node->right);
    }

    Node<T> *del(Node<T> *node, T x) {
        if (node == nullptr) {
            return nullptr;
        }
        if (x < node->data) {
            node->left = del(node->left, x);
        } else if (x > node->data) {
            node->right = del(node->right, x);
        } else {
            if (node->left == nullptr) return node->right;
            if (node->right == nullptr) return node->left;
            node->data = findMaxNode(node->left)->data;
            node->left = del(node->left, node->data);
        }
        return node;
    }

    void print_tree(Node<T> *p, int level) {
        if (p == NULL)
            return;
        print_tree(p->left, level + 1);

        for (int i = 0; i < level; i++)

            std::cout << ".";

        std::cout << p->data << std::endl;

        print_tree(p->right, level + 1);
    }
};


int main() {
    std::string command;
    int num;
    BinarySearchTree<int> bst;

    while (std::cin >> command) {
        if (command == "ADD") {
            std::cin >> num;
            if (bst.search(bst.root, num)) {
                std::cout << "ALREADY" << std::endl;
            } else {
                bst.root = bst.insert(bst.root, num);
                std::cout << "DONE" << std::endl;
            }
        } else if (command == "DELETE") {
            std::cin >> num;
            if (!bst.search(bst.root, num)) {
                std::cout << "CANNOT" << std::endl;
            } else {
                bst.root = bst.del(bst.root, num);
                std::cout << "DONE" << std::endl;
            }
        } else if (command == "SEARCH") {
            std::cin >> num;
            if (bst.search(bst.root, num)) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        } else if (command == "PRINTTREE") {
            bst.print_tree(bst.root, 0);
        }
    }
}
