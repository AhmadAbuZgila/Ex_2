#include <iostream>
#include "SystemManager.h"

using namespace std;

int main() {
    SystemManager sys;

    if (sys.loadFromJson("data.json")) {
        sys.evaluateAllObjects();
    } else {
        cerr << "Error: Could not open data.json." << endl;
    }

    return 0;
}