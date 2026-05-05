#include "Feature.h"

using namespace std;
Feature::Feature(string n, double w, bool imp) {
    name = n;
    weight = w;
    important = imp;
}

string Feature::getName() const { return name; }
double Feature::getWeight() const { return weight; }
bool Feature::isImportant() const { return important; }