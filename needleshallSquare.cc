export module needleshall_square;

import action_square;
import <string>;

export class NeedlesHallSquare : public ActionSquare {
public:
    NeedlesHallSquare(int posn);
    void applyAction(Player *p) override;
};
