#include "stockPriceMovement.h"
#include <iostream>

StockPriceMovement::StockPriceMovement(int n, double S_0, double u, double d)
    : S_0(S_0), u(u), d(d), BinaryTree() {
        this->setN(n);
        std::shared_ptr<Node> head = buildStockPriveMovement(n, S_0);
        this->setHead(head);
    } 

std::shared_ptr<Node> StockPriceMovement::buildStockPriveMovement(int n, double value) {
    std::shared_ptr<Node> current = std::make_shared<Node>(value);
    if (n == 0){
        std::cout << "Test" << "\n";
        return current;
    }

    std::shared_ptr<Node> left = buildStockPriveMovement(n-1, value * d);
    current->setLeft(left);

    std::shared_ptr<Node> right = buildStockPriveMovement(n-1, value * u);
    current->setRight(right);

    return current;
}