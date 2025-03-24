export module player;
#include "PRNG.h"
import <iostream>;
import <string>;
import <sstream>;
import <vector>;
import building; // havent made building yet
using namespace std;

class Player {
    private:
    string name;
    int money, posn, timsCups;
    bool inTimsLine;
    vector<Building*> buildingsOwned;

    public:
    Player(const string &name, int money, int posn, int timsCups, bool inTimsLine);
    ~Player();
    void roll();
    void move(int steps);
    int getTimsCupsVal();
    int getMoney();
    int getPosn();
    void receivedCup();
    void atTimsLineSwitch();
    void pay(int amount);
    void receive(int amount);
    void bankrupt(Player *other);
    void assets();
    void trade (Player *other, int amount, const string &receiving);
    void trade(Player *other, const string &trading, const string &receiving);
    void trade (Player *other, const string &receiving, int amount);
};
