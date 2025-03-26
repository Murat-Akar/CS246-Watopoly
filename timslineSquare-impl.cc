module timsline_square;

import <iostream>;
import player;

TimsLineSquare::TimsLineSquare(int posn, int cups)
    : ActionSquare("DC Tims Line", posn), activeCups(cups) {}

void TimsLineSquare::applyAction(Player *p) {
    // What happens when we end up landing on DC Tims Line by moving normally:
    std::cout << p->getName() 
              << " landed on DC Tims Line. (No immediate effect.)\n";
    // The special rules for leaving Tims Line would be handled in oour game loop
    // (checking if the player is "stuck" here, rolling doubles, paying $50, etc.)
}
