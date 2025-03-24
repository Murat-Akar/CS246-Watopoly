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
