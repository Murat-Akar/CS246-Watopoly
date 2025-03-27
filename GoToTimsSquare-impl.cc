module GoToTims_square;
import <iostream>;
import player;
import action_square;
using namespace std;

GoToTimsSquare::GoToTimsSquare(int posn)
    : ActionSquare("GO TO TIMS", posn) {}

void GoToTimsSquare::applyAction(Player *p) {
    cout << p->getName() << " is sent to DC Tims Line!\n";
    p->setPosition(10);
}
