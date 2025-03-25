module textobserver;
import <iostream>;
import <string>;
using namespace std;

TextObserver::TextObserver(vector<Player*> players, vector<Square*> squares)
    : players{move(players)}, squares{move(squares)} {
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
    const int linesPerSquare = 5;

    // -------- TOP ROW (squares 20 to 30) --------
    for (int line = 0; line < linesPerSquare; ++line) {
        for (int i = 20; i <= 30; ++i) {
            cout << squares[i]->print_square()[line];
        }
        cout << '\n';
    }

    // -------- MIDDLE 9 ROWS (LEFT and RIGHT columns) --------
    for (int row = 0; row < 9; ++row) {
        int leftIdx = 19 - row;
        int rightIdx = 31 + row;

        vector<string> leftLines = squares[leftIdx]->print_square();
        vector<string> rightLines = squares[rightIdx]->print_square();

        for (int line = 0; line < linesPerSquare; ++line) {
            cout << leftLines[line]
                 << string(63, ' ')
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


