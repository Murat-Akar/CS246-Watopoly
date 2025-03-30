#include "PropertyData.h"

const map<string, PropertyData>& PropertyData::getAcademicData() {
    static const map<string, PropertyData> data = {
        { "COLLECT OSAP",  { "NONE", false,0, 0, 0, {} } },
        { "AL",  { "Arts1", true,1, 40, 50, { 2, 10, 30, 90, 160, 250 } } },
        { "SLC", { "NONE", false,2, 0, 0, {} } },
        { "ML",  { "Arts1", true,3, 60, 50, { 4, 20, 60, 180, 320, 450 } } },
        { "TUITION", { "NONE", false,4, 0, 0, {} } },
        { "MKV", { "NONE", false,5, 200, 0, {} } },
        { "ECH", { "Arts2", true,6, 100, 50, { 6, 30, 90, 270, 400, 550 } } },
        { "NEEDLES HALL", { "NONE", false,7, 0, 0, {} } },
        { "PAS", { "Arts2", true,8, 100, 50, { 6, 30, 90, 270, 400, 550 } } },
        { "HH",  { "Arts2", true,9, 120, 50, { 8, 40, 100, 300, 450, 600 } } },
        { "DC TIMS LINE", { "NONE", false,10, 0, 0, {} } },
        { "RCH", { "Eng", true,11, 140, 100, { 10, 50, 150, 450, 625, 750 } } },
        { "PAC", { "NONE", false,12, 150, 0, {} } },
        { "DWE", { "Eng", true,13, 140, 100, { 10, 50, 150, 450, 625, 750 } } },
        { "CPH", { "Eng", true,14, 150, 100, { 12, 60, 180, 500, 700, 900 } } },
        { "UWP", { "NONE", false,15, 200, 0, {} } },
        { "LHI", { "Health", true,16, 180, 100, { 14, 70, 200, 550, 750, 950 } } },
        { "SLC", { "NONE", false,17, 0, 0, {} } },
        { "BMH", { "Health", true,18, 180, 100, { 14, 70, 200, 550, 750, 950 } } },
        { "OPT", { "Health", true,19, 200, 100, { 16, 80, 220, 600, 800, 1000 } } },
        { "GOOSE NESTING", { "NONE", false,20, 0, 0, {} } },
        { "EV1", { "Env", true,21, 220, 150, { 18, 90, 250, 700, 875, 1050 } } },
        { "NEEDLES HALL", { "NONE", false,22, 0, 0, {} } },
        { "EV2", { "Env", true,23, 220, 150, { 18, 90, 250, 700, 875, 1050 } } },
        { "EV3", { "Env", true,24, 220, 150, { 20, 100, 300, 750, 925, 1100 } } },
        { "V1", { "NONE", false,25, 200, 0, {} } },
        { "PHYS", { "Sci1", true,26, 120, 150, { 22, 110, 330, 800, 975, 1150 } } },
        { "B1",  { "Sci1", true,27, 100, 150, { 22, 110, 330, 800, 975, 1150 } } },
        { "CIF", { "NONE", false,28, 150, 0, {} } },
        { "B2",  { "Sci1", true,29, 100, 150, { 24, 120, 360, 850, 1025, 1200 } } },
        { "GO TO TIMS", { "NONE",false,30, 0, 0, {} } },
        { "EIT", { "Sci2", true,31, 300, 200, { 26, 130, 390, 900, 1100, 1275 } } },
        { "ESC", { "Sci2", true,32, 300, 200, { 26, 130, 390, 900, 1100, 1275 } } },
        { "SLC", { "NONE", false,33, 0, 0, {} } },
        { "C2",  { "Sci2", true,34, 320, 200, { 28, 150, 450, 1000, 1200, 1400 } } },
        { "REV", { "NONE", false,35, 200, 0, {} } },
        { "NEEDLES HALL", { "NONE",false,36, 0, 0, {} } },
        { "MC",  { "Math", true,37, 350, 200, { 35, 175, 500, 1100, 1300, 1500 } } },
        { "COOP FEE", { "NONE",false,38, 0, 0, {} } },
        { "DC",  { "Math", true, 39, 400, 200, { 50, 200, 600, 1400, 1700, 2000 } } }
    };
    return data;
}

const PropertyData* PropertyData::lookup(const string &name) {
    const auto &db = getAcademicData();
    auto it = db.find(name);
    if(it != db.end())
        return &it->second;
    return nullptr;
}

const PropertyData* PropertyData::find_idx(int idx) {
    const auto &db = getAcademicData();
    if(idx < 0 || idx >= 40)
        return nullptr;
    int i = 0;
    for(auto it = db.begin(); it != db.end(); ++it, ++i)
        if(i == idx)
            return &it->second;
    return nullptr;
}
