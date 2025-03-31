#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <vector>
using namespace std;

class Player;  // Forward declaration

class Square {
protected:
    string name;
    int posn;
    int squareVal;   // Typically, the property's value or rent
    bool isOwnable;
public:
    // Constructor and virtual destructor
    Square(const string &name, int posn, int squareVal, bool isOwnable);
    virtual ~Square();

    // Pure virtual: each square must define what happens when a player lands on it.
    virtual bool landOn(Player *p) = 0;
    // Getters
    const string& getName() const;
    int getRent() const;
    int getPosition() const;
    bool isPurchasable() const;

    // Returns a simple ASCII box (for display) as a vector of strings.
    virtual vector<string> print_square(const vector<Player*>& players) const;
};

#endif // SQUARE_H
