module action_square;
import <iostream>;
import <string>;
import <sstream>;
import <vector>;
import square;
import player;
import propertyData;

using namespace std;

ActionSquare::ActionSquare(const string &name, int posn)
    : Square(name, posn, 0, false) {
}

bool ActionSquare::landOn(Player *p) {
    applyAction(p);
    return true;
}