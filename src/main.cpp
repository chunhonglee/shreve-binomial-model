#include <iostream>
#include "binaryTree.h"

int main() {
    BinaryTree tree = BinaryTree(2);
    std::shared_ptr<Node> head = tree.getHead();

    std::cout << head->getValue() << "\n";
    std::cout << head->getLeft()->getValue() << "\n";
    std::cout << head->getRight()->getValue() << "\n";

    std::cout << head->getLeft()->getLeft()->getValue() << "\n";
    std::cout << head->getLeft()->getRight()->getValue() << "\n";
    return 0;
}