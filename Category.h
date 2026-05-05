#pragma once

#include <string>
#include <vector>
#include <map>
#include "Feature.h"
using namespace std;
class Category
{
private:
  string name;
  vector<Feature> features;
  map<std::string, double> prototype;
public:
    Category(string n);

    void addFeature(const Feature& f);
    void addPrototypeValue(const string& featureName, double value);

    string getName() const;
    const vector<Feature>& getFeatures() const;
    double getPrototypeValue(const string& featureName) const;
};
