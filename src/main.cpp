#include <iostream>
#include "StockPriceMovement.h"
#include "node.h"
#include <string>
#include "optionValue.h"
#include "europeanOption.h"
#include "americanOption.h"

void printBT(const std::string& prefix, std::shared_ptr<Node> node, bool isLeft) {
    if (node != nullptr){
        std::cout << prefix;

        std::cout << (isLeft ? "|-\\" : "\\-\\" );

        // print the value of the node
        std::cout << node->getValue() << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->getRight(), true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->getLeft(), false);
    }
}

double europeanCallOption(double value){
    double k = 4;
    return std::max(value - k, 0.0);
}

double americanPutOption(double value){
    double k = 4;
    return std::max(k - value, 0.0);
}

int main() {

    AmericanOptionBuilder OptionBuilder = AmericanOptionBuilder();
    AmericanOption option = OptionBuilder
        .setN(3)
        .setU(2)
        .setD(0.5)
        .setS_0(4)
        .setR(0.25)
        .setStrikeFunction(americanPutOption)
        .build();

    StockPriceMovement stockPriceMovement = option.getStockPriceMovement();
    OptionValue optionValue = option.getOptionValue();

    printBT("", stockPriceMovement.getHead(), false);
    std::cout << "--------------" << "\n";
    printBT("", optionValue.getHead(), false);   
    std::cout << "--------------" << "\n";
    std::cout << option.getStrikeFunction()(8) << "\n";
    std::cout << option.getP_Tilde() << "\n";
    std::cout << option.getQ_Tilde() << "\n";
    std::cout << "--------------" << "\n";
    option.evaluateOption();
    printBT("", optionValue.getHead(), false);   
    std::cout << option.getTimeZeroOptionValue() << "\n";

    return 0;
}

