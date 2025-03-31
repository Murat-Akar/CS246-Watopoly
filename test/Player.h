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

    //Navigation around board
    bool roll();
    bool roll_testing(int die1, int die2);
    void move(int steps);
    int getPosn() const;
    void setPosition(int position);
    int getLastRollSum() const;

    // To Test If Broke
    void broke(string true_for_player, int amount_owed);
    bool isBroke();
    string indebtedTo();
    int debtAmount();
    void setisBroke(bool val);
    void setindebtedTo(string val);
    void setdebtAmount(int n);

    //Broke and Out:
    void bankrupt(Player *other);
    void bankrupt(vector<Player*>& players);

    //Identification:
    string getName() const;
    char getPiece() const;

    //cashflow:
    int getMoney() const;
    void pay(int amount);
    void receive(int amount);
    void assets() const;
    void trade(Player *other, int amount, const string &receiving);
    void trade(Player *other, const string &trading, const string &receiving);
    void trade(Player *other, const string &receiving, int amount);
    void addBuilding(Square *s);
    
    //Tims Line:
    void setSentToTims(bool value);
    bool isSentToTims() const;
    void receivedCup();
    int getTimsCupsVal() const;
    void atTimsLineSwitch();
    void useCup();

    //Jail:
    void incrementTimsLineTurns();
    void resetTimsLineTurns();
    int getTimsLineTurns() const;

    //OSAP:
    void setPassedOSAP(bool value);
    bool hasPassedOSAP() const;

    // Observer pattern methods (currently no-op implementations).
    void attach(Observer* o);
    void detach(Observer* o);
    
    bool broke_in_tims_line = false;

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
    bool broke_b;
    string brokeTo;
    int amountOwed;
};

#endif // PLAYER_H
