export module timsline_square;

import action_square;
import <string>;

export class TimsLineSquare : public ActionSquare {
private:
    int activeCups;

public:
    TimsLineSquare(int posn, int cups = 0);
    void applyAction(Player *p) override;
};
