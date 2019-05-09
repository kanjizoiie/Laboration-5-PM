/*Lab 5, Marcus Johansson
 * Marcus Johansson
 * main.cpp, Created on den 14 oktober 2016, 13:45
 * This file contains alot of function calls to the STL library, these functions calls are applied to a vector with a custom class called car.
 * To make the functions do the things i want i've used predicates which can be seen in the file pred_class.h. These are templated to be generic, they are supposed to able to use on whatever class you want. 
 */
#include <numeric>
#include <algorithm>
#include <iostream>
#include "Car.h"
#include "MyPrint.h"
#include "pred_class.h"

using namespace std;

/*
 * This is thg main entrypoint of the program. It firstly adds numerous cars to the array and then it makes a vector from all of the values in the array.
 * This vector is then used in all of the generic algorithms.
 */
int main(int argc, char** argv) {
    Car cars [12];
    std::vector<Car> searchV;
    
    searchV.push_back(Car("Volvo", 130));
    searchV.push_back(Car("Volvo", 130));
    searchV.push_back(Car("Volvo", 130));
    searchV.push_back(Car("Volvo", 130));
    searchV.push_back(Car("Volvo", 130));
    
    std::vector<Car> test(cars, cars + sizeof(cars) / sizeof(*cars));
    MyPrint<Car> print;
    
    test.push_back(Car("Volvo", 130));
    test.push_back(Car("Volvo", 130));
    test.push_back(Car("Volvo", 130));
    test.push_back(Car("Volvo", 130));
    test.push_back(Car("Volvo", 130));
    
    print(test);
    
    auto f_if = std::find_if(test.begin(), test.end(), pred_class::find_if_pred<Car>(20));
    std::cout << "THE FOUND CAR WAS: " << f_if->getName() << "\n";
    
    auto a_f = std::adjacent_find(test.begin(), test.end());
    std::cout << a_f->getName() << "\n";
    
    auto eq = std::equal(test.begin(), test.end(), cars);
    std::cout << eq << "\n";
    
    auto srch = std::search(test.begin(), test.end(), searchV.begin(), searchV.end());
    std::cout << srch->getName() << " : " << srch->getPower() << "\n";
    
    double mean = std::accumulate(test.begin(), test.end(), 0.0, pred_class::myBinOp<Car>()) / test.size();
    std::cout << mean << "\n";
    
    std::vector<double> test_v2;
    test_v2.resize(test.size());
    std::transform(test.begin(), test.end(), test_v2.begin(), pred_class::myUnOp<Car>());
    
    MyPrint<double> print_v2;
    print_v2(test_v2);
    
    std::transform(test_v2.begin(), test_v2.end(), test_v2.begin(), pred_class::newPow<double>(mean));
    
    std::sort(test_v2.begin(), test_v2.end());
    print_v2(test_v2);
    
    return 0;
}

