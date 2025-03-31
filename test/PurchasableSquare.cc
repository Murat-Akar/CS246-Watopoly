#include "PurchasableSquare.h"
#include "Player.h"
#include "PropertyData.h"
#include <vector>

PurchasableSquare::PurchasableSquare(const string &name, int posn, int propertyValue, bool ownable,
    const string &monopolyblockId, int improvementLevels, Player *owner, bool mortgaged)
    : Square(name, posn, propertyValue, ownable),
      monopolyblockId(monopolyblockId),
      improvementLevels(improvementLevels),
      owner(owner),
      mortgaged(mortgaged) {
}

void PurchasableSquare::buy(Player *p) {
    if (owner == nullptr && p->getMoney() >= getRent()) {
        p->pay(getRent());
        owner = p;
        p->addBuilding(this);
        cout << p->getName() << " purchased " << getName() 
             << " for $" << getRent() << endl;
    }
    else if (owner != nullptr) {
        cout << "Sorry " << owner->getName() << " owns this." << endl;
    }
    else {
        cout << "Insufficient Funds For Purchase" << endl;
    }
}
void PurchasableSquare::setOwner(Player *new_owner) {
    owner = new_owner;
}

Player* PurchasableSquare::getOwner()  {
    return owner;
}

bool PurchasableSquare::landOn(Player *p) {
    if (owner == nullptr) {
        cout << p->getName() << " landed on " << getName() 
             << ". This property is unowned and costs $" << getRent() << ".\n";
        return true;
    }
    else if (owner != p) {
        if (mortgaged) {
            cout << p->getName() << " landed on " << getName() 
                 << ", but it is mortgaged. No rent is due.\n";
            return true;
        } else {
            const PropertyData* pd = PropertyData::lookup(getName());
            if (!pd) {
                cout << "Error: Property data not found for " << getName() << endl;
                return false;
            }
            int rent = 0;
            // Suppose if no improvements and not a monopoly, rent doubles.
            if (improvementLevels == 0 && !isMonopoly())
                rent = pd->rentTable[0] * 2;
            else
                rent = pd->rentTable[improvementLevels];
            cout << p->getName() << " must pay $" << rent 
                 << " in rent for " << getName() << ".\n";
            if (p->getMoney() <= rent) {
                cout << "You do not have enough funds to pay the owner you must raise funds by (mortgage/trade) or declare bankruptcy :<" << endl;
            }
            else {
                p->pay(rent);
                owner->receive(rent);
                return true;
            }
        }
    }
    else {
        cout << p->getName() << " landed on their own property " << getName() << ".\n";
        return true;
    }
    return false;
}

bool PurchasableSquare::isMonopoly() {
    int monopoly_amount = 0, owner_amount = 0;
    string square_tag = getMonopolyBlock();
    if (square_tag == "NONE" || square_tag == "GYM" || square_tag == "RESIDENCE") {
        return false;
    }
    const auto &pd = PropertyData::getAcademicData(); 
    for (auto it = pd.begin(); it != pd.end(); ++it) {
        if (it->second.monopolyblockID == square_tag) {
            ++monopoly_amount;
        }
    }
    for (auto it = owner->buildingsOwned.begin(); it != owner->buildingsOwned.end(); ++it) {
        PurchasableSquare *ps = dynamic_cast<PurchasableSquare*>(*it);
        if (ps && ps->getMonopolyBlock() == square_tag) {
            ++owner_amount;
        }
    }
    return (owner_amount == monopoly_amount && monopoly_amount > 0);
}


void PurchasableSquare::mortgage() {
    if (improvementLevels > 0) {
        cout << "You must sell improvements before mortgaging this property." << endl;
        return;
    }
    if (!mortgaged) {
        int mortgageValue = getRent() / 2;
        owner->receive(mortgageValue);
        mortgaged = true;
        cout << owner->getName() << " has mortgaged " << getName() 
             << " for $" << mortgageValue << endl;
    } else {
        cout << getName() << " is already mortgaged." << endl;
    }
}

void PurchasableSquare::unmortgage() {
    if (mortgaged) {
        int unmortgageCost = (getRent() * 60) / 100;
        if (owner->getMoney() >= unmortgageCost) {
            owner->pay(unmortgageCost);
            mortgaged = false;
            cout << owner->getName() << " has unmortgaged " << getName() 
                 << " by paying $" << unmortgageCost << endl;
        } else {
            cout << "Insufficient funds to unmortgage " << getName() << "." << endl;
        }
    } else {
        cout << getName() << " is not mortgaged." << endl;
    }
}

void PurchasableSquare::inc_improvementLevel(Player *p) {
    if ((monopolyblockId != "NONE" && monopolyblockId != "GYM" && monopolyblockId != "RESIDENCE") 
        && improvementLevels < 5 && isMonopoly()) {
        if (p == owner) {
            improvementLevels++;
            cout << getName() << " now has improvement level " << improvementLevels << ".\n";
        } else {
            cout << "You are not the owner of this square." << endl;
        }
    } else {
        cout << "Sorry, you do not own all the buildings in this monopoly block to improve it." << endl;
    }
}

void PurchasableSquare::dec_improvementLevel(Player *p) {
    if ((monopolyblockId != "NONE" && monopolyblockId != "GYM" && monopolyblockId != "RESIDENCE") 
        && improvementLevels > 0 && isMonopoly()) {
        if (p == owner) {
            improvementLevels--;
            cout << getName() << " now has improvement level " << improvementLevels << ".\n";
        } else {
            cout << "You are not the owner of this square." << endl;
        }
    } else {
        cout << "Sorry, you do not own all the buildings in this monopoly block to lower the improvement level." << endl;
    }
}

void PurchasableSquare::auction(vector<Player*>& players) {
    int currentBid = 0;
    Player* highestBidder = nullptr;
    vector<Player*> remainingPlayers = players;  // Players still participating in the auction
    
    cout << "Auction for " << getName() << " begins!" << endl;
    
    while (remainingPlayers.size() > 1) {
        for (auto it = remainingPlayers.begin(); it != remainingPlayers.end();) {
            Player* bidder = *it;
            cout << bidder->getName() << ", the current bid is $" << currentBid << ". Do you want to (b)id or (w)ithdraw? ";
            char choice;
            cin >> choice;
            
            if (choice == 'w' || choice == 'W') {
                cout << bidder->getName() << " withdrew from the auction." << endl;
                it = remainingPlayers.erase(it);  // Remove this player from the auction
            } else if (choice == 'b' || choice == 'B') {
                int totalBid;
                cout << "Enter your total bid (must be more than $" << currentBid << "): ";
                cin >> totalBid;
                
                // Ensure the bid is higher than the last bid and the player can afford it
                if (totalBid > currentBid && totalBid <= bidder->getMoney()) {
                    currentBid = totalBid;
                    highestBidder = bidder;
                    cout << bidder->getName() << " bid $" << currentBid << "." << endl;
                    ++it;  // Continue to the next player
                } else if (totalBid <= currentBid) {
                    cout << "Your bid must be higher than the current bid of $" << currentBid << "." << endl;
                } else {
                    cout << "Insufficient funds for this bid." << endl;
                }
            } else {
                cout << "Invalid choice. Please choose (b)id or (w)ithdraw." << endl;
            }
        }
    }

    // Auction ends when only one player is left
    if (highestBidder != nullptr) {
        cout << highestBidder->getName() << " wins the auction for " << getName() << " with a bid of $" << currentBid << "." << endl;
        highestBidder->pay(currentBid);  // Deduct the amount from the winner
        highestBidder->addBuilding(this);  // Transfer the property
    } else {
        cout << "No one bid. The property remains unowned." << endl;
    }
}
