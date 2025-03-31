#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Observer.h"  // For Observer definition; ensure observer.h exists in your project.
#include "Square.h"    // Ensure this file exists with the full Square definition.
#include "PRNG.h"      // For prng function.

using namespace std;

class Player {
public:
    vector<Square*> buildingsOwned;
    Player(const string &name, const char &piece, int money, int posn, int timsCup, bool inTimsLine);
    ~Player();

    bool roll();
    bool roll_testing(int die1, int die2);
    void move(int steps);
    void addBuilding(Square *s);
    void receivedCup();
    int getTimsCupsVal() const;
    int getMoney() const;
    int getPosn() const;
    string getName() const;
    char getPiece() const;
    void atTimsLineSwitch();
    void pay(int amount);
    void receive(int amount);
    void bankrupt(Player *other);
    void bankrupt();
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
    const char piece;
    int money;
    int posn;
    int timsCups;
    bool inTimsLine;
};

#endif // PLAYER_H
