// CoopFeeSquare.cc
#include "CoopFeeSquare.h"
#include "Player.h"
#include <iostream>
using namespace std;

CoopFeeSquare::CoopFeeSquare(int posn, int fee)
    : ActionSquare("COOP FEE", posn), fee(fee) {
}

void CoopFeeSquare::applyAction(Player *p) {
    cout << p->getName() << " pays a co-op fee of $" << fee << ".\n";
    p->pay(fee);
}
