#include "NeedlesHallSquare.h"
#include "Player.h"
#include <iostream>
#include "PRNG.h"

using namespace std;

extern int totalCups;

NeedlesHallSquare::NeedlesHallSquare(int posn)
    : ActionSquare("NEEDLES HALL", posn) {
}

void NeedlesHallSquare::applyAction(Player *p) {
    static PRNG prng;

    if (totalCups < 4 && prng(1, 100) <= 1) {
        cout << p->getName() << " receives a Roll Up the Rim cup!\n";
        p->receivedCup(); 
        totalCups++;
        return;
    }

    int roll = prng(1, 18);

    int amount = 0;
    if (roll == 1) {
        amount = -200;
    } else if (roll == 2 || roll == 3) {
        amount = -100;
    } else if (roll >= 4 && roll <= 6) {
        amount = -50;
    } else if (roll >= 7 && roll <= 12) {
        amount = 25;
    } else if (roll >= 13 && roll <= 15) {
        amount = 50;
    } else if (roll == 16 || roll == 17) {
        amount = 100;
    } else {  // scenario where roll == 18
        amount = 200;
    }

    if (amount < 0) {
        cout << p->getName() << " loses $" << -amount 
                  << " from Needles Hall.\n";
        p->pay(-amount);
    } else {
        cout << p->getName() << " gains $" << amount 
                  << " from Needles Hall.\n";
        p->receive(amount);
    }    
}