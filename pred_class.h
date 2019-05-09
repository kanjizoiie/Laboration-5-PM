/* 
 * File:   pred_class.h
 * Author: Mackan
 *
 * Created on den 14 oktober 2016, 19:54
 * 
 * Contains all of the predicates used in the lab.
 * Requires that operator> is overloaded at least, this could be implemented more generally but i think this is enough for the completion of the lab.
 */

#ifndef PRED_CLASS_H
#define PRED_CLASS_H

#include <algorithm>
#include <vector>
class pred_class {
public:
    //Looks if the input value is higher, if so it returns true, else it returns false.
    template<typename T>
    struct find_if_pred {
    public:
        find_if_pred(double val): compValue(val) {}
        bool operator()(T& input) { return (input > compValue); }
    private:
        double compValue;
    };
    //Adds the power to the sum
    template<typename T>
    struct myBinOp {
    public:
        double operator()(double sum, T& b) { return (sum + b.getPower()); } //getPower() should be replaced with a operator.
    };
    //Returns the power, this will be used for setting the values in the new vector.
    template<typename T>
    struct myUnOp {
    public:
        double operator()(const T& car){ return car.getPower(); } //getPower() should be replaced with a operator.
    };
    //Calculates power - mean and outputs it to the vector.
    template<typename T>
    struct newPow {
    public:
        newPow(double mean): mean (mean) { }
        double operator()(const T& a){ return a - mean; } 
    private:
        double mean;
    };
private:
    
};

#endif /* PRED_CLASS_H */

