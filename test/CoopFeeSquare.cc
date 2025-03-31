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
    if (p->getMoney() < fee) {
        cout << "You don't have enough money to pay the fee! Either mortgage property or file bankruptcy" << endl;
        
    } else {
        p->pay(fee);
    }
}
