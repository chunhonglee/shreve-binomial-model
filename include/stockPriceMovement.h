#ifndef STOCKPRICEMOVEMENT_H
#define STOCKPRICEMOVEMENT_H

#include "binaryTree.h"

// Class to represent the Stock Price Movement
class StockPriceMovement : public BinaryTree {
    private:
        double u;
        double d;
        double S_0;

        std::shared_ptr<Node> buildStockPriveMovement(int n, double value);

    public:
        StockPriceMovement();

        StockPriceMovement(int n, double S_0, double u, double d);
};

#endif