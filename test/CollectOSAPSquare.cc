#include "CollectOSAPSquare.h"
#include "Player.h"

CollectOSAPSquare::CollectOSAPSquare(int posn, int amount)
    : ActionSquare("COLLECT OSAP", posn), collectAmount(amount) {
}

void CollectOSAPSquare::applyAction(Player *p) {
    // We aren't going to do anything here because we will handle collecting OSAP in main.cc
}
