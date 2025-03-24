export module purchasable_square;
import <iostream>;
import <string>;
import <sstream>;
import <vector>;
import square;
import player;
using namespace std;

export class PurchasableSquare : public Square {
    private:
    Player *owner;
    bool mortgaged;
    public:
    PurchasableSquare(const string &name, const int posn, int propertyValue, bool ownable
                      Player *owner, bool mortgaged);
    
    void buy(Player *p);
    void mortgage();
    void unmortgage();
    // gonna have to add a Improvable? function to make sure that there is a monopoly before improvements 
}
