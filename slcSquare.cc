export module slc_square;

import action_square;
import <string>;

export class SLCSquare : public ActionSquare {
public:
    SLCSquare(int posn);
    void applyAction(Player *p) override;
};
