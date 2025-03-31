#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Observer.h" 
#include "Square.h"   
#include "PRNG.h"    

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
    void bankrupt(vector<Player*>& players);
    void assets() const;
    void setPosition(int position);
    void trade(Player *other, int amount, const string &receiving);
    void trade(Player *other, const string &trading, const string &receiving);
    void trade(Player *other, const string &receiving, int amount);
    void setSentToTims(bool value);
    bool isSentToTims() const;
    void setPassedOSAP(bool value);
    bool hasPassedOSAP() const;
    void incrementTimsLineTurns();
    void resetTimsLineTurns();
    int getTimsLineTurns() const;
    void setTimsLineSwitch();
    void useCup();
    int getLastRollSum() const;

    void attach(Observer* o);
    void detach(Observer* o);

private:
    string name;
    const char piece;
    int money;
    int posn;
    int timsCups;
    bool inTimsLine;
    bool sentToTims;
    bool passedOSAP;
    int timsLineTurns;
    int lastRollSum;
};

#endif 
