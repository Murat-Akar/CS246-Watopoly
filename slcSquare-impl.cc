module slc_square;

import <iostream>;
import <random>;
import player;

SLCSquare::SLCSquare(int posn)
    : ActionSquare("SLC", posn) {}

void SLCSquare::applyAction(Player *p) {
    // We'll simulate a random integer from 1..24 to match the probabilities
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 24);
    int roll = dist(gen);

    if (roll <= 3) { 
        // 3 out of 24 => 1/8 chance => back 3
        std::cout << p->getName() << " moves back 3.\n";
        p->move(-3);
    } else if (roll <= 7) {
        // next 4 out of 24 => 1/6 chance => back 2
        std::cout << p->getName() << " moves back 2.\n";
        p->move(-2);
    } else if (roll <= 11) {
        // next 4 out of 24 => 1/6 chance => back 1
        std::cout << p->getName() << " moves back 1.\n";
        p->move(-1);
    } else if (roll <= 14) {
        // next 3 out of 24 => 1/8 chance => forward 1
        std::cout << p->getName() << " moves forward 1.\n";
        p->move(1);
    } else if (roll <= 18) {
        // next 4 out of 24 => 1/6 chance => forward 2
        std::cout << p->getName() << " moves forward 2.\n";
        p->move(2);
    } else if (roll <= 22) {
        // next 4 out of 24 => 1/6 chance => forward 3
        std::cout << p->getName() << " moves forward 3.\n";
        p->move(3);
    } else if (roll == 23) {
        // 1 out of 24 => 1/24 => go to DC Tims Line
        std::cout << p->getName() << " is sent to DC Tims Line!\n";
        // Suppose DC Tims Line is at board index 10, for example
        p->setPosition(10);
    } else {
        // roll == 24 => 1 out of 24 => go to OSAP
        std::cout << p->getName() << " advances to Collect OSAP.\n";
        // Suppose OSAP is at board index 0
        p->setPosition(0);
        // Possibly also collect $200 if your rules say so on a direct move
    }

    // 1% chance for a Roll Up the Rim Cup if fewer than 4 cups exist
    // (Placeholder: integrate your actual cup logic here)
}