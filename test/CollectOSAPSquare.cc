#include "CollectOSAPSquare.h"
#include "Player.h"

CollectOSAPSquare::CollectOSAPSquare(int posn, int amount)
    : ActionSquare("Collect OSAP", posn), collectAmount(amount) {
}

void CollectOSAPSquare::applyAction(Player *p) {
    cout << p->getName() << " collects $" << collectAmount << " from OSAP.\n";
    p->receive(collectAmount);
}
