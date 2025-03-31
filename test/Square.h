#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <vector>
using namespace std;

class Player; 

class Square {
protected:
    string name;
    int posn;
    int squareVal;
    bool isOwnable;
public:
    Square(const string &name, int posn, int squareVal, bool isOwnable);
    virtual ~Square();

    virtual bool landOn(Player *p) = 0;
    const string& getName() const;
    int getRent() const;
    int getPosition() const;
    bool isPurchasable() const;

    virtual vector<string> print_square(const vector<Player*>& players) const;
};

#endif
