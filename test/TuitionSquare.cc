#include "TuitionSquare.h"
#include "Player.h"

TuitionSquare::TuitionSquare(int posn, int tuitionAmount)
    : ActionSquare("TUITION", posn), tuitionAmount(tuitionAmount) {
}

void TuitionSquare::applyAction(Player *p) {
    // Here we assume Player has a method getTotalWorth() – adjust as needed.
    int totalWorth = 1500; // Placeholder value
    int tenPercent = totalWorth / 10;
    cout << p->getName() << " must pay either $" << tuitionAmount << " or 10% of total worth ($" << tenPercent << ").\n";
    int finalPayment = (tenPercent < tuitionAmount) ? tenPercent : tuitionAmount;
    p->pay(finalPayment);
    cout << p->getName() << " pays $" << finalPayment << " in tuition.\n";
}
