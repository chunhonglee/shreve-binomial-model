#ifndef EUROPEANOPTION_H
#define EUROPEANOPTION_H

#include "stockPriceMovement.h"
#include "optionValue.h"

// Class to represent a European Option
class EuropeanOption {
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
        EuropeanOption(int n, double u, double d, double S_0, double r, std::function<double(double)> strikeFunction);
        int getN();
        double getU();
        double getS_0();
        double getR();
        std::function<double(double)> getStrikeFunction();
        double getP_Tilde();
        double getQ_Tilde();
        StockPriceMovement getStockPriceMovement();
        OptionValue getOptionValue();

        void evaluateOption();
        double getTimeZeroOptionValue();
};

// Builder used to create European Options
class EuropeanOptionBuilder {
    private:
        int n;
        double u;
        double d;
        double S_0;
        double r;
        std::function<double(double)> strikeFunction;

    public:
        EuropeanOptionBuilder();
        EuropeanOptionBuilder setN(int n);
        EuropeanOptionBuilder setU(double u);
        EuropeanOptionBuilder setD(double d);
        EuropeanOptionBuilder setS_0(double S_0);
        EuropeanOptionBuilder setR(double r);
        EuropeanOptionBuilder setStrikeFunction(std::function<double(double)> strikeFunction);
        EuropeanOption build();
};


#endif