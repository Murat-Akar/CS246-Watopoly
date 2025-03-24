export module square;
import <iostream>;
import <string>;
import <sstream>;
using namespace std;

// Abstract base class of squares
export class Square {
    private:
    string name;
    int posn;
    int squareVal;
    bool isOwnable;
    public:
    Square(const string &name, const int posn, int squareVal, bool isOwnable);
    virtual ~Square();
    virtual bool landOn (Player *p);
    string getName() const;
    int getRent();
    int getPosition() const;
    bool isPurchasable();
};
