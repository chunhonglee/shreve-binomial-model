#include <iostream>
#include "StockPriceMovement.h"

int main() {
    StockPriceMovement tree = StockPriceMovement(2, 1, 2, 0.5);
    std::shared_ptr<Node> head = tree.getHead();

    std::cout << head->getValue() << "\n";
    std::cout << head->getLeft()->getValue() << "\n";
    std::cout << head->getRight()->getValue() << "\n";

    std::cout << head->getLeft()->getLeft()->getValue() << "\n";
    std::cout << head->getLeft()->getRight()->getValue() << "\n";
    return 0;
}