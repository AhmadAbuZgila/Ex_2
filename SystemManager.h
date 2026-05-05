#pragma once

#include <string>
#include <vector>
#include "Category.h"
#include "TestedObject.h"
using namespace std;

class SystemManager {
private:
    vector<Category> categories;
    vector<TestedObject> objects;
    
    const Category* findCategory(const string& name) const;
    
public:
    bool loadFromJson(const std::string& filename);
    
    void evaluateAllObjects() const;
};