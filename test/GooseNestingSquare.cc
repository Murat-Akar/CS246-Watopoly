#include "GooseNestingSquare.h"
#include "Player.h"

GooseNestingSquare::GooseNestingSquare(int posn, int collectAmount)
    : ActionSquare("Goose Nesting", posn), collectAmount(collectAmount) {
}

void GooseNestingSquare::applyAction(Player *p) {
    cout << p->getName() << " is attacked by a flock of nesting geese! No further effect.\n";
}
