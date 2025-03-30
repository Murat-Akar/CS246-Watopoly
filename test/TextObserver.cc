#include "TextObserver.h"
#include "Square.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

TextObserver::TextObserver(const vector<Player*>& players, const vector<Square*>& squares)
    : players(players), squares(squares) {
    for (auto p : this->players) {
        p->attach(this);
    }
}

TextObserver::~TextObserver() {
    for (auto p : players) {
        p->detach(this);
    }
}

void TextObserver::notify() {
    const int linesPerSquare = 5;
    // Print top row (squares 20 to 30)
    for (int line = 0; line < linesPerSquare; ++line) {
        for (int i = 20; i <= 30; ++i) {
            vector<string> squareLines = squares[i]->print_square(players);
            cout << squareLines[line];
        }
        cout << '\n';
    }
    // Print middle rows (left and right columns)
    for (int row = 0; row < 9; ++row) {
        int leftIdx = 19 - row;
        int rightIdx = 31 + row;

        vector<string> leftLines = squares[leftIdx]->print_square(players);
        vector<string> rightLines = squares[rightIdx]->print_square(players);

        // Print each line for left and right columns
        for (int line = 0; line < linesPerSquare; ++line) {
            cout << leftLines[line];
            if (line == linesPerSquare - 1 && row == 8) {
                cout << string(81, '_');
            } else {
                cout << string(81, ' ');
            }
            cout << rightLines[line] << '\n';
        }

    }
    
    // Print bottom row (squares 10 to 0, right-to-left)
    for (int line = 0; line < linesPerSquare; ++line) {
        for (int i = 10; i >= 0; --i) {
            // Print the 4th line with player initials if a player is on that square
            vector<string> squareLines = squares[i]->print_square(players);  // Pass players to print_square
            cout << squareLines[line];
        }
        cout << '\n';
    }
}
