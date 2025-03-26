export module goosenesting_square;

import action_square;
import <string>;

export class GooseNestingSquare : public ActionSquare {
private:
    int collectAmount; // If your design requires it, otherwise can be omitted.

public:
    GooseNestingSquare(int posn, int collectAmount = 0);
    void applyAction(Player *p) override;
};