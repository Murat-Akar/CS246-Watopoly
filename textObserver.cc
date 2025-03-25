export module textobserver;

import observer;
import player;
import <vector>;
using namespace std;

export class TextObserver : public Observer {
  private:
    vector<Player*> players;
    int width;
    int height;

  public:
    TextObserver(vector<Player*> players, int width, int height);
    void notify() override;
    ~TextObserver();
};
