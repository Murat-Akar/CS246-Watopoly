#include "GameState.h"
#include <fstream>
#include <sstream>
#include "Player.h"
#include "PurchasableSquare.h"
#include <iostream>
using namespace std;

void saveGameState(const vector<Player*>& players, const vector<Square*>& board, int currentPlayerIndex, const string &filename) {
    ofstream out {filename};
    if (!out) {
        cerr << "Error: was not able to open file: " << filename << " for writing" << endl;
        return;
    }
    
    out << players.size() << endl;
    out << currentPlayerIndex << endl;
    for (auto it = players.begin(); it != players.end(); ++it) {
        // Assuming Tims Line is square 10.
        if ((*it)->getPosn() == 10) {
            out << (*it)->getName() << " " << (*it)->getPiece() << " " << (*it)->getTimsCupsVal()
                << " " << (*it)->getMoney() << " " << (*it)->getPosn() << " " << (*it)->getTimsLineTurns() << endl;
        }
        else {
            out << (*it)->getName() << " " << (*it)->getPiece() << " " << (*it)->getTimsCupsVal()
                << " " << (*it)->getMoney() << " " << (*it)->getPosn() << endl;
        }
    }
    for (auto it = board.begin(); it != board.end(); ++it) {
        PurchasableSquare *ps = dynamic_cast<PurchasableSquare *>((*it));
        if (ps) {
            string ownerName = (ps->getOwner() != nullptr) ? ps->getOwner()->getName() : "";
            out << ps->getName() << " " << ownerName << " " << ps->getImprovementLevels() << endl;
        }
    }
    out.close();
}


bool loadGameState(vector<Player*>& players, vector<Square*>& board, int &currentPlayerIndex, const string &filename) {
        ifstream in(filename);
        if (!in) {
            cerr << "Error: was not able to open file: " << filename << " for reading" << endl;
            return false;
        }
        
        // Read the number of players and the current player index.
        int numPlayers = 0;
        in >> numPlayers;
        in >> currentPlayerIndex;
        in.ignore(); // Consume the newline after reading currentPlayerIndex.
        
        // Clear any existing players.
        for (auto p : players) {
            delete p;
        }
        players.clear();
        
        // Load each player's data.
        for (int i = 0; i < numPlayers; i++) {
            string playerLine;
            getline(in, playerLine);
            if (playerLine.empty()) {
                // Skip empty lines.
                i--;
                continue;
            }
            istringstream pss(playerLine);
            string name;
            char piece;
            int timsCups, money, pos;
            int timsLineTurns = 0; // default if not in Tims Line
            
            pss >> name >> piece >> timsCups >> money >> pos;
            if (pos == 10) {
                pss >> timsLineTurns;
            }
            Player* p = new Player(name, piece, money, pos, timsCups, false);
            if (pos == 10) {
                p->setSentToTims(timsLineTurns);
                p->setSentToTims(true);
            }
            players.push_back(p);
        }
        
        string boardLine;
        while (getline(in, boardLine)) {
            if (boardLine.empty()) continue;
            istringstream bss(boardLine);
            string buildingName;
            string owner_name;  
            int impLevels;
            bss >> buildingName >> owner_name >> impLevels;
            for (Square* s : board) {
                PurchasableSquare* ps = dynamic_cast<PurchasableSquare*>(s);
                if (ps && ps->getName() == buildingName) {
                    ps->setImprovementLevels(impLevels);
                    Player *p1 = nullptr;
                    for (auto it = players.begin(); it != players.end(); ++it) {
                        if ((*it)->getName() == owner_name) {
                            p1 = *it;
                        }
                    }
                    ps->setOwner(p1); 
                }
            }
        }
        in.close();
        return true;
}
