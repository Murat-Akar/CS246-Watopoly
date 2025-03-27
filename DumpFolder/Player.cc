#include "Player.h"
#include "PRNG.h"
#include "observer.h"
#include "Square.h"
#include <iostream>
#include <algorithm>
using namespace std;

Player::Player(const string &name, int money, int posn, int timsCup, bool inTimsLine)
    : name{name}, money(money), posn(posn), timsCups(timsCup), inTimsLine(inTimsLine) {}

Player::~Player() {
    for(auto s : buildingsOwned)
        delete s;
    buildingsOwned.clear();
}

void Player::roll() {
    int die1 = 2;
    int die2 = 3;
    int steps = die1 + die2;
    cout << name << " rolled a " << die1 << " and a " << die2 << endl;
    move(steps);
}

void Player::move(int steps) {
    posn = (posn + steps) % 40;
    cout << name << " moved " << steps << " steps to position " << posn << endl;
}

void Player::addBuilding(Square *s) {
    buildingsOwned.push_back(s);
}

void Player::receivedCup() {
    ++timsCups;
}

int Player::getTimsCupsVal() const { 
    return timsCups; 
}

int Player::getMoney() const { 
    return money; 
}

int Player::getPosn() const { 
    return posn; 
}

string Player::getName() const {
    return name;
}

void Player::atTimsLineSwitch() { 
    inTimsLine = !inTimsLine; 
}

void Player::pay(int amount) {
    if(money >= amount)
        money -= amount;
    else
        cout << "Insufficient funds" << endl;
}

void Player::receive(int amount) {
    money += amount;
}

void Player::bankrupt(Player *other) {
    for(auto s : buildingsOwned)
        other->addBuilding(s);
    buildingsOwned.clear();
}

void Player::assets() const {
    for(auto s : buildingsOwned)
        cout << "Building: " << s->getName() << endl;
}

void Player::setPosition(int position) {
    posn = position;
}

void Player::trade(Player *other, int amount, const string &receiving) {
    if(money >= amount) {
        pay(amount);
        other->receive(amount);
        for(auto it = other->buildingsOwned.begin(); it != other->buildingsOwned.end(); ) {
            if((*it)->getName() == receiving) {
                addBuilding(*it);
                it = other->buildingsOwned.erase(it);
                return;
            } else {
                ++it;
            }
        }
    }
    cout << "Trade failed." << endl;
}

void Player::trade(Player *other, const string &trading, const string &receiving) {
    auto itTrading = buildingsOwned.end();
    for(auto it = buildingsOwned.begin(); it != buildingsOwned.end(); ++it) {
        if((*it)->getName() == trading) {
            itTrading = it;
            break;
        }
    }
    auto itReceiving = other->buildingsOwned.end();
    for(auto it = other->buildingsOwned.begin(); it != other->buildingsOwned.end(); ++it) {
        if((*it)->getName() == receiving) {
            itReceiving = it;
            break;
        }
    }
    if(itTrading != buildingsOwned.end() && itReceiving != other->buildingsOwned.end()) {
        swap(*itTrading, *itReceiving);
        cout << name << " traded " << trading << " for " << receiving 
             << " with " << other->getName() << endl;
        return;
    }
    cout << "Trade failed." << endl;
}

void Player::trade(Player *other, const string &receiving, int amount) {
    if(money >= amount) {
        pay(amount);
        other->receive(amount);
        for(auto it = other->buildingsOwned.begin(); it != other->buildingsOwned.end(); ) {
            if((*it)->getName() == receiving) {
                addBuilding(*it);
                it = other->buildingsOwned.erase(it);
                return;
            } else {
                ++it;
            }
        }
    }
    cout << "Trade failed." << endl;
}

// Observer pattern methods (currently no-op implementations)
void Player::attach(Observer* o) { /* no-op */ }
void Player::detach(Observer* o) { /* no-op */ }
