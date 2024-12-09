#ifndef OPTION_H
#define OPTION_H

// An interface to represent an Option
class IOption {
    public:
        virtual void evaluateOption() = 0;

        virtual double getTimeZeroOptionValue() = 0;
};

#endif