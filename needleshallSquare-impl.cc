module needleshall_square;

import <iostream>;
import <random>;
import player;

NeedlesHallSquare::NeedlesHallSquare(int posn)
    : ActionSquare("Needles Hall", posn) {}

void NeedlesHallSquare::applyAction(Player *p) {
    // We'll simulate a random int from 1..18 for the distribution
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 18);
    int roll = dist(gen);

    int amount = 0;
    if (roll == 1) {
        amount = -200;       // 1/18
    } else if (roll == 2 || roll == 3) {
        amount = -100;       // 2/18 => 1/9
    } else if (roll >= 4 && roll <= 6) {
        amount = -50;        // 3/18 => 1/6
    } else if (roll >= 7 && roll <= 12) {
        amount = 25;         // 6/18 => 1/3
    } else if (roll == 13 || roll == 14) {
        amount = 50;         // 2/18 => 1/9
    } else if (roll == 15 || roll == 16) {
        amount = 100;        // 2/18 => 1/9
    } else {
        amount = 200;        // 17,18 => 2/18 => 1/9 (the table says 1/18 for 200, so you might adjust accordingly)
    }

    if (amount < 0) {
        std::cout << p->getName() << " loses $" << -amount 
                  << " from Needles Hall.\n";
        p->pay(-amount);  // pay() expects a positive integer
    } else {
        std::cout << p->getName() << " gains $" << amount 
                  << " from Needles Hall.\n";
        p->receive(amount);
    }

    // 1% chance for a Roll Up the Rim Cup if fewer than 4 cups exist
    // (Placeholder: integrate your actual cup logic here)
}