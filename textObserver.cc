export module textobserver;

import observer;
import player;
import square;
import <vector>;
using namespace std;

export class TextObserver : public Observer {
private:
    vector<Player*> players;
    vector<Square*> squares;

public:
    TextObserver(vector<Player*> players, vector<Square*> squares);
    void notify() override;
    ~TextObserver();
};
