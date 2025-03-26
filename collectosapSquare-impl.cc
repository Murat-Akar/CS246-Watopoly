module collectosap_square;

import <iostream>;
import player;

CollectOSAPSquare::CollectOSAPSquare(int posn, int amount)
    : ActionSquare("Collect OSAP", posn), collectAmount(amount) {}

void CollectOSAPSquare::applyAction(Player *p) {
    std::cout << p->getName() << " collects $" 
              << collectAmount << " from OSAP.\n";
    p->receive(collectAmount);
}