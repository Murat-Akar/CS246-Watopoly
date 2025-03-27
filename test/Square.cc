#include "Square.h"
#include "PropertyData.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

Square::Square(const string &name, int posn, int squareVal, bool isOwnable)
    : name(name), posn(posn), squareVal(squareVal), isOwnable(isOwnable)
{
}

Square::~Square() {
    // Nothing to do here in this base implementation.
}

const string& Square::getName() const {
    return name;
}

int Square::getRent() const {
    return squareVal;
}

int Square::getPosition() const {
    return posn;
}

bool Square::isPurchasable() const {
    return isOwnable;
}

vector<string> Square::print_square() const {
    vector<string> output;
    ostringstream oss;
    // Lookup property data using the square's name.
    const PropertyData* data = PropertyData::lookup(name);
    
    // Line 1: if property is improvable, mark it with an I; otherwise blank.
    if (data && data->improvable)
        oss << "|   I   |";
    else
        oss << "|       |";
    output.push_back(oss.str());
    oss.str(""); oss.clear();

    // Line 2: display a divider or the square name.
    if (data && data->improvable) {
        output.push_back("|-------|");
    } else {
        oss << "|" << left << setw(7) << name.substr(0, 7) << "|";
        output.push_back(oss.str());
    }
    oss.str(""); oss.clear();

    // Line 3: if improvable, show name; otherwise blank.
    if (data && data->improvable)
        oss << "|" << left << setw(7) << name.substr(0, 7) << "|";
    else
        oss << "|       |";
    output.push_back(oss.str());
    oss.str(""); oss.clear();

    // Lines 4-5: simple placeholders.
    output.push_back("|       |");
    output.push_back("|_______|");
    
    return output;
}
