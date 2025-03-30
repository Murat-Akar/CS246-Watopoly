#include "SLCSquare.h"
#include "Player.h"
#include "PropertyData.h"
#include "PurchasableSquare.h"
#include "ActionSquare.h"
#include "PRNG.h"
#include "CoopFeeSquare.h"
#include "NeedlesHallSquare.h"
#include "TuitionSquare.h"
#include "GooseNestingSquare.h"
#include "GoToTimsSquare.h"
#include "TimsLineSquare.h"
#include <iostream>
using namespace std;

extern int totalCups; // Global variable for total cups

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

    
    if (totalCups < 4 && prng(1, 100) <= 1) { 
        cout << p->getName() << " receives a Roll Up the Rim cup!\n";
        p->receivedCup();
        totalCups++;  
    }

    // Use the player's updated position.
    int new_posn = p->getPosn();

    // Manually iterate over the property data map to find the entry for board index new_posn.
    const auto &data = PropertyData::getAcademicData();

    string realName;
    const PropertyData *pd_ptr = nullptr;
    
    for(auto it = data.begin(); it != data.end(); ++it) {
       if ((*it).second.posn == new_posn) {
            realName = (*it).first;
            pd_ptr = &it->second;
       }
    }
    
    if (pd_ptr) {
        const PropertyData &pd = *pd_ptr;
        if (pd.improvable) {
            // Create a new PurchasableSquare using the real property name and data.
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
            // For non-improvable properties, choose the correct square based on its real name.
            if (realName == "COOP FEE") {
                CoopFeeSquare *tempSquare = new CoopFeeSquare(new_posn, 150);
                cout << "Created CoopFeeSquare: " << tempSquare->getName() << endl;
                tempSquare->landOn(p);
                delete tempSquare;
            }
            else if (realName == "NEEDLES HALL") {
                NeedlesHallSquare *tempSquare = new NeedlesHallSquare(new_posn);
                cout << "Created NeedlesHallSquare: " << tempSquare->getName() << endl;
                tempSquare->landOn(p);
                delete tempSquare;
            }
            else if (realName == "TUITION") {
                TuitionSquare *tempSquare = new TuitionSquare(new_posn, 300);
                cout << "Created TuitionSquare: " << tempSquare->getName() << endl;
                tempSquare->landOn(p);
                delete tempSquare;
            }
            else if (realName == "GOOSE NESTING") {
                GooseNestingSquare *tempSquare = new GooseNestingSquare(new_posn);
                cout << "Created GooseNestingSquare: " << tempSquare->getName() << endl;
                tempSquare->landOn(p);
                delete tempSquare;
            }
            else if (realName == "GO TO TIMS") {
                GoToTimsSquare *tempSquare = new GoToTimsSquare(new_posn);
                cout << "Created GoToTimsSquare: " << tempSquare->getName() << endl;
                tempSquare->landOn(p);
                delete tempSquare;
            }
            else if (realName == "SLC") {
                // If it happens to be SLC again, re-instantiate an SLCSquare.
                SLCSquare *tempSquare = new SLCSquare(new_posn);
                cout << "Created SLCSquare: " << tempSquare->getName() << endl;
                tempSquare->landOn(p);
                delete tempSquare;
            }
            else if (realName == "DC TIMS LINE") {
                TimsLineSquare *tempSquare = new TimsLineSquare(new_posn, 0);
                cout << "Created TimsLineSquare: " << tempSquare->getName() << endl;
                tempSquare->landOn(p);
                delete tempSquare;
            }
            else {
                cout << "Unknown non-improvable square type: " << realName << ". No action taken.\n";
            }
        }
    } else {
        cout << "No property data found for board index " << new_posn << ".\n";
    }
}
