#pragma once

#include <string>
#include <map>
#include "Category.h"
using namespace std;

class TestedObject {
private:
    string name;
    string categoryName;
    map<string, double> featureValues;

public:
    TestedObject(const string& n, const string& catName);

    void addFeatureValue(const string& featureName, double value);

    string getName() const;
    string getCategoryName() const;
    double getFeatureValue(const string& featureName) const;
    
    double calculateSimilarity(const Category& category) const;
};