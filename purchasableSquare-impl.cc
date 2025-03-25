module purchasable_square;
import <iostream>;
import <string>;
import <sstream>;
import <vector>;
import square;
import player;
import propertyData;

using namespace std;

PurchasableSquare::PurchasableSquare(const string &name, int posn, int propertyValue, bool ownable,
    const string &monopolyblockId, int improvementLevels, Player *owner, bool mortgaged)
    : Square(name, posn, propertyValue, ownable),
      monopolyblockId(monopolyblockId),
      improvementLevels(improvementLevels),
      owner(owner),
      mortgaged(mortgaged)
{
    
}

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
    // If the property is unowned, prompt purchase
    if (owner == nullptr) {
        cout << p->getName() << " landed on " << getName() 
             << ". This property is unowned and costs $" << propertyValue << "." << endl;
        return true; // You might then prompt the player to buy it.
    }
    // If the property is owned by another player
    else if (owner != p) {
        if (mortgaged) {
            cout << p->getName() << " landed on " << getName() 
                 << ", but it is mortgaged. No rent is due." << endl;
            return true;
        } else {
            const PropertyData* pd = PropertyData::lookup(getName());
            if (!pd) {
                cout << "Error: Property data not found for " << getName() << endl;
                return false;
            }
            int rent = 0;
            if (improvementLevels == 0 && !isMonopoly(p, monopolyblockID)) {
                rent = pd->rentTable[0] * 2;  // double the base rent if no improvements and no monopoly?
            } else {
                rent = pd->rentTable[improvementLevels];
            }
            cout << p->getName() << " must pay $" << rent << " in rent for " << getName() << "." << endl;
            p->pay(rent);
            owner->receive(rent);
            return true;
        }
    }
    // If the player lands on their own property
    else {
        cout << p->getName() << " landed on their own property " << getName() << "." << endl;
        return true;
    }
}

bool isMonopoly(Player *p, const std::string &monopolyId) {
    int totalCount = 0;
    const auto &db = PropertyData::getAcademicData();
    for (const auto &entry : db) {
        if (entry.second.monopolyBlockID == monopolyId) {
            totalCount++;
        }
    }
    int ownedCount = 0;
    for (Square *s : p->buildingsOwned) {
        PurchasableSquare *ps = dynamic_cast<PurchasableSquare*>(s);
        if (ps && ps->getMonopolyBlock() == monopolyId) {
            ownedCount++;
        }
    }
    return (ownedCount == totalCount && totalCount > 0);
}

void PurchasableSquare::mortgage() {
    // Ensure that improvements are sold before mortgaging
    if (improvementLevels > 0) {
        cout << "You must sell improvements before mortgaging this property." << endl;
        return;
    }

    // Mortgaging the property and giving the player 50% of the property value
    if (!mortgaged) {
        int mortgageValue = propertyValue / 2;  // Calculatting 50% of the property's value
        owner->receive(mortgageValue);  // Giving the player the mortgage amount
        mortgaged = true;  // Marking the property as mortgaged
        cout << owner->getName() << " has mortgaged " << getName() << " for $" << mortgageValue << endl;
    } else {
        cout << getName() << " is already mortgaged." << endl;
    }    
} 

void PurchasableSqaure::unmortgage() {
     // If property is mortgaged, unmortgage it
    if (mortgaged) {
        int unmortgageCost = (propertyValue * 60) / 100;  // Calculating 60% of the property's value
        if (owner->getMoney() >= unmortgageCost) {
            owner->pay(unmortgageCost);  // Paying the unmortgage cost (60% of the property value)
            mortgaged = false;  // Marking the property as unmortgaged
            cout << owner->getName() << " has unmortgaged " << getName() << " by paying $" << unmortgageCost << endl;
        } else {
            cout << "Insufficient funds to unmortgage " << getName() << "." << endl;
        }
    } else {
        cout << getName() << " is not mortgaged." << endl;
    }
} 
