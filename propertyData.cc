export module propertyData;
import <string>;
import <vector>;
using namespace std;
export struct PropertyData {
    string monopolyblockID;
    int purchase_cost;
    int improvement_cost;
    vector<int> rentTable;
    export static const map<string, PropertyData>& getAcademicData();
    export static const PropertyData* lookup(const string &name);
};

