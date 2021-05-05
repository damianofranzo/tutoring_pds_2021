//
// Created by Damiano Franzò on 05/05/21.
//

#ifndef TUTORING05052021_DATA_H
#define TUTORING05052021_DATA_H
#include <vector>

class Data {
    std::vector<double> x, y;
public:
    Data(const std::vector<double> &_x, const std::vector<double> &_y);
    const std::vector<double>& get_x() const;
    const std::vector<double>& get_y() const;
};


#endif //TUTORING05052021_DATA_H
