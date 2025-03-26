export module coopfee_square;

import action_square;
import <string>;

export class CoopFeeSquare : public ActionSquare {
private:
    int fee;

public:
    CoopFeeSquare(int posn, int fee = 150);
    void applyAction(Player *p) override;
};
