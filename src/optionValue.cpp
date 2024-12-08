#include "optionValue.h"

OptionValue::OptionValue() {}

OptionValue::OptionValue(int n) : BinaryTree(n) {}

double OptionValue::calculateOptionValues(std::shared_ptr<Node> currentOption, std::shared_ptr<Node> currentStock, double r, double p_tilde, double q_tilde, std::function<double(double)> strikeFunction) {
    if (currentOption->getLeft() == nullptr && currentOption->getRight() == nullptr) {
        double newValue = strikeFunction(currentStock->getValue());
        currentOption->setValue(newValue);
        return newValue;
    }

    double temp = 
        p_tilde * calculateOptionValues(currentOption->getLeft(), currentStock->getLeft(), r, p_tilde, q_tilde, strikeFunction) 
        + q_tilde * calculateOptionValues(currentOption->getRight(), currentStock->getRight(), r, p_tilde, q_tilde, strikeFunction);
    double newValue = (1/(1+r)) * temp;
    currentOption->setValue(newValue);
    return newValue;
}
