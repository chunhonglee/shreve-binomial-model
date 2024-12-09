#include "americanOption.h"

AmericanOption::AmericanOption(int n, double u, double d, double S_0, double r, std::function<double(double)> strikeFunction) 
    : n(n), u(u), d(d), S_0(S_0), r(r), strikeFunction(strikeFunction) {
        this->p_tilde = (1 + r - d) / (u - d);
        this->q_tilde = (u - 1 - r) / (u - d);
        this->stockPriceMovement = StockPriceMovement(n, S_0, u, d);
        this->optionValue = OptionValue(n);
    }

int AmericanOption::getN() {
    return this->n;
}

double AmericanOption::getU() {
    return this->u;
}

double AmericanOption::getS_0() {
    return this->S_0;
}

double AmericanOption::getR() {
    return this->r;
}

std::function<double(double)> AmericanOption::getStrikeFunction() {
    return this->strikeFunction;
}

double AmericanOption::getP_Tilde() {
    return this->p_tilde;
}

double AmericanOption::getQ_Tilde() {
    return this->q_tilde;
}

StockPriceMovement AmericanOption::getStockPriceMovement() {
    return this->stockPriceMovement;
}

OptionValue AmericanOption::getOptionValue() {
    return this->optionValue;
}

void AmericanOption::evaluateOption() {
    calculateOptionValues(
        this->optionValue.getHead(),
        this->stockPriceMovement.getHead(),
        this->r,
        this->p_tilde,
        this->q_tilde,
        this->strikeFunction
    );
    return;
}

double AmericanOption::getTimeZeroOptionValue() {
    return this->optionValue.getHead()->getValue();
}

double AmericanOption::calculateOptionValues(std::shared_ptr<Node> currentOption, std::shared_ptr<Node> currentStock, double r, double p_tilde, double q_tilde, std::function<double(double)> strikeFunction) {
    if (currentOption->getLeft() == nullptr && currentOption->getRight() == nullptr) {
        double newValue = strikeFunction(currentStock->getValue());
        currentOption->setValue(newValue);
        return newValue;
    }

    double temp = 
        p_tilde * calculateOptionValues(currentOption->getLeft(), currentStock->getLeft(), r, p_tilde, q_tilde, strikeFunction) 
        + q_tilde * calculateOptionValues(currentOption->getRight(), currentStock->getRight(), r, p_tilde, q_tilde, strikeFunction);
    double newValue = std::max(strikeFunction(currentStock->getValue()),(1/(1+r)) * temp);
    currentOption->setValue(newValue);
    return newValue;
}

AmericanOptionBuilder::AmericanOptionBuilder() {}

AmericanOptionBuilder AmericanOptionBuilder::setN(int n) {
    this->n = n;
    return *this;
}

AmericanOptionBuilder AmericanOptionBuilder::setU(double u) {
    this->u = u;
    return *this;
}

AmericanOptionBuilder AmericanOptionBuilder::setD(double d) {
    this->d = d;
    return *this;
}

AmericanOptionBuilder AmericanOptionBuilder::setS_0(double S_0) {
    this->S_0 = S_0;
    return *this;
}

AmericanOptionBuilder AmericanOptionBuilder::setR(double r) {
    this->r = r;
    return *this;
}

AmericanOptionBuilder AmericanOptionBuilder::setStrikeFunction(std::function<double(double)> strikeFunction) {
    this->strikeFunction = strikeFunction;
    return *this;
}

AmericanOption AmericanOptionBuilder::build() {
    return AmericanOption(this->n, this->u, this->d, this->S_0, this->r, this->strikeFunction);
}