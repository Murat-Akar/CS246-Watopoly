export module collectosap_square;

import action_square;
import <string>;

export class CollectOSAPSquare : public ActionSquare {
private:
    int collectAmount;

public:
    CollectOSAPSquare(int posn, int amount);
    void applyAction(Player *p) override;
};
