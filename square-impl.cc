module square;
import <iostream>;
import <string>;
import <sstream>;
import <vector>;
using namespace std;

Square::Square(const string &name, const int posn, int squareVal, bool isOwnable){}

virtual ~Square() = default;

virtual bool landOn (Player *p) = 0;

string Square::getName() {return name;}
int Square::getPosition(){return position;}
int Square::getRent() {return squareVal;}
bool Square::isPurchasable(){return isOwnable;}

vector<string> Square::print_square() const {
    vector<string> output;
    ostringstream line;

    const PropertyData* data = PropertyData::lookup(name);

    // Line 1: Improvement marker if improvable (I)
    if (data && data->improvable) {
        line << "|   I   |";
    } else {
        line << "|       |";
    }
    output.emplace_back(line.str());
    line.str(""); line.clear();

    // Line 2: Divider or name
    if (data && data->improvable) {
        output.emplace_back("|-------|");
    } else {
        line << "|" << left << setw(7) << name.substr(0, 7) << "|";
        output.emplace_back(line.str());
    }
    line.str(""); line.clear();

    // Line 3: Name for improvable, blank otherwise
    if (data && data->improvable) {
        line << "|" << left << setw(7) << name.substr(0, 7) << "|";
    } else {
        line << "|       |";
    }
    output.emplace_back(line.str());
    line.str(""); line.clear();

    // Line 4–5: Player tokens or empty (can be overridden or injected later)
    output.emplace_back("|       |");
    output.emplace_back("|_______|");

    return output;
}
