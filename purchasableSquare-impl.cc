module purchasable_square;
import <iostream>;
import <string>;
import <sstream>;
import <vector>;
import square;
import player;
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

void PurchasableSquare::mortgage() {} //not sure what to add
void PurchasableSqaure::unmortgage() {} //not sure what to add here
