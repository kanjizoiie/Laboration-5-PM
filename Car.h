/* 
 * File:   Car.h
 * Author: Mackan
 *
 * Created on den 6 oktober 2016, 13:03
 * 
 * Car class with operator overloads.
 */

#ifndef CAR_H
#define CAR_H

#include <string>
#include <cstdlib>
#include <iostream>

class Car {
public:
    Car();
    Car(std::string name, double power);
    Car(const Car& orig);
    bool operator==(const Car& rhs);
    bool operator==(const std::string& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Car& dt);
    bool operator>(const double& rhs);
    double getPower() const;
    std::string getName() const;
    virtual ~Car();
private:
    std::string name;
    double power;
};
#endif