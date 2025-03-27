#include "PurchasableSquare.h"
#include "Square.h"
#include "Player.h"
#include "PropertyData.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

PurchasableSquare::PurchasableSquare(
    const string &name, int posn, int propertyValue, bool ownable,
    const string &monopolyblockId, int improvementLevels,
    Player *owner, bool mortgaged
)
    : Square(name, posn, propertyValue, ownable),
      monopolyblockId(monopolyblockId),
      improvementLevels(improvementLevels),
      owner(owner),
      mortgaged(mortgaged) {}

void PurchasableSquare::buy(Player *p) {
    if(owner == nullptr && p->getMoney() >= getRent()) {
        p->pay(propertyValue);
        owner = p;
        cout << p->getName() << " purchased " << getName() 
             << " for $" << propertyValue << endl;
    } else {
        cout << "Insufficient Funds For Purchase" << endl;
    }
}

bool PurchasableSquare::landOn(Player *p) {
    if(owner == nullptr) {
        cout << p->getName() << " landed on " << getName() 
             << ". This property is unowned and costs $" << propertyValue << ".\n";
        return true;
    } else if(owner != p) {
        if(mortgaged) {
            cout << p->getName() << " landed on " << getName() 
                 << ", but it is mortgaged. No rent is due.\n";
            return true;
        } else {
            const PropertyData* pd = PropertyData::lookup(getName());
            if(!pd) {
                cout << "Error: Property data not found for " << getName() << endl;
                return false;
            }
            int rent = 0;
            if(improvementLevels == 0 && !isMonopoly(p))
                rent = pd->rentTable[0] * 2;
            else
                rent = pd->rentTable[improvementLevels];
            cout << p->getName() << " must pay $" << rent 
                 << " in rent for " << getName() << ".\n";
            p->pay(rent);
            owner->receive(rent);
            return true;
        }
    } else {
        cout << p->getName() << " landed on their own property " << getName() << ".\n";
        return true;
    }
}

bool PurchasableSquare::isMonopoly(Player *p) {
    // Stub: always return false.
    return false;
}

void PurchasableSquare::mortgage() {
    if(improvementLevels > 0) {
        cout << "Sell improvements before mortgaging.\n";
        return;
    }
    if(!mortgaged) {
        int mortgageValue = propertyValue / 2;
        owner->receive(mortgageValue);
        mortgaged = true;
        cout << owner->getName() << " mortgaged " << getName() 
             << " for $" << mortgageValue << ".\n";
    } else {
        cout << getName() << " is already mortgaged.\n";
    }
}

void PurchasableSquare::unmortgage() {
    if(mortgaged) {
        int unmortgageCost = (propertyValue * 60) / 100;
        if(owner->getMoney() >= unmortgageCost) {
            owner->pay(unmortgageCost);
            mortgaged = false;
            cout << owner->getName() << " unmortgaged " << getName() 
                 << " by paying $" << unmortgageCost << ".\n";
        } else {
            cout << "Insufficient funds to unmortgage " << getName() << ".\n";
        }
    } else {
        cout << getName() << " is not mortgaged.\n";
    }
}
