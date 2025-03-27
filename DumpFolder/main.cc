#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "Player.h"
using namespace std;

int main() {
    srand(time(nullptr));
    
    // Create board squares.
    vector<Square*> board = createBoard();
    
    // Input players.
    cout << "Number of players: ";
    int numPlayers;
    cin >> numPlayers;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (numPlayers < 1) {
        cerr << "At least one player is required.\n";
        return 1;
    }
    vector<Player*> players;
    for (int i = 0; i < numPlayers; i++) {
        cout << "Player " << (i + 1) << " name: ";
        string nm;
        getline(cin, nm);
        if (nm.empty()) nm = "PLAYER" + to_string(i + 1);
        // Create the player with default money 1500, starting position 0, 0 tims cups, and not in Tims Line.
        players.push_back(new Player(nm, 1500, 0, 0, false));
    }
    
    // Initial board display.
    vector<string> finalDisplay = buildBoardDisplay(board, players);
    printBoardDisplay(finalDisplay);
    
    // Main game loop: each player's turn until "quit" is entered.
    bool done = false;
    int current = 0;
    while (!done) {
        Player *p = players[current];
        cout << p->getName() << "'s turn. (roll, next, quit): ";
        string cmd;
        cin >> cmd;
        if (cmd == "roll") {
            p->roll();
            // Use getPosn() instead of getPos()
            int sq = p->getPosn();
            board[sq]->landOn(p);
        } else if (cmd == "next") {
            // End turn.
        } else if (cmd == "quit") {
            done = true;
        } else {
            cout << "Unknown command.\n";
        }
        finalDisplay = buildBoardDisplay(board, players);
        printBoardDisplay(finalDisplay);
        current = (current + 1) % numPlayers;
    }
    
    cout << "Game Over!\n";
    for (auto s : board) delete s;
    for (auto p : players) delete p;
    return 0;
}
