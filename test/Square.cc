#include "Square.h"
#include "PropertyData.h"
#include "PurchasableSquare.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

Square::Square(const string &name, int posn, int squareVal, bool isOwnable)
    : name(name), posn(posn), squareVal(squareVal), isOwnable(isOwnable)
{
}

Square::~Square() {}

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

vector<string> Square::print_square(const vector<Player*>& players) const {
    vector<string> output;
    ostringstream oss;
    const PropertyData* data = PropertyData::lookup(name);
    
    // Line 1: if property is improvable, mark it with an I; otherwise blank.
     if (name == "COLLECT OSAP") {
        oss << "|COLLECT|";
    } else if (name == "SLC") {
        oss << "|SLC    |";
    } else if (name == "TUITION") {
        oss << "|TUITION|";
    } else if (name == "MKV") {
        oss << "|MKV    |";
    } else if (name == "NEEDLES HALL") {
        oss << "|NEEDLES|";
    } else if (name == "DC Tims Line") {
        oss << "|DC Tims|";
    } else if (name == "PAC") {
        oss << "|PAC    |";
    } else if (name == "UWP") {
        oss << "|UWP    |";
    } else if (name == "Goose Nesting") {
        oss << "|Goose  |";
    } else if (name == "V1") {
        oss << "|V1     |";
    } else if (name == "CIF") {
        oss << "|CIF    |";
    } else if (name == "GO TO TIMS") {
        oss << "|GO TO  |";
    } else if (name == "REV") {
        oss << "|REV    |";
    } else if (name == "COOP FEE") {
        oss << "|COOP   |";
    } else if (data && data->improvable) {
        string improvablePart = "";
        int improvements = 0;

        if (auto purchasable = dynamic_cast<const PurchasableSquare*>(this)) {
            improvements = purchasable->getImprovementLevels();
        }

        for (int i = 0; i < improvements; ++i) {
            improvablePart += "I";
        }

        oss << "| " << left << setw(5) << improvablePart << " |";
    } else {
        oss << "|       |";
    }
    output.push_back(oss.str());
    oss.str(""); 
    oss.clear();

    // Line 2: display a divider or the square name.
    if (name == "COLLECT OSAP") {
        oss << "|OSAP   |";
        output.push_back(oss.str());
    } else if (name == "NEEDLES HALL") {
        oss << "|HALL   |";
        output.push_back(oss.str());
    } else if (name == "DC Tims Line") {
        oss << "|Line   |";
        output.push_back(oss.str());
    } else if (name == "Goose Nesting") {
        oss << "|Nesting|";
        output.push_back(oss.str());
    } else if (name == "GO TO TIMS") {
        oss << "|TIMS   |";
        output.push_back(oss.str());
    } else if (name == "COOP FEE") {
        oss << "|FEE    |";
        output.push_back(oss.str());
    } else if (data && data->improvable) {
        output.push_back("|-------|");
    } else {
        oss << "|       |";
        output.push_back(oss.str());
    }
    oss.str(""); 
    oss.clear();

    // Line 3: if improvable, show name; otherwise blank.
    if (data && data->improvable)
        oss << "|" << left << setw(7) << name.substr(0, 7) << "|";
    else
        oss << "|       |";
    output.push_back(oss.str());
    oss.str(""); oss.clear();

    // Line 4: Player initials based on position
    oss << "|";
    string initials = "";
    for (auto p : players) {
        if (p->getPosn() == posn) {
            initials += p->getPiece();  // Concatenate player's piece (initial) if on the square
        }
    }

    if (!initials.empty()) {
        initials = initials.substr(0, 6);

        oss << left << setw(6) << initials;
        oss << " |";
    } else {
        oss << "       |";
    }

    output.push_back(oss.str());
    
    // Line 5: simple placeholder
    output.push_back("|_______|");
    
    return output;
}
