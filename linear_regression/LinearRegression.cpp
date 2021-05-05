//
// Created by Damiano Franzò on 05/05/21.
//

#include "LinearRegression.h"

void LinearRegression::fit(const Data &data){
    const std::vector<double> &x = data.get_x();
    const std::vector<double> &y = data.get_y();
    size_t data_size = x.size();

    double x_sum = std::accumulate(x.begin(), x.end(), 0.0);
    double x_mean = x_sum / (double) data_size;

    double y_sum = std::accumulate(y.begin(), y.end(), 0.0);
    double y_mean = y_sum / (double) data_size;

    double m_num = 0., m_div = 0.;
    for(size_t i = 0; i < data_size; i++){
        m_num += (x[i] - x_mean) * (y[i] - y_mean);
        m_div += (x[i] - x_mean) * (x[i] - x_mean);
    }
    m = m_num / m_div;
    b = y_mean - m * x_mean;
    check_fit = true;
}

double LinearRegression::predict(double x) {
    if(!check_fit)
        throw std::invalid_argument("The model is not fit yet");
    return m * x + b;
}

std::vector<double> LinearRegression::predict(std::vector<double> x) {
    if (!check_fit)
        throw std::invalid_argument("The model is not fit yet");

    std::vector<double> y;
    y.reserve(x.size());
    for(const double& xi : x){
        y.push_back(m * xi + b);
    }
    return y;
}
