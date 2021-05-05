#include <iostream>
/*
 * Input:
 * N
 * x1, y1
 * x2, y2
 * .....
 * xN, yN
 *
 * Create a class Data containing the training data
 * - Variables vector<double> x, y;
 * - methods getX, getY
 *
 * Create a class LinearRegression that implements the methods
 * - fit(Data &data_training)
 *   y = m x + b
 *   compute m, b
 * - predict(Data &data_testing)
 *   y = m x + b
 *   compute y
 * - predict(xi)
 *   compute yi = m xi + b
 *
 * - predict(vector<double> x)
 *   compute y = m x + b
 */

/*
 * Optional
 * Sketch a class LinearRegressionBase which has a virtual method fit() which changes for different implementation
 */
#include <vector>
#include "Data.h"
#include "LinearRegression.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    size_t n; std::cin >> n;
    std::cout << n << std::endl;
    std::vector<double> x, y;
    x.reserve(n);
    y.reserve(n);
    double tmp1, tmp2;
    for(size_t i = 0; i < n; ++i)
    {
        std::cin >> tmp1 >> tmp2;
        x.push_back(tmp1);
        y.push_back(tmp2);
    }
    Data data(x, y);
    // --- QUA ---- //
    LinearRegression lr{};
    lr.fit(data);
    // Test 1
    double x_i = 3.;
    double y_i = lr.predict(x_i);
    std::cout << "For x = " << x_i << " y = " << y_i << std::endl;

    //Test 2
    std::vector<double> x_vector{1., 2., 3.};
    std::vector<double> y_vector = lr.predict(x_vector);
    for(size_t i = 0; i < x_vector.size(); i++){
        std::cout << "For x = " << x_vector[i] << " y = " << y_vector[i] << std::endl;
    }
    return 0;
}
