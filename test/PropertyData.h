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

    static const map<string, PropertyData>& getAcademicData();
    static const PropertyData* lookup(const string &name);
    static const PropertyData* find_idx(int idx);
};

#endif
