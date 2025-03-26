export module tuition_square;

import action_square;
import <string>;

export class TuitionSquare : public ActionSquare {
private:
    int tuitionAmount; // e.g., 300

public:
    TuitionSquare(int posn, int tuitionAmount = 300);
    void applyAction(Player *p) override;
};
