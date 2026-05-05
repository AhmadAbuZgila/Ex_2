#include "TestedObject.h"
using namespace std;

TestedObject::TestedObject(const string& n, const string& catName) {
    name = n;
    categoryName = catName;
}

void TestedObject::addFeatureValue(const string& featureName, double value) {
    featureValues[featureName] = value;
}

string TestedObject::getName() const { return name; }
string TestedObject::getCategoryName() const { return categoryName; }

double TestedObject::getFeatureValue(const string& featureName) const {
    auto it = featureValues.find(featureName);
    if (it != featureValues.end()) {
        return it->second;
    }
    return 0.0; 
}

double TestedObject::calculateSimilarity(const Category& category) const {
    double score = 0.0;
    
    for (const Feature& f : category.getFeatures()) {
        std::string featureName = f.getName();
        double weight = f.getWeight();
        
        double objectValue = getFeatureValue(featureName);
        
        score += (objectValue * weight);
    }
    
    return score;
}