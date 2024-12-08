#ifndef OPTIONVALUE_H
#define OPTIONVALUE_H

#include <functional>
#include "binaryTree.h"

// Class to represent the Option Value at every timepoint
class OptionValue : public BinaryTree {
    public:
        OptionValue();

        OptionValue(int n);

        double calculateOptionValues(std::shared_ptr<Node> currentOption, std::shared_ptr<Node> currentStock, double r, double p_tilde, double q_tilde, std::function<double(double)> strikeFunction);
};

#endif