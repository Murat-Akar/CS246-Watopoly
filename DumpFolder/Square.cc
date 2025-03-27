#include "Square.h"
#include <sstream>
using namespace std;

Square::Square(const string &n, int i) : name(n), index(i) {}

string Square::getName() const {
    return name;
}

int Square::getIndex() const {
    return index;
}

vector<string> Square::printBox() const {
    vector<string> box;
    // Top border
    box.push_back("+" + string(CELL_W - 2, '-') + "+");
    // Middle line: center the square's name (truncate if needed)
    ostringstream oss;
    oss << "|";
    string txt = name.substr(0, CELL_W - 2);
    int pad = (CELL_W - 2 - txt.size()) / 2;
    oss << string(pad, ' ') << txt << string(CELL_W - 2 - pad - txt.size(), ' ') << "|";
    box.push_back(oss.str());
    // Bottom border
    box.push_back("|" + string(CELL_W - 2, '_') + "|");
    return box;
}
