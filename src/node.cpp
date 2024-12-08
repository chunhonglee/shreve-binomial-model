#include "node.h"

Node::Node() {}

Node::Node(double value): value(value) {}

double Node::getValue() {
    return this->value;
}

std::shared_ptr<Node> Node::getLeft() {
    return this->left;
}

std::shared_ptr<Node> Node::getRight() {
    return this->right;
}

void Node::setValue(double value) {
    this->value = value;
}

void Node::setLeft(std::shared_ptr<Node>& left){
    this->left = left;
}

void Node::setRight(std::shared_ptr<Node>& right){
    this->right = right;
}