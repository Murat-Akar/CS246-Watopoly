module player;
#include "PRNG.h"
import <iostream>;
import <string>;
import <sstream>;
import <vector>;
import <algorithm>; //swap usage
import square;
using namespace std;

Player::Player(const string &name, int money, int posn, int timsCup, bool inTimsLine)
    : name{name}, money{1500}, posn{0}, timsCups{0}, inTimsLine{false} {
}

Player::~Player() {
    for (Square* s : buildingsOwned) {
        delete s;
    }
    buildingsOwned.clear();
}

void Player::roll() {
    int die1 = prng(1, 6);
    int die2 = prng(1, 6);
    int steps = die1 + die2;
    cout << name << " rolled a " << die1 << " and a " << die2 << endl;
    move(steps);
}

void Player::move(int steps) {
    posn += steps;
    posn = posn % 40; // wrap around board of 40 squares
    cout << name << " moved " << steps << " steps" << endl;
}

void Player::addBuilding(Square *s) {
    buildingsOwned.emplace_back(s);
}

void Player::receivedCup() {
    ++timsCups;
}

int Player::getTimsCupVal() { return timsCups; }
int Player::getMoney() { return money; }
int Player::getPosn() { return posn; }
void Player::atTimsLineSwitch() { inTimsLine = !inTimsLine; }

void Player::pay(int amount) {
    if (money >= amount) {
        money -= amount;
    } else {
        cout << "insufficient funds" << endl;
    }
}

void Player::receive(int amount) {
    money += amount;
}

void Player::bankrupt(Player *other) {
    // Transfer all owned squares (ownable properties) to the other player.
    for (size_t i = 0; i < buildingsOwned.size(); i++) {
        other->buildingsOwned.push_back(buildingsOwned[i]);
    }
    buildingsOwned.clear();
}

void Player::assets() {
    for (Square* s : buildingsOwned) {
        cout << "Building Name: " << s->getName() 
             << "   Building Value: " << s->getValue() << endl;
    }
}

void Player::trade(Player *other, int amount, const string &receiving) {
    if (money >= amount) {
        pay(amount);
        other->receive(amount);
        for (vector<Square*>::iterator it = other->buildingsOwned.begin(); 
             it != other->buildingsOwned.end(); ) {
            if ((*it)->getName() == receiving) {
                // Transfer the square pointer from other to this player.
                buildingsOwned.emplace_back(*it);
                it = other->buildingsOwned.erase(it);
                return;
            } else {
                ++it;
            }
        }
    }
    cout << "Trade Failed, either insufficient funds or nonexistent/unowned Building" << endl;
}

// Overloaded trade function: swapping buildings between players.
void Player::trade(Player *other, const string &trading, const string &receiving) {
    vector<Square*>::iterator itTrading = buildingsOwned.end();
    for (vector<Square*>::iterator it = buildingsOwned.begin(); it != buildingsOwned.end(); ++it) {
        if ((*it)->getName() == trading) {
            itTrading = it;
            break;
        }
    }
    
    // Find the square named 'receiving' in the other player's buildingsOwned.
    vector<Square*>::iterator itReceiving = other->buildingsOwned.end();
    for (vector<Square*>::iterator it = other->buildingsOwned.begin(); it != other->buildingsOwned.end(); ++it) {
        if ((*it)->getName() == receiving) {
            itReceiving = it;
            break;
        }
    }
    
    // If both squares were found, swap their pointers.
    if (itTrading != buildingsOwned.end() && itReceiving != other->buildingsOwned.end()) {
        std::swap(*itTrading, *itReceiving);
        cout << name << " traded " << trading << " for " << receiving 
             << " with " << other->getName() << endl;
        return;
    }
    
    cout << "Trade failed, either insufficient funds or nonexistent/unowned Building" << endl;
}

// Overloaded trade function: trading a building for money.
void Player::trade(Player *other, const string &receiving, int amount) {
    if (money >= amount) {
        pay(amount);
        other->receive(amount);
        for (vector<Square*>::iterator it = other->buildingsOwned.begin(); 
             it != other->buildingsOwned.end(); ) {
            if ((*it)->getName() == receiving) {
                buildingsOwned.push_back(*it);
                it = other->buildingsOwned.erase(it);
                return;
            } else {
                ++it;
            }
        }
    }
    cout << "Trade Failed, either insufficient funds or nonexistent/unowned Building" << endl;
}