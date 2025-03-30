#include "SLCSquare.h"
#include "Player.h"
#include "PropertyData.h"
#include "PurchasableSquare.h"
#include "ActionSquare.h"
#include <random>
#include "PRNG.h"

extern int totalCups; // Using to keep track of total cups across all players

SLCSquare::SLCSquare(int posn)
    : ActionSquare("SLC", posn) {
}

void SLCSquare::applyAction(Player *p) {
    static PRNG prng; 

    int roll = prng(1, 24);

    if (roll <= 3) { 
        cout << p->getName() << " moves back 3.\n";
        p->move(-3);
    } else if (roll <= 7) {
        cout << p->getName() << " moves back 2.\n";
        p->move(-2);
    } else if (roll <= 11) {
        cout << p->getName() << " moves back 1.\n";
        p->move(-1);
    } else if (roll <= 14) {
        cout << p->getName() << " moves forward 1.\n";
        p->move(1);
    } else if (roll <= 18) {
        cout << p->getName() << " moves forward 2.\n";
        p->move(2);
    } else if (roll <= 22) {
        cout << p->getName() << " moves forward 3.\n";
        p->move(3);
    } else if (roll == 23) {
        cout << p->getName() << " is sent to DC Tims Line!\n";
        p->setPosition(10);  
    } else {
        cout << p->getName() << " advances to Collect OSAP.\n";
        p->setPosition(0); 
    }
    const auto &data = PropertyData::getAcademicData();
    string realName;
    const PropertyData *pd_ptr = nullptr;
    int count = 0;
    for (const auto &entry : data) {
        if (count == new_posn) {
            realName = entry.first;
            pd_ptr = &entry.second;
            break;
        }
        count++;
    }
    

    if (totalCups < 4 && prng(1, 100) <= 1) { 
        cout << p->getName() << " receives a Roll Up the Rim cup!\n";
        p->receivedCup();
        totalCups++;  
    }

    if (pd_ptr) {
        const PropertyData &pd = *pd_ptr;
        if (pd.improvable) {
            PurchasableSquare *tempSquare = new PurchasableSquare(
                realName,
                new_posn,
                pd.purchase_cost,
                true,
                pd.monopolyblockID,
                0,        // initial improvement level
                nullptr,  // no owner initially
                false     // not mortgaged
            );
            cout << "Created PurchasableSquare: " << tempSquare->getName() << endl;
            tempSquare->landOn(p);
            delete tempSquare;
        } else {
            // Create an ActionSquare using its constructor.
            ActionSquare *tempSquare = new ActionSquare(realName, new_posn);
            cout << "Created ActionSquare: " << tempSquare->getName() << endl;
            tempSquare->landOn(p);
            delete tempSquare;
        }
    } else {
        cout << "No property data found for board index " << new_posn << ".\n";
    }
}
