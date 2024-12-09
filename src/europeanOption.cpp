#include "europeanOption.h"

EuropeanOption::EuropeanOption(int n, double u, double d, double S_0, double r, std::function<double(double)> strikeFunction) 
    : n(n), u(u), d(d), S_0(S_0), r(r), strikeFunction(strikeFunction) {
        this->p_tilde = (1 + r - d) / (u - d);
        this->q_tilde = (u - 1 - r) / (u - d);
        this->stockPriceMovement = StockPriceMovement(n, S_0, u, d);
        this->optionValue = OptionValue(n);
    }

int EuropeanOption::getN() {
    return this->n;
}

double EuropeanOption::getU() {
    return this->u;
}

double EuropeanOption::getS_0() {
    return this->S_0;
}

double EuropeanOption::getR() {
    return this->r;
}

std::function<double(double)> EuropeanOption::getStrikeFunction() {
    return this->strikeFunction;
}

double EuropeanOption::getP_Tilde() {
    return this->p_tilde;
}

double EuropeanOption::getQ_Tilde() {
    return this->q_tilde;
}

StockPriceMovement EuropeanOption::getStockPriceMovement() {
    return this->stockPriceMovement;
}

OptionValue EuropeanOption::getOptionValue() {
    return this->optionValue;
}

void EuropeanOption::evaluateOption() {
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

double EuropeanOption::getTimeZeroOptionValue() {
    return this->optionValue.getHead()->getValue();
}

double EuropeanOption::calculateOptionValues(std::shared_ptr<Node> currentOption, std::shared_ptr<Node> currentStock, double r, double p_tilde, double q_tilde, std::function<double(double)> strikeFunction) {
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

EuropeanOptionBuilder::EuropeanOptionBuilder() {}

EuropeanOptionBuilder EuropeanOptionBuilder::setN(int n) {
    this->n = n;
    return *this;
}

EuropeanOptionBuilder EuropeanOptionBuilder::setU(double u) {
    this->u = u;
    return *this;
}

EuropeanOptionBuilder EuropeanOptionBuilder::setD(double d) {
    this->d = d;
    return *this;
}

EuropeanOptionBuilder EuropeanOptionBuilder::setS_0(double S_0) {
    this->S_0 = S_0;
    return *this;
}

EuropeanOptionBuilder EuropeanOptionBuilder::setR(double r) {
    this->r = r;
    return *this;
}

EuropeanOptionBuilder EuropeanOptionBuilder::setStrikeFunction(std::function<double(double)> strikeFunction) {
    this->strikeFunction = strikeFunction;
    return *this;
}

EuropeanOption EuropeanOptionBuilder::build() {
    return EuropeanOption(this->n, this->u, this->d, this->S_0, this->r, this->strikeFunction);
}