#pragma once

#include <iostream>
#include <string>
using namespace std;
class Feature {
    private: 
    string name;
    double weight;
    bool important;
    public:
    Feature(string n, double w, bool i);
    string getName()const;
    double getWeight()const;
    bool isImportant()const;
}; 