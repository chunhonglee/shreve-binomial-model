#include <iostream>
#include "StockPriceMovement.h"
#include "node.h"
#include <string>
#include "optionValue.h"

void printBT(const std::string& prefix, std::shared_ptr<Node> node, bool isLeft) {
    if (node != nullptr){
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "\\--" );

        // print the value of the node
        std::cout << node->getValue() << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->getRight(), true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->getLeft(), false);
    }
}

int main() {
    StockPriceMovement tree = StockPriceMovement(3, 1, 2, 0.5);
    std::shared_ptr<Node> head = tree.getHead();

    printBT("", head, false);

    std::cout << "-----------------" << "\n";

    OptionValue option = OptionValue(3);
    std::shared_ptr<Node> headOption = option.getHead();

    printBT(", ", headOption, false);

    return 0;
}

