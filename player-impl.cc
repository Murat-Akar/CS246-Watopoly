module player;
#include "PRNG.h"
import <iostream>;
import <string>;
import <sstream>;
import <vector>;
import <algorithm>; //swap usage
import building;
using namespace std;

Player::Player(const string &name, int money, int posn, int timsCup, bool inTimsLine):
    name{name}, money{1500}, posn{0}, timsCup{0}, inTimsLine{false}{}

Player::~Player() {
 for (Building* b : buildingsOwned) {
        delete b;
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
    posn = posn % 40; // if posn hits 40 reset to 0
    cout << name << " moved "  << steps << " steps" << endl;
}
void Player::addBuilding(Building *b) {buildingsOwned.emplace_back(b);}
void Player::receivedCup(){return ++timsCup;}
int Player::getTimsCupVal() {return timsCup;}
int Player::getMoney() {return money;}
int Player::getPosn() {return posn;}
void Player::atTimsLineSwitch(){inTimsLine = !inTimsLine;}

void Player::pay(int amount) {
    if (money >= amount) {
        money -= amount;
    }
    else {
        cout << "insufficient funds" << endl;
    }
}

void Player::receive(int amount) {
    money += amount;
}

void Player::bankrupt(Player *other) {
    for (size_t i = 0; i < buildingsOwned.size(); i++) {
        other->buildingsOwned.push_back(buildingsOwned[i]);
    }
    buildingsOwned.clear();
}

void Player::assets() {
    for (auto b: buildingsOwned) {
        cout << "Building Name: " << b->getName() << "Building Value: " << b->getValue() << endl;
    }
}

void Player::trade (Player *other, int amount, const string &receiving) {
    if (money >= amount) {
        pay(amount);
        other->receive(amount);
        for (auto it = other->buildingsOwned.begin(); it != other->buildingsOwned.end(); ) {
            if ((*it)->getName() == receiving) {
                // Add the building pointer to our list.
                buildingsOwned.emplace_back(*it);
                // Erase from the other player's vector and update iterator.
                it = other->buildingsOwned.erase(it);
                return;
            } else {
                ++it;
            }
        }
    }
    cout << "Trade Failed, either insufficient funds or nonexistent/unowned Building" << endl; 

}

//overloaded trade function
void Player::trade(Player *other, const string &trading, const string &receiving) {
    vector<Building*>::iterator itTrading = buildingsOwned.end();
    for (std::vector<Building*>::iterator it = buildingsOwned.begin(); it != buildingsOwned.end(); ++it) {
        if ((*it)->getName() == trading) {
            itTrading = it;
            break;
        }
    }
    
    // Find the building named 'receiving' in the other player's buildingsOwned.
    std::vector<Building*>::iterator itReceiving = other->buildingsOwned.end();
    for (std::vector<Building*>::iterator it = other->buildingsOwned.begin(); it != other->buildingsOwned.end(); ++it) {
        if ((*it)->getName() == receiving) {
            itReceiving = it;
            break;
        }
    }
    
    // If both buildings were found, swap the pointers.
    if (itTrading != buildingsOwned.end() && itReceiving != other->buildingsOwned.end()) {
        std::swap(*itTrading, *itReceiving);
        std::cout << name << " traded " << trading << " for " << receiving 
                  << " with " << other->getName() << std::endl;
        return;
    }
    
    std::cout << "Trade failed, either insufficient funds or nonexistent/unowned Building" << std::endl;
}


//overloaded trade function
void Player::trade (Player *other, const string &receiving, int amount) {
    if (money >= amount) {
        pay(amount);
        other->receive(amount);
        for (auto it = other->buildingsOwned.begin(); it != other->buildingsOwned.end(); ) {
            if ((*it)->getName() == receiving) {
                // Add the building pointer to our list.
                buildingsOwned.push_back(*it);
                // Erase from the other player's vector and update iterator.
                it = other->buildingsOwned.erase(it);
                return;
            } else {
                ++it;
            }
        }
    }
    cout << "Trade Failed, either insufficient funds or nonexistent/unowned Building" << endl; 

}