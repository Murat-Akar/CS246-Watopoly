#include "NeedlesHallSquare.h"
#include "Player.h"
#include <iostream>
#include <random>
using namespace std;

NeedlesHallSquare::NeedlesHallSquare(int posn)
    : ActionSquare("Needles Hall", posn) {
}

void NeedlesHallSquare::applyAction(Player *p) {
    // Simulate a random outcome for Needles Hall
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 18);
    int roll = dist(gen);

    int amount = 0;
    if (roll == 1) {
        amount = -200;
    } else if (roll == 2 || roll == 3) {
        amount = -100;
    } else if (roll >= 4 && roll <= 6) {
        amount = -50;
    } else if (roll >= 7 && roll <= 12) {
        amount = 25;
    } else if (roll == 13 || roll == 14) {
        amount = 50;
    } else if (roll == 15 || roll == 16) {
        amount = 100;
    } else {
        amount = 200;
    }

    if (amount < 0) {
        cout << p->getName() << " loses $" << -amount << " from Needles Hall.\n";
        p->pay(-amount);
    } else {
        cout << p->getName() << " gains $" << amount << " from Needles Hall.\n";
        p->receive(amount);
    }
}
