#include "GoToTimsSquare.h"
#include "Player.h"

GoToTimsSquare::GoToTimsSquare(int posn)
    : ActionSquare("GO TO TIMS", posn) {
}

void GoToTimsSquare::applyAction(Player *p) {
    cout << p->getName() << " is sent to DC Tims Line!\n";
    p->setPosition(10); // Assuming Tims Line is at index 10.
    p->setSentToTims(true);
}
