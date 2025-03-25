module purchasable_square;
import <iostream>;
import <string>;
import <sstream>;
import <vector>;
import square;
import player;
import propertyData;

using namespace std;

PurchasableSquare::PurchasableSquare(const string &name, const int posn, int propertyValue, 
    bool ownable, Player *owner, bool mortgaged) : Square(name, posn, propertyValue, ownable),
    owner{nullptr}, mortgaged{false} {}

void PurchasableSquare::buy(Player *p) {
    if (owner == nullptr && p->getMoney() >= propertyValue) {
        p->pay(propertyValue);
        owner = p;
        p->buildingsOwned.emplace_back(this);
        cout << p->getName() << " purchased " << getName() << " for $" << propertyValue << endl;
    }
    else {
        cout << "Insufficient Funds For Purchase" << endl;
    }
}

bool PurchasableSquare::landOn(Player *p) {
    if (owner == nullptr) {
        cout << p->getName() << " landed on " << getName() 
             << ". This property is unowned and costs $" << propertyValue << "." << endl;
        return true; // if true ask player if they want to buy
    }
    else if (owner != p) {
        if (mortgaged) {
            cout << p->getName() << " landed on " << getName() 
            << ", but it is mortgaged. No rent is due." << endl;
        }
        else {
            // if not mortgaged, 
        }
    }
}

void PurchasableSquare::mortgage() {} //not sure what to add
void PurchasableSqaure::unmortgage() {} //not sure what to add here
