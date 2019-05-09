/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.cpp
 * Author: Mackan
 * 
 * Created on den 6 oktober 2016, 13:03
 */


#include "Car.h"

Car::Car(): name("Generic car"), power(std::rand() % 200) {}

Car::Car(std::string name, double power): name(name), power(power) {}

Car::Car(const Car& orig): name(orig.name), power(orig.power) {}

bool Car::operator==(const Car& rhs) {
    return (this->name == rhs.name && this->power == rhs.power);
}
bool Car::operator ==(const std::string& rhs) {
    return (this->name == rhs);
}

bool Car::operator>(const double& rhs) {
    return this->power > rhs;
}

std::string Car::getName() const {
    return name;
}

double Car::getPower() const {
    return power;
}
Car::~Car() {}

std::ostream& operator<<(std::ostream& os, const Car& in)
{
    os << in.getName() << " : " << in.getPower();
    return os;
}