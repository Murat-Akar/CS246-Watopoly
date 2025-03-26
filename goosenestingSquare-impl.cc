module goosenesting_square;

import <iostream>;
import player;

GooseNestingSquare::GooseNestingSquare(int posn, int collectAmount)
    : ActionSquare("Goose Nesting", posn), collectAmount(collectAmount) {}

void GooseNestingSquare::applyAction(Player *p) {
    std::cout << p->getName() 
              << " is attacked by a flock of nesting geese! No further effect.\n";
    // If you want to give or deduct money, you could do:
    // p->receive(collectAmount);
}
