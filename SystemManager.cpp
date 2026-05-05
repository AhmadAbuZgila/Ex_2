#include "SystemManager.h"
#include "./nlohmann/json.hpp" 
#include <fstream>
#include <iostream>

using json = nlohmann::json;
using namespace std;

const Category* SystemManager::findCategory(const string& name) const {
    for (const auto& cat : categories) {
        if (cat.getName() == name) {
            return &cat;
        }
    }
    return nullptr;
}

bool SystemManager::loadFromJson(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    json j;
    file >> j;

    for (const auto& catJson : j["categories"]) {
        Category cat(catJson["name"]);

        for (const auto& featJson : catJson["features"]) {
            Feature f(featJson["name"], featJson["weight"], featJson["important"]);
            cat.addFeature(f);
        }

        for (auto& [key, val] : catJson["prototype"].items()) {
            cat.addPrototypeValue(key, val);
        }

        categories.push_back(cat);
    }

    for (const auto& objJson : j["objects"]) {
        TestedObject obj(objJson["name"], objJson["category"]);

        for (auto& [key, val] : objJson["features"].items()) {
            obj.addFeatureValue(key, val);
        }

        objects.push_back(obj);
    }

    return true;
}

void SystemManager::evaluateAllObjects() const {
    cout << "Loading data from JSON file..." << endl;
    cout << "Found " << categories.size() << " categories." << endl << endl;

    for (const auto& obj : objects) {
        const Category* cat = findCategory(obj.getCategoryName());
        if (cat == nullptr) {
            cout << "Error: Category not found for " << obj.getName() << endl;
            continue;
        }

        cout << "Testing object: " << obj.getName() << " (Category: " << cat->getName() << ")" << endl;

        double rawScore = obj.calculateSimilarity(*cat);
        double maxScore = 0.0; 

        for (const auto& f : cat->getFeatures()) {
            double protoValue = cat->getPrototypeValue(f.getName());
            maxScore += (protoValue * f.getWeight());
            
            double objVal = obj.getFeatureValue(f.getName());
            double contribution = objVal * f.getWeight();
            
            cout << "Feature: " << f.getName() 
                 << " | Value: " << objVal 
                 << " | Weight: " << f.getWeight() 
                 << " | Contribution: " << contribution << endl;
        }

        cout << "Weighted score: " << rawScore << endl;

        double finalScore = 1.0;
        if (maxScore > 0) {
            finalScore = 1.0 + 6.0 * (rawScore / maxScore); 
        }
        
        if (finalScore > 7.0) finalScore = 7.0;

        cout << "Final score (1-7 scale): " << finalScore << endl;
        
        cout << "Conclusion: ";
        if (finalScore >= 6.0) {
            cout << "The object " << obj.getName() << " is very similar to the prototype." << endl;
        } else if (finalScore >= 4.0) {
            cout << "The object " << obj.getName() << " is somewhat similar to the prototype." << endl;
        } else {
            cout << "The object " << obj.getName() << " is not similar to the prototype." << endl;
        }
        
        cout << "-----------------------------------" << endl;
    }
}