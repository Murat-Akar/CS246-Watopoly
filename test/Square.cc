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

vector<string> Square::print_square(const vector<Player*>& players) const {
    vector<string> output;
    ostringstream oss;
    // Lookup property data using the square's name.
    const PropertyData* data = PropertyData::lookup(name);
    
    // Line 1: if property is improvable, mark it with an I; otherwise blank.
    if (data && data->improvable) {
        string improvablePart = "";
        int improvements = 0;

        // If this is a PurchasableSquare, get the improvement levels
        if (auto purchasable = dynamic_cast<const PurchasableSquare*>(this)) {
            improvements = purchasable->getImprovementLevels();
        }

        // Generate the "I" marks based on improvements
        for (int i = 0; i < improvements; ++i) {
            improvablePart += "I";
        }

        // Ensure the box is always 7 characters wide
        oss << "| " << left << setw(5) << improvablePart << " |";
    } else {
        oss << "|       |";
    }
    output.push_back(oss.str());
    oss.str(""); 
    oss.clear();

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

    // Line 4: Player initials based on position
    oss << "|";  // start with the left border
    string initials = "";
    for (auto p : players) {
        if (p->getPosn() == posn) {
            initials += p->getPiece();  // Concatenate player's piece (initial) if on the square
        }
    }

    // If there are players on the square, we only show up to 6 initials
    if (!initials.empty()) {
        // Ensure the initials string doesn't exceed 6 characters
        initials = initials.substr(0, 6);

        // Fill the remaining space with a blank if less than 6 initials
        oss << left << setw(6) << initials;  // Ensure the initials take up 6 spaces
        oss << " |";  // Right border
    } else {
        oss << "       |";  // No player on this square
    }

    output.push_back(oss.str());
    
    // Line 5: simple placeholder
    output.push_back("|_______|");
    
    return output;
}
