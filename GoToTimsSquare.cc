export module GoToTims_square;
import <iostream>;
import player;
import action_square;
using namespace std;

export class GoToTimsSquare : public ActionSquare {
public:
    GoToTimsSquare(int posn);
    void applyAction(Player *p) override;
};
