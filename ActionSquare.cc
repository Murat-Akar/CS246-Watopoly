export module action_square;
import <iostream>;
import <string>;
import <sstream>;
import <vector>;
import square;
import player;
import propertyData;
using namespace std;


export class ActionSquare : public Square {    
    public:
    ActionSquare(const string &name, int posn);
     
    bool landOn(Player *p) override;
    virtual void applyAction(Player *p) = 0; //Not sure if we need it to be virtual
}


