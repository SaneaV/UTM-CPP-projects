#include "funtionality.h"

int inputNumberFor(char *message) {
    int number;
    std::cout << "Input number " << message << ": ";
    std::cin >> number;
    return number;
}

void insertRecursive(Node *&root, int key) {
    if (root == nullptr) {
        root = new Node(key);
        return;
    }

    if (key < root->data) {
        insertRecursive(root->left, key);
    } else {
        insertRecursive(root->right, key);
    }
}

void insertIterative(Node *&root, int key) {
    Node *curr = root;
    Node *parent = nullptr;

    if (root == nullptr) {
        root = new Node(key);
        return;
    }

    while (curr != nullptr) {
        parent = curr;

        if (key < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (key < parent->data) {
        parent->left = new Node(key);
    } else {
        parent->right = new Node(key);
    }
}

void searchRecursive(Node *root, int key, Node *parent) {
    if (root == nullptr) {
        std::cout << "Key not found";
        return;
    }

    if (root->data == key) {
        if (parent == nullptr) {
            std::cout << "The node with key " << key << " is root node" << "\n\n";
        } else if (key < parent->data) {
            std::cout << "The given key is the left node of the node with key " << parent->data << "\n\n";
        } else {
            std::cout << "The given key is the right node of the node with key " << parent->data << "\n\n";
        }

        return;
    }

    if (key < root->data) {
        searchRecursive(root->left, key, root);
    } else {
        searchRecursive(root->right, key, root);
    }
}

void searchIterative(Node *root, int key) {
    Node *curr = root;

    Node *parent = nullptr;

    while (curr != nullptr && curr->data != key) {
        parent = curr;

        if (key < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (curr == nullptr) {
        std::cout << "Key not found";
        return;
    }

    if (parent == nullptr) {
        std::cout << "The node with key " << key << " is root node" << "\n\n";
    } else if (key < parent->data) {
        std::cout << "The given key is the left node of the node with key " << parent->data << "\n\n";
    } else {
        std::cout << "The given key is the right node of the node with key " << parent->data << "\n\n";
    }
}