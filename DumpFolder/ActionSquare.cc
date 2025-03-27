#include "ActionSquare.h"
#include "Player.h"  // include full definition of Player
#include <iostream>
using namespace std;

ActionSquare::ActionSquare(const string &n, int i) : Square(n, i) {}

bool ActionSquare::landOn(Player *p) {
    cout << p->getName() << " lands on " << name << " (Action)\n";
    return true;
}
