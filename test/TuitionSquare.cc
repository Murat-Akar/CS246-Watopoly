#include "TuitionSquare.h"
#include "PurchasableSquare.h"
#include "Player.h"

TuitionSquare::TuitionSquare(int posn, int tuitionAmount)
    : ActionSquare("TUITION", posn), tuitionAmount(tuitionAmount) {
}

void TuitionSquare::applyAction(Player *p) {
    int totalWorth = p->getMoney();
    for (auto &sq : p->buildingsOwned) {
        PurchasableSquare *ps = dynamic_cast<PurchasableSquare*>(sq);
        if (ps) {
           totalWorth += ps->getRent();
           totalWorth += (ps->getImprovementLevels() * 50);
        }
        else {
            cout << "Not A Asset" << endl;
        }
    }
    int tenPercent = totalWorth / 10;
    cout << p->getName() << " must pay either $" << tuitionAmount << " or 10 percent of total worth ($" << tenPercent << ").\n";
    int finalPayment = 0;
    if (p->getMoney() >= 300) {
        finalPayment = 300;
    }
    else {
        finalPayment = tenPercent;
    }
    p->pay(finalPayment);
    cout << p->getName() << " pays $" << finalPayment << " in tuition.\n";
}
