#ifndef PURCHASABLE_SQUARE_H
#define PURCHASABLE_SQUARE_H

#include "Square.h"
#include "Player.h"
#include "PropertyData.h"
#include <string>
#include <vector>
#include <iostream>
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
    bool isMonopoly(); 
    void mortgage();
    void unmortgage();
    void inc_improvementLevel(Player *p);
    void dec_improvementLevel(Player *p);
    virtual bool landOn(Player *p) override;
    void setOwner(Player *new_owner);
    Player* getOwner();
    // For use in isMonopoly checking.
    string getMonopolyBlock() const { return monopolyblockId; }
    int getImprovementLevels() const { return improvementLevels; }
};

#endif // PURCHASABLE_SQUARE_H
