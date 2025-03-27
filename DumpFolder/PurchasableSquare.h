#ifndef PURCHASABLE_SQUARE_H
#define PURCHASABLE_SQUARE_H

#include "Square.h"
#include "Player.h"
#include "PropertyData.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class PurchasableSquare : public Square {
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
    bool isMonopoly(Player *p); // Stub implementation: always false.
    void mortgage();
    void unmortgage();
    bool landOn(Player *p) override;
};

#endif // PURCHASABLE_SQUARE_H
