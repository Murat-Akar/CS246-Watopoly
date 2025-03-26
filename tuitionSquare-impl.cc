module tuition_square;

import <iostream>;
import player;

TuitionSquare::TuitionSquare(int posn, int tuitionAmount)
    : ActionSquare("Tuition", posn), tuitionAmount(tuitionAmount) {}

void TuitionSquare::applyAction(Player *p) {
    // Suppose you have a method to calculate total worth:
    int totalWorth = p->getTotalWorth(); // Or your own logic to compute this
    int tenPercent = totalWorth / 10;

    std::cout << p->getName() << " must pay either $" 
              << tuitionAmount << " or 10% of total worth ($" 
              << tenPercent << ").\n";

              //Probably add a field in TuitionSquare for the choice they maake

    // For demonstration, let's choose automatically. In a real game,
    // we'd prompt the user or implement your own logic:
    int finalPayment = (tenPercent < tuitionAmount) ? tenPercent : tuitionAmount;
    p->pay(finalPayment);

    std::cout << p->getName() << " pays $" << finalPayment 
              << " in tuition";
}