#ifndef AMERICANOPTION_H
#define AMERICANOPTION_H

#include "stockPriceMovement.h"
#include "optionValue.h"
#include "option.h"

// Class to represent a American Option
class AmericanOption : public IOption {
    private:
        int n;
        double u;
        double d;
        double S_0;
        double r;
        double p_tilde;
        double q_tilde;
        std::function<double(double)> strikeFunction;
        StockPriceMovement stockPriceMovement;
        OptionValue optionValue;
        
        double calculateOptionValues(std::shared_ptr<Node> currentOption, std::shared_ptr<Node> currentStock, double r, double p_tilde, double q_tilde, std::function<double(double)> strikeFunction);

    public:
        AmericanOption(int n, double u, double d, double S_0, double r, std::function<double(double)> strikeFunction);
        int getN();
        double getU();
        double getS_0();
        double getR();
        std::function<double(double)> getStrikeFunction();
        double getP_Tilde();
        double getQ_Tilde();
        StockPriceMovement getStockPriceMovement();
        OptionValue getOptionValue();

        void evaluateOption() override;
        double getTimeZeroOptionValue() override;
};

// Builder used to create American Options
class AmericanOptionBuilder {
    private:
        int n;
        double u;
        double d;
        double S_0;
        double r;
        std::function<double(double)> strikeFunction;

    public:
        AmericanOptionBuilder();
        AmericanOptionBuilder setN(int n);
        AmericanOptionBuilder setU(double u);
        AmericanOptionBuilder setD(double d);
        AmericanOptionBuilder setS_0(double S_0);
        AmericanOptionBuilder setR(double r);
        AmericanOptionBuilder setStrikeFunction(std::function<double(double)> strikeFunction);
        AmericanOption build();
};

#endif