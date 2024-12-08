#include "binaryTree.h"

std::shared_ptr<Node> BinaryTree::buildTree(int n){
    std::shared_ptr<Node> current = std::make_shared<Node>();
    if (n == 0){
        return current;
    }

    std::shared_ptr<Node> left = buildTree(n-1);
    current->setLeft(left);

    std::shared_ptr<Node> right = buildTree(n-1);
    current->setRight(right);

    return current;
}

BinaryTree::BinaryTree() {}

BinaryTree::BinaryTree(int n) : n(n) {
    this->head = buildTree(n);
}

int BinaryTree::getHeight() {
    return this->n;
}

std::shared_ptr<Node> BinaryTree::getHead() {
    return this->head;
}

void BinaryTree::setHead(std::shared_ptr<Node>& head){
    this->head = head;
}

void BinaryTree::setN(int n){
    this->n = n;
}
