#include "Player.h"
#include "Observer.h"
#include "Square.h"
#include <iostream>
#include "PRNG.h"
#include "PurchasableSquare.h"
using namespace std;

extern PRNG prng1;

Player::Player(const string &name, const char &piece, int money, int posn, int timsCup, bool inTimsLine)
    : name{name}, piece{piece}, money(money), posn(posn), timsCups(timsCup), inTimsLine(inTimsLine), sentToTims(false), passedOSAP(false), timsLineTurns(0), lastRollSum(0) {}

Player::~Player() {
    buildingsOwned.clear();
}

bool Player::roll() { 
    //int  die1 = prng1(1,6); 
    //int  die2 = prng1(1,6);
    int oldPos = posn;
    int die1 = 10;
    int die2 = 20;
    int steps = die1 + die2;
    lastRollSum = steps;
    cout << name << " rolled a " << die1 << " and a " << die2 << endl;
    move(steps);
    if (oldPos + steps >= 40) {
        passedOSAP = true;
    } else {
        passedOSAP = false;
    }
    return (die1 == die2);
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

int Player::getLastRollSum() const {
    return lastRollSum;
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

char Player::getPiece() const {
    return piece;
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

bool Player::roll_testing(int die1, int die2) {
    posn = (posn + (die1 + die2)) % 40;
    return true;
}
//bankrupt to another player
void Player::bankrupt(Player *other) {
    for(auto s : buildingsOwned)
        other->addBuilding(s);
    buildingsOwned.clear();
}

//bankrupt to the bank
void Player::bankrupt(vector<Player*>& players) {
    for (auto s : buildingsOwned) {
        PurchasableSquare *ps = static_cast<PurchasableSquare*>(s);
        ps->setOwner(nullptr);
    }

    for (auto s : buildingsOwned) {
        PurchasableSquare *ps = static_cast<PurchasableSquare*>(s);
        ps->auction(players);
    }

    buildingsOwned.clear();
}

void Player::assets() const {
    for(auto s : buildingsOwned)
        cout << "Building: " << s->getName() << endl;

    cout << "You also have $" << getMoney() << endl;
}

void Player::setSentToTims(bool value) {
    sentToTims = value;
}

bool Player::isSentToTims() const {
    return sentToTims;
}

void Player::setPassedOSAP(bool value) {
    passedOSAP = value;
}

bool Player::hasPassedOSAP() const {
    return passedOSAP;
}

void Player::incrementTimsLineTurns() {
    timsLineTurns++;
}

void Player::resetTimsLineTurns() {
    timsLineTurns = 0;
}

int Player::getTimsLineTurns() const {
    return timsLineTurns;
}

void Player::setPosition(int position) {
    posn = position;
}

void Player::useCup() {
    if(timsCups > 0){
        timsCups--;
    }
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
    // Check if the other player has enough money.
    if(other->getMoney() >= amount) {
        other->pay(amount);    // Other pays the amount.
        receive(amount);       // Trader receives the amount.
        // Look for the building in the trader's own properties.
        for(auto it = buildingsOwned.begin(); it != buildingsOwned.end(); ) {
            if((*it)->getName() == receiving) {
                // Transfer the building from trader to other.
                other->addBuilding(*it);
                it = buildingsOwned.erase(it);
                cout << name << " traded " << receiving << " for $" << amount 
                        << " from " << other->getName() << endl;
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

