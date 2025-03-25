module textobserver;

import <iostream>;
import <string>;
import <vector>;
import player;
using namespace std;

TextObserver::TextObserver(std::vector<Player*> players, int width, int height)
    : players{move(players)}, width{width}, height{height} {
        
    for (auto* p : this->players) {
        p->attach(this);
    }
}

TextObserver::~TextObserver() {
    for (auto* p : players) {
        p->detach(this);
    }
}

void TextObserver::notify() {
    // Each square returns 5 lines
    const int linesPerSquare = 5;

    // -------- TOP ROW (squares 20 to 30) --------
    for (int line = 0; line < linesPerSquare; ++line) {
        for (int i = 20; i <= 30; ++i) {
            std::cout << squares[i]->print_square()[line];
        }
        std::cout << '\n';
    }

    // -------- MIDDLE 9 ROWS (LEFT and RIGHT columns) --------
    for (int row = 0; row < 9; ++row) {
        int leftIdx = 19 - row;
        int rightIdx = 31 + row;

        vector<string> leftLines = squares[leftIdx]->print_square();
        vector<string> rightLines = squares[rightIdx]->print_square();

        for (int line = 0; line < linesPerSquare; ++line) {
            cout << leftLines[line]
                      << string(63, ' ')  // space between left and right
                      << rightLines[line] << '\n';
        }
    }

    // -------- BOTTOM ROW (squares 10 to 0, right to left) --------
    for (int line = 0; line < linesPerSquare; ++line) {
        for (int i = 10; i >= 0; --i) {
            cout << squares[i]->print_square()[line];
        }
        cout << '\n';
    }
}

