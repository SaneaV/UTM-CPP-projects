#include <iostream>
#include <iomanip>
#include <fstream>

class Node {

    Node() {}

public:
    Node(int data) : data(data) {}

    int data;
    Node *left = nullptr;
    Node *right = nullptr;
};

void insertRecursive(Node *&root, int key);

void insertIterative(Node *&root, int key);

int inputNumberFor(char *message);

void searchRecursive(Node *root, int key, Node *parent);

void searchIterative(Node *root, int key);