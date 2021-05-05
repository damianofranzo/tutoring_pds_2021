//
// Created by Damiano Franzò on 05/05/21.
//

#ifndef TUTORING05052021_LINEARREGRESSION_H
#define TUTORING05052021_LINEARREGRESSION_H
#include "Data.h"
#include <numeric>


class LinearRegression {
    double m, b;
    bool check_fit = false;
public:
    LinearRegression(double _m, double _b) : m(_m), b(_b), check_fit(true) {};
    LinearRegression() : m(-1.), b(-1.) {};
    void fit(const Data& data);
    double predict(double x);
    std::vector<double> predict(std::vector<double> y);
};


#endif //TUTORING05052021_LINEARREGRESSION_H
