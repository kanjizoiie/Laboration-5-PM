
/* 
 * File:   MyPrint.h
 * Author: Mackan
 *
 * Created on den 6 oktober 2016, 13:58
 * 
 * used for printing the different vectors.
 */

#ifndef MYPRINT_H
#define MYPRINT_H
#include "Car.h"
#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
class MyPrint {
public:
    //Prints all the values in a vector.
    void operator()(std::vector<T> data) {
        std::for_each(data.begin(), data.end(), [](T& in){ std::cout << in << "\n"; });
    }
};

#endif /* MYPRINT_H */

