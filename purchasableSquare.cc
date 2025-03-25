export module purchasable_square;
import <iostream>;
import <string>;
import <sstream>;
import <vector>;
import square;
import player;
import propertyData;
using namespace std;

export class PurchasableSquare : public Square {
    private:
    Player *owner;
    bool mortgaged;
    string monopolyblockId;
    int improvementLevels;
    public:
    PurchasableSquare(const string &name, int posn, int propertyValue, bool ownable,
        const string &monopolyblockId, int improvementLevels,
        Player *owner = nullptr, bool mortgaged = false);
    
    void buy(Player *p);
    bool isMonopoly(Player *p);
    void mortgage();
    void unmortgage();
    bool landOn(Player *p) override;
    // gonna have to add a Improvable? function to make sure that there is a monopoly before improvements 
}
