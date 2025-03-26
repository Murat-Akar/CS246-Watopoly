module coopfee_square;

import <iostream>;
import player;

CoopFeeSquare::CoopFeeSquare(int posn, int fee)
    : ActionSquare("Co-op Fee", posn), fee(fee) {}

void CoopFeeSquare::applyAction(Player *p) {
    std::cout << p->getName() 
              << " pays a co-op fee of $" << fee << ".\n";
    p->pay(fee);
}