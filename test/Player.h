#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Observer.h"  // For Observer definition; ensure observer.h exists in your project.
#include "Square.h"    // Ensure this file exists with the full Square definition.
// #include "PRNG.h"      // For prng function.

using namespace std;

class Player {
public:
    // Updated constructor: now requires five arguments.
    Player(const string &name, int money, int posn, int timsCup, bool inTimsLine);
    ~Player();

    void roll();
    void move(int steps);
    void addBuilding(Square *s);
    void receivedCup();
    int getTimsCupsVal() const;
    int getMoney() const;
    int getPosn() const;
    // Added getName() so that callers can access the player's name.
    string getName() const;
    void atTimsLineSwitch();
    void pay(int amount);
    void receive(int amount);
    void bankrupt(Player *other);
    void assets() const;
    void setPosition(int position);
    void trade(Player *other, int amount, const string &receiving);
    void trade(Player *other, const string &trading, const string &receiving);
    void trade(Player *other, const string &receiving, int amount);

    // Observer pattern methods (currently no-op implementations).
    void attach(Observer* o);
    void detach(Observer* o);

private:
    string name;
    int money;
    int posn;
    int timsCups;
    bool inTimsLine;
    vector<Square*> buildingsOwned;
};

#endif // PLAYER_H
