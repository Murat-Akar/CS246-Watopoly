#ifndef TEXTOBSERVER_H
#define TEXTOBSERVER_H

#include "Observer.h"
#include "Player.h"
#include "Square.h"
#include <vector>
using namespace std;

class TextObserver : public Observer {
private:
    vector<Player*> players;
    vector<Square*> squares;
public:
    TextObserver(const vector<Player*>& players, const vector<Square*>& squares);
    virtual void notify() override;
    virtual ~TextObserver();
};

#endif
