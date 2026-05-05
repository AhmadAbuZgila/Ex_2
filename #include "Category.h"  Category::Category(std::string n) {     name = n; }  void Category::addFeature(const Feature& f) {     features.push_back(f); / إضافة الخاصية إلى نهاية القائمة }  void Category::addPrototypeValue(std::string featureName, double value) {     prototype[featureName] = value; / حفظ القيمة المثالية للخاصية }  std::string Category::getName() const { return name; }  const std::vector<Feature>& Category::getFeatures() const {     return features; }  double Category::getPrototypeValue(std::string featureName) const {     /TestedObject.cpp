#include "TestedObject.h"
using namespace std;


TestedObject::TestedObject(string n, string catName) {
    name = n;
    categoryName = catName;
}

void TestedObject::addFeatureValue(string featureName, double value) {
    featureValues[featureName] = value;
}

string TestedObject::getName() const { return name; }
string TestedObject::getCategoryName() const { return categoryName; }

double TestedObject::getFeatureValue(string featureName) const {
    if (featureValues.count(featureName) > 0) {
        return featureValues.at(featureName);
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