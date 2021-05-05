#include "convolution.h"


using namespace std;

vector<float> discrete_convolution(vector<float> &f, vector<float> &g){
    if(f.size() < g.size()){
        throw std::invalid_argument( "The kernel size should be smaller than than the signal size!" );
    }
    size_t size_signal_f = f.size();
    size_t size_signal_g = g.size();

    vector<float> h;
    //Wrong
    //vector<float> results (signal.size() - kernel.size() + 1, 0.0f);
    //Correct
    h.reserve(size_signal_f - size_signal_g + 1);

    for(size_t i = 0; i <= size_signal_f - size_signal_g; i++){
        float result_val = 0.0;
        for(size_t j = 0; j < size_signal_g; j++){
            result_val  += f[i + j] * g[size_signal_g - j - 1];
        }
	//Correct
        h.push_back(result_val);
    	//Wrong 
        //h[i] = results_value;
    }
    return h;
}
