#include "SLCSquare.h"
#include "Player.h"
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

    if (totalCups < 4 && prng(1, 100) <= 1) { 
        cout << p->getName() << " receives a Roll Up the Rim cup!\n";
        p->receivedCup();
        totalCups++;  
    }
}