#include "SLCSquare.h"
#include "Player.h"
#include <random>

SLCSquare::SLCSquare(int posn)
    : ActionSquare("SLC", posn) {
}

void SLCSquare::applyAction(Player *p) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 24);
    int roll = dist(gen);

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
}
