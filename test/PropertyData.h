#ifndef PROPERTYDATA_H
#define PROPERTYDATA_H

#include <string>
#include <vector>
#include <map>
using namespace std;

struct PropertyData {
    string monopolyblockID;
    bool improvable;
    bool ownable;
    int posn;
    int purchase_cost;
    int improvement_cost;
    vector<int> rentTable;

    // Returns a reference to a static map containing the property data.
    static const map<string, PropertyData>& getAcademicData();
    
    // Look up a property's data by its name.
    static const PropertyData* lookup(const string &name);

    // Find a property's data by an index (order defined by the map).
    static const PropertyData* find_idx(int idx);
};

#endif // PROPERTYDATA_H
