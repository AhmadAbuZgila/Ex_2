#include "Category.h"

using namespace std;

Category::Category(string n) {
    name = n;
}

void Category::addFeature(const Feature& f) {
    features.push_back(f);
}

void Category::addPrototypeValue(const string& featureName, double value) {
    prototype[featureName] = value;
}

string Category::getName() const {
    return name;
}

const vector<Feature>& Category::getFeatures() const {
    return features;
}

double Category::getPrototypeValue(const string& featureName) const {
    if (prototype.count(featureName) > 0) {
        return prototype.at(featureName);
    }
    return 0.0;
}