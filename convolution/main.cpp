#include <iostream>
#include <vector>
#include "convolution.h"
#include <stdexcept>

/*
 * Problem:
 *   Write an C++ program computing the convolution of two signals using the following defintion.
 *              M                    M
 * f * g [n] = Sum f[m] g[n - m] =  Sum f[n - m] g[m]
 *             n=0                  n=0
 *
 * N.B. The developed function will be equivalent to scipy.signal.convolve with mode='valid'
 *
 * Input file:
 *   N M
 *   f0 f1 f2 .. fN
 *   g0 g1 g2 .. fM
 *
 * Input:
 *   vector<float> f
 *   vector <float> g
 * Output:
 *   vector<float> result
 *
 * Additional notes
 *   The reference values are 69.83, 448.67, 290.42, 303.8 for signals in signal.txt
 */

using namespace std;

int main(int argc, char** argv){
    int nF, nG;
    float input_value;
    cin >> nF >> nG;
    vector<float> f, g;
    f.reserve(nF);
    g.reserve(nG);

    for(size_t i = 0; i < nF; i++){
        cin >> input_value;
        f.push_back(input_value);
    }
    for(size_t i = 0; i < nG; i++) {
        cin >> input_value;
        g.push_back(input_value);
    }
    vector<float> result;
    try{
        result = discrete_convolution(f, g);
    }
    catch (const std::invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(1);
    }

    cout << "f * g [n] = ";
    for(size_t i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
