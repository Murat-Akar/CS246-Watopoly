#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <vector>
#include "Config.h"
using namespace std;

class Player; // forward declaration

class Square {
protected:
    string name;
    int index; // square index [0..39]
public:
    Square(const string &n, int i);
    virtual ~Square() = default;
    virtual bool landOn(Player *p) = 0;
    string getName() const;
    int getIndex() const;
    
    // printBox returns a CELL_H×CELL_W ASCII box with the square's name centered.
    virtual vector<string> printBox() const;
};

#endif // SQUARE_H
