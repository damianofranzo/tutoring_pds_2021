//
// Created by Damiano Franzò on 05/05/21.
//

#include "Data.h"

Data::Data(const std::vector<double>& _x, const std::vector<double>& _y){
    x = std::vector<double>(_x);
    y = std::vector<double>(_y);
}

const std::vector<double>& Data::get_x() const{
    return x;
}
const std::vector<double>& Data::get_y() const{
    return y;
}
