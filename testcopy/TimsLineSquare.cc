#include "TimsLineSquare.h"
#include "Player.h"

TimsLineSquare::TimsLineSquare(int posn, int cups)
    : ActionSquare("DC Tims Line", posn), activeCups(cups) {
}

void TimsLineSquare::applyAction(Player *p) {
    cout << p->getName() << " landed on DC Tims Line. (No immediate effect.)\n";
    // Special handling for leaving Tims Line in the game loop.
}
