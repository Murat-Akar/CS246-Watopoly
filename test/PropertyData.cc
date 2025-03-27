#include "PropertyData.h"

const map<string, PropertyData>& PropertyData::getAcademicData() {
    static const map<string, PropertyData> data = {
        { "COLLECT OSAP",  { "NONE", false, 0, 0, {} } },
        { "AL",  { "Arts1", true, 40, 50, { 2, 10, 30, 90, 160, 250 } } },
        { "SLC", { "NONE", false, 0, 0, {} } },
        { "ML",  { "Arts1", true, 60, 50, { 4, 20, 60, 180, 320, 450 } } },
        { "TUITION", { "NONE", false, 0, 0, {} } },
        { "MKV", { "NONE", false, 200, 0, {} } },
        { "ECH", { "Arts2", true, 100, 50, { 6, 30, 90, 270, 400, 550 } } },
        { "NEEDLES HALL", { "NONE", false, 0, 0, {} } },
        { "PAS", { "Arts2", true, 100, 50, { 6, 30, 90, 270, 400, 550 } } },
        { "HH",  { "Arts2", true, 120, 50, { 8, 40, 100, 300, 450, 600 } } },
        { "DC TIMS LINE", { "NONE", false, 0, 0, {} } },
        { "RCH", { "Eng", true, 140, 100, {10, 50, 150, 450, 625, 750} } },
        { "DWE", { "Eng", true, 140, 100, {10, 50, 150, 450, 625, 750} } },
        { "CPH", { "Eng", true, 160, 100, {12, 60, 180, 500, 700, 900} } },
        { "NEEDLES HALL 2", { "NONE", false, 0, 0, {} } },
        { "LHI", { "Health", true, 180, 100, {14, 70, 200, 550, 750, 950} } },
        { "BMH", { "Health", true, 180, 100, {14, 70, 200, 550, 750, 950} } },
        { "OPT", { "Health", true, 200, 100, {16, 80, 220, 600, 800, 1000} } },
        { "GOOSE NESTING", { "NONE", false, 0, 0, {} } },
        { "EV1", { "Env", true, 220, 150, {18, 90, 250, 700, 875, 1050} } },
        { "EV2", { "Env", true, 220, 150, {18, 90, 250, 700, 875, 1050} } },
        { "EV3", { "Env", true, 240, 150, {20, 100, 300, 750, 925, 1100} } },
        { "NEEDLES HALL 3", { "NONE", false, 0, 0, {} } },
        { "PHYS",{ "Sci1", true, 260, 150, {22, 110, 330, 800, 975, 1150} } },
        { "B1",  { "Sci1", true, 260, 150, {22, 110, 330, 800, 975, 1150} } },
        { "B2",  { "Sci1", true, 280, 150, {24, 120, 360, 850, 1025, 1200} } },
        { "GO TO TIMS", { "NONE", false, 0, 0, {} } },
        { "EIT", { "Sci2", true, 300, 200, {26, 130, 390, 900, 1100, 1275} } },
        { "ESC", { "Sci2", true, 300, 200, {26, 130, 390, 900, 1100, 1275} } },
        { "C2",  { "Sci2", true, 320, 200, {28, 150, 450, 1000, 1200, 1400} } },
        { "SLC 2", { "NONE", false, 0, 0, {} } },
        { "MC",  { "Math", true, 350, 200, {35, 175, 500, 1100, 1300, 1500} } },
        { "COOP FEE", { "NONE", false, 0, 0, {} } },
        { "DC",  { "Math", true, 400, 200, {50, 200, 600, 1400, 1700, 2000} } },
        { "SLC 3", { "NONE", false, 0, 0, {} } },
        { "UWP", { "NONE", false, 200, 0, {} } },
        { "V1", { "NONE", false, 200, 0, {} } },
        { "REV", { "NONE", false, 200, 0, {} } },
        { "CIF", { "NONE", false, 150, 0, {} } },
        { "PAC", { "NONE", false, 150, 0, {} } }
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
