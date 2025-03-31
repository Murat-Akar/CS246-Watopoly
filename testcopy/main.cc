Spruz
spruz2.0
Online
246 Project

Feltz — Yesterday at 9:19 PM
rolling 1 is 1/18 chance
Spruz — Yesterday at 9:20 PM
yea but wha about the other ones
Feltz — Yesterday at 9:20 PM
2 or 3 is 2/18 chance
Spruz — Yesterday at 9:20 PM
is this for needles hall
Feltz — Yesterday at 9:20 PM
yes
Spruz — Yesterday at 9:20 PM
oh yea
Feltz — Yesterday at 9:20 PM
it makes sense
Spruz — Yesterday at 9:20 PM
i see
ok good thats good
wanna work on auctions?
Feltz — Yesterday at 9:21 PM
im gonna make a change to the if blocks for both
Spruz — Yesterday at 9:21 PM
alr
Feltz — Yesterday at 9:21 PM
and then im gonna push it in test
is that fine
Spruz — Yesterday at 9:21 PM
alright
yea its for needleshall right
Feltz — Yesterday at 9:21 PM
yeah
Feltz — Yesterday at 9:22 PM
that or i was gonna look at mortgage bro
Feltz — Yesterday at 9:33 PM
okay its pushed
yo mortage or auction @Spruz
Spruz — Yesterday at 9:34 PM
mortgage should be fast
cus ur adding one more parameter
do that first and then
go on to auction
Feltz — Yesterday at 9:34 PM
oke
Spruz — Yesterday at 9:34 PM
working on bankrupt rn
gonna finish that and work on urs
then win
and then save/load commands
Feltz — Yesterday at 9:35 PM
ill let you know once im done with mortage and auction
Spruz — Yesterday at 9:35 PM
imma push ur folder back when im done
test adn see and then merge if possible
alr sounds good
how does bankrupt work
in the pdf it says they must declare bankruptcy
does that mean they have to call it themselves if they cant pay someone
Spruz — Yesterday at 9:43 PM
they need to mortgage/trade or declare bankrupty
if they dont have enough funds so make sure they have enough money in the actionsquares before making em pay
if they dont they dont pay yet 
NEED TO FIGURE OUT OF WAY TO TRACK IF THEY REACH ENOUGH MONEY TO CHARGE THEM
Feltz — Yesterday at 9:54 PM
Yeah it gives them the choice if they're have total assets 0
Spruz — Yesterday at 10:02 PM
yea
not just 0
if it is less than what they owe
Spruz — Yesterday at 10:09 PM
ok just pushed bankrupt
gonna work on urs rn
Feltz — Yesterday at 10:24 PM
Sam just to make sure you didn't add or start any code for mortgage anywhere right
Spruz — Yesterday at 10:25 PM
no i didnt do it
i think i figured ur think out btw
Feltz — Yesterday at 10:25 PM
okay bet you're cracked
mb for that i was cooked trying to figure it out in restaurant
bro btw
do they just receive the 50% and that's it
Image
like the whole point is just quick cash right
Spruz — Yesterday at 10:38 PM
bro you shouldve told me i wouldve took out ur hands didnt know u were eating
i wouldve given u something lighter
Spruz — Yesterday at 10:39 PM
yea
Feltz — Yesterday at 10:39 PM
It's fine I was trying so hard to get it done gonna eat when I'm home
I may work through the night
Spruz — Yesterday at 10:39 PM
but u need to test and see through the game
buy renting
and if someone mortgages if anything happens
Feltz — Yesterday at 10:40 PM
And btw someone has some code from mortgage in main.cc
Spruz — Yesterday at 10:40 PM
try not to add mroe fields for player and shi
Spruz — Yesterday at 10:40 PM
i added that
Feltz — Yesterday at 10:40 PM
I'm keeping for now
Spruz — Yesterday at 10:40 PM
just use that as a template u need to send a building name as a string to mortgage
Feltz — Yesterday at 10:42 PM
Alri
Professor — Yesterday at 10:48 PM
bros
anything i can help
?
how are we now?
Spruz — Yesterday at 10:49 PM
masood jusst pushed the directory
Spruz — Yesterday at 10:49 PM
did u finish the text display
if u finished, work on the auction and win method
if not just work on auction/win first and finish display later 
@Feltz
merge the code first
before doing mortgage
Feltz — Yesterday at 10:51 PM
You pushed testcopy right?
Spruz — Yesterday at 10:51 PM
yea
honestly think you shouldve done in same directory cus bro its gonna be so long 
to find all changes man
Feltz — Yesterday at 10:52 PM
Okay let me go through I took a screenshot of all the places where changes were made
Spruz — Yesterday at 10:52 PM
okok
thats good then
Feltz — Yesterday at 10:52 PM
Yeah I'm j getting home
Spruz — Yesterday at 10:52 PM
ok try asap this is vital
@Professor the auction will be done in the bankrupt() command in the main
acc no u can make a function for it somehow
maybe a helper in the same file
bruh i dont get why we have to do an auction for every player that doesnt buy a purchasableSquare
thats so stupid
its always gonna be a auction then
Feltz started a call. — 12:03 AM
Spruz — 12:08 AM
void auction (parameter) {

}

int main () {

bool player_buy = false;

if (player doesnt buy this turn) {
     auction()
}

if (bankrupt()) {
 auction()
}

}
main.cc
bool Player::roll_testing(int die1, int die2) {
    posn = (posn + (die1 + die2)) % 40;
    return true;
}
//bankrupt to another player
void Player::bankrupt(Player *other) {
    for(auto s : buildingsOwned)
        other->addBuilding(s);
    buildingsOwned.clear();
}

//bankrupt to the bank
void Player::bankrupt() {
    for (auto s : buildingsOwned) {
        PurchasableSquare *ps = static_cast<PurchasableSquare*>(s);
        ps->setOwner(nullptr);
    }
    buildingsOwned.clear();
}
Spruz — 12:21 AM
if (!canRoll) {
                    cout << "You have already rolled this turn. Please choose another command." << endl;
                } else {
                    oldPos = p->getPosn();
                    bool doubles = p->roll();
                    int newPos = p->getPosn();
Expand
message.txt
5 KB
Feltz — 12:29 AM
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "Player.h"
Expand
message.txt
22 KB
﻿
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "Player.h"
#include "Square.h"
#include "CollectOSAPSquare.h"
#include "CoopFeeSquare.h"
#include "NeedlesHallSquare.h"
#include "GooseNestingSquare.h"
#include "GoToTimsSquare.h"
#include "SLCSquare.h"
#include "TimsLineSquare.h"
#include "TuitionSquare.h"
#include "PurchasableSquare.h"
#include "Subject.h"
#include "TextObserver.h"
#include <unistd.h> // getpid
#include "PRNG.h"

using namespace std;

int totalCups = 0;

PRNG prng1, prng2, prng3; // global PRNG instances
extern PRNG prng1;        // declaration to use prng1 in another translation unit

/* TESTING HARNESS FOR ROLL
int d1, d2;
cout << "Enter Value Of First Die:";
cin >> d1;
cout << "\nEnter Value Of Second Die:" << endl;
cin >> d2;
bool doubles = p->roll_testing(d1, d2);
// END OF TESTING HARNESS FOR ROLL*/

int main(int argc, char* argv)
{
    // Randomize PRNG seeds.
    uint32_t seed = getpid();
    prng1.seed(seed);
    prng2.seed(seed);
    prng3.seed(seed);

    // Create players.
    vector<Player *> players;
    cout << "Enter the Number of Players (2 - 6): " << endl;
    int num_of_players = 0;
    string line;
    while (true)
    {
        getline(cin, line);
        stringstream ss(line);
        if (!(ss >> num_of_players) || !(ss >> ws).eof())
        {
            cout << "Invalid input. Please enter a number between 2 and 6: ";
            continue;
        }
        if (num_of_players >= 2 && num_of_players <= 6)
            break;
        else
            cout << "Please enter a number between 2 and 6: ";
    }

    for (int i = 0; i < num_of_players; ++i)
    {
        string name;
        cout << "Enter Player Name: ";
        getline(cin, name);
        if (name.empty())
        {
            name = "Player" + to_string(i + 1);
        }

        char piece;
        while (true)
        {
            cout << "Enter What Piece You'd Like To Be:" << endl;
            cout << "(Goose(G), GRT BUS(B), Tim Hortons Doughnut(D), Professor(P), Student(S), Money(M), Laptop(L), Pink Tie(T)):" << endl;
            string pieceStr;
            getline(cin, pieceStr);
            if (pieceStr.length() != 1)
            {
                cout << "Invalid piece. Please enter one of the allowed letters." << endl;
                continue;
            }
            piece = toupper(pieceStr[0]);
            if (piece != 'G' && piece != 'B' && piece != 'D' && piece != 'P' &&
                piece != 'S' && piece != 'M' && piece != 'L' && piece != 'T')
            {
                cout << "Invalid piece. Please enter one of the allowed letters." << endl;
                continue;
            }
            bool duplicate = false;
            for (auto *pl : players)
            {
                if (toupper(pl->getPiece()) == piece)
                {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate)
            {
                cout << "Someone has already chosen that piece, pick another :)" << endl;
            }
            else
            {
                break;
            }
        }
        players.emplace_back(new Player{name, piece, 1500, 0, 0, false});
    }

    // Create a board of 40 squares.
    vector<Square *> board(40, nullptr);
    board[0] = new CollectOSAPSquare(0, 200);
    board[1] = new PurchasableSquare("AL", 1, 40, true, "Arts1", 0, nullptr, false);
    board[2] = new SLCSquare(2);
    board[3] = new PurchasableSquare("ML", 3, 60, true, "Arts1", 0, nullptr, false);
    board[4] = new TuitionSquare(4, 300);
    board[5] = new PurchasableSquare("MKV", 5, 200, true, "None", 0, nullptr, false);
    board[6] = new PurchasableSquare("ECH", 6, 100, true, "Arts2", 0, nullptr, false);
    board[7] = new NeedlesHallSquare(7);
    board[8] = new PurchasableSquare("PAS", 8, 300, true, "Arts2", 0, nullptr, false);
    board[9] = new PurchasableSquare("HH", 9, 320, true, "Arts2", 0, nullptr, false);
    board[10] = new TimsLineSquare(10, 0);
    board[11] = new PurchasableSquare("RCH", 11, 140, true, "Eng", 0, nullptr, false);
    board[12] = new PurchasableSquare("PAC", 12, 150, true, "NONE", 0, nullptr, false);
    board[13] = new PurchasableSquare("DWE", 13, 140, true, "Eng", 0, nullptr, false);
    board[14] = new PurchasableSquare("CPH", 14, 150, true, "ENG", 0, nullptr, false);
    board[15] = new PurchasableSquare("UWP", 15, 200, true, "NONE", 0, nullptr, false);
    board[16] = new PurchasableSquare("LHI", 16, 180, true, "Health", 0, nullptr, false);
    board[17] = new SLCSquare(17);
    board[18] = new PurchasableSquare("BMH", 18, 180, true, "Health", 0, nullptr, false);
    board[19] = new PurchasableSquare("OPT", 19, 200, true, "Health", 0, nullptr, false);
    board[20] = new GooseNestingSquare(20, 0);
    board[21] = new PurchasableSquare("EV1", 21, 220, true, "Env", 0, nullptr, false);
    board[22] = new NeedlesHallSquare(22);
    board[23] = new PurchasableSquare("EV2", 23, 220, true, "Env", 0, nullptr, false);
    board[24] = new PurchasableSquare("EV3", 24, 220, true, "Env", 0, nullptr, false);
    board[25] = new PurchasableSquare("V1", 25, 200, true, "NONE", 0, nullptr, false);
    board[26] = new PurchasableSquare("PHYS", 26, 120, true, "Sci1", 0, nullptr, false);
    board[27] = new PurchasableSquare("B1", 27, 100, true, "Sci1", 0, nullptr, false);
    board[28] = new PurchasableSquare("CIF", 28, 150, true, "NONE", 0, nullptr, false);
    board[29] = new PurchasableSquare("B2", 29, 100, true, "Sci1", 0, nullptr, false);
    board[30] = new GoToTimsSquare(30);
    board[31] = new PurchasableSquare("EIT", 31, 300, true, "Sci2", 0, nullptr, false);
    board[32] = new PurchasableSquare("ESC", 32, 300, true, "Sci2", 0, nullptr, false);
    board[33] = new SLCSquare(33);
    board[34] = new PurchasableSquare("C2", 34, 320, true, "Sci2", 0, nullptr, false);
    board[35] = new PurchasableSquare("REV", 35, 200, true, "NONE", 0, nullptr, false);
    board[36] = new NeedlesHallSquare(36);
    board[37] = new PurchasableSquare("MC", 37, 350, true, "Math", 0, nullptr, false);
    board[38] = new CoopFeeSquare(38);
    board[39] = new PurchasableSquare("DC", 39, 400, true, "Math", 0, nullptr, false);

    TextObserver observer(players, board);

    bool gameOver = false;
    int currentPlayerIndex = 0;
    while (!gameOver)
    {
        bool command_loop = true;
        bool canRoll = true;
        int oldPos = 0;
        while (command_loop)
        {
            Player *p = players[currentPlayerIndex];
            cout << "\nAnyone can choose to (trade/mortgage/unmortgage) at anytime if resources allow. " << endl;
            cout << p->getName() << "'s turn. (roll/next/buy/assets/all/improvements/bankrupt/quit/save): ";
            string cmd;
            cin >> cmd;
            int pos = p->getPosn();
            if (cmd == "roll") {
                if (!canRoll) {
                    cout << "You have already rolled this turn. Please choose another command." << endl;
                } else {
                    oldPos = p->getPosn();
                    bool doubles = p->roll();
                    int newPos = p->getPosn();
                    cout << p->getName() << " (" << p->getPiece() << ") landed on " 
                         << board[newPos]->getName() << ".\n";
                    board[newPos]->landOn(p);
                    
                    // Check if the player is in DC Tims Line and was sent there.
                    if (p->getPosn() == 10 && p->isSentToTims()) {
                        p->incrementTimsLineTurns();
                        cout << p->getName() << " is in DC Tims Line (turn " 
                             << p->getTimsLineTurns() << " of 3)." << endl;
                        cout << p->getName() << ", what option would you like to use to get out of jail:" << endl;
                        cout << "1) Roll Doubles" << endl;
                        cout << "2) Pay $50" << endl;
                        cout << "3) Use Roll Up the Rim cup" << endl;
                        int code;
                        cin >> code;
                        bool break_out = false;
                        while (true && p->getTimsLineTurns() != 3) {
                            if (code == 1) {
                                bool d = p->roll();
                                if (d) {
                                    p->setSentToTims(false);
                                    p->resetTimsLineTurns();
                                    break_out = true;
                                    break;
                                } else {
                                    p->setPosition(10);
                                    cout << "You did not roll doubles." << endl;
                                    break;
                                }
                            }
                            if (code == 2) {
                                if (p->getMoney() >= 50) {
                                    p->pay(50);
                                    cout << p->getName() << " pays $50 to exit DC Tims Line." << endl;
                                    p->setSentToTims(false);
                                    p->resetTimsLineTurns();
                                    break_out = true;
                                    break;
                                } else {
                                    cout << "You do not have enough money. Please choose option 1 or 3." << endl;
                                }
                            }
                            if (code == 3) {
                                if (p->getTimsCupsVal() > 0) {
                                    p->useCup();
                                    cout << p->getName() << " uses a Roll Up the Rim cup." << endl;
                                    p->setSentToTims(false);
                                    p->resetTimsLineTurns();
                                    break_out = true;
                                    break;
                                } else {
                                    cout << "You do not have any Roll Up the Rim cups. Please choose option 1." << endl;
                                }
                            }
                            cout << "Invalid choice. Please try again: ";
                            cin >> code;
                        }
                        if (break_out) {
                            cout << p->getName() << " exits the DC Tims Line." << endl;
                        } else {
                            cout << p->getName() << " did not exit the DC Tims Line." << endl;
                        }
                    }
                    
                    // Award OSAP if the player passed or landed on OSAP.
                    if (!p->isSentToTims() && (newPos < oldPos || newPos == 0)) {
                        p->receive(200);
                        cout << p->getName() << " collects $200 from OSAP." << endl;
                    }
                    
                    if (!doubles) {
                        canRoll = false;
                    } else {
                        cout << "Doubles rolled! You may now roll again." << endl;
                    }
                }
            } else if (cmd == "buy") {
                PurchasableSquare *ps = dynamic_cast<PurchasableSquare *>(board[pos]);
                if (ps)
                {
                    ps->buy(p);
                }
                else
                {
                    cout << "This square is not purchasable." << endl;
                }
            } else if (cmd == "assets")
            {
                p->assets();
            }
            else if (cmd == "trade")
            {
                cout << "Enter your name (the one offering the trade): ";
                string traderName;
                cin >> traderName;
                cout << "Enter the name of the player you want to trade with: ";
                string accepterName;
                cin >> accepterName;
                Player *p1_trader = nullptr;
                Player *p2_accepter = nullptr;
                for (auto *pl : players)
                {
                    if (pl->getName() == traderName)
                        p1_trader = pl;
                    else if (pl->getName() == accepterName)
                        p2_accepter = pl;
                }
                if (!p1_trader || !p2_accepter)
                {
                    cout << "Could not find one of those players. Trade aborted." << endl;
                    continue;
                }
                cout << "Select the type of trade:\n"
                     << "  1) Money for Building\n"
                     << "  2) Building for Building\n"
                     << "  3) Building for Money\n"
                     << "Enter choice: ";
                int code;
                cin >> code;
                if (code == 1)
                {
                    cout << "How much money is " << traderName << " offering? ";
                    int amount;
                    cin >> amount;
                    cout << "Which building does " << accepterName << " own that you want to receive? ";
                    string buildingName;
                    cin >> buildingName;
                    cout << accepterName << ", do you accept this trade? (1 = yes, 2 = no): ";
                    int acceptCode;
                    cin >> acceptCode;
                    if (acceptCode == 1)
                    {
                        p1_trader->trade(p2_accepter, amount, buildingName);
                    }
                    else
                    {
                        cout << accepterName << " did not accept the trade." << endl;
                    }
                }
                else if (code == 2)
                {
                    cout << "Enter the building name that " << traderName << " is offering: ";
                    string buildingOffered;
                    cin >> buildingOffered;
                    cout << "Enter the building name that " << accepterName << " is offering: ";
                    string buildingWanted;
                    cin >> buildingWanted;
                    cout << accepterName << ", do you accept this trade? (1 = yes, 2 = no): ";
                    int acceptCode;
                    cin >> acceptCode;
                    if (acceptCode == 1)
                    {
                        p1_trader->trade(p2_accepter, buildingOffered, buildingWanted);
                    }
                    else
                    {
                        cout << accepterName << " did not accept the trade." << endl;
                    }
                }
                else if (code == 3)
                {
                    cout << "Enter the building name that " << traderName << " wants to give: ";
                    string buildingOffered;
                    cin >> buildingOffered;
                    cout << "How much money do you want from " << accepterName << " in return? ";
                    int amount;
                    cin >> amount;
                    cout << accepterName << ", do you accept this trade? (1 = yes, 2 = no): ";
                    int acceptCode;
                    cin >> acceptCode;
                    if (acceptCode == 1)
                    {
                        p1_trader->trade(p2_accepter, buildingOffered, amount);
                    }
                    else
                    {
                        cout << accepterName << " did not accept the trade." << endl;
                    }
                }
                else
                {
                    cout << "Unknown trade type." << endl;
                }
            }
            else if (cmd == "all") {
                if (board[pos]->getName() == "TUITION") {
                    cout << "This command does not function on this square" << endl;
                }
                else {
                    for (auto it = players.begin(); it != players.end(); it++) {
                        cout << (*it)->getName() << " assets are:" << endl;
                        (*it)->assets();
                    }
                }
            }
            else if (cmd == "mortgage")
            {
                string piece, building;
                Player *mortgaging_player = nullptr;
                cout << "Enter the piece of the player mortgaging: ";
                cin >> piece;
                cout << "Enter the Building Name: ";
                cin >> building;
                for (auto *pl : players)
                {
                    if (pl->getPiece() == toupper(piece[0]))
                    {
                        mortgaging_player = pl;
                        break;
                    }
                }
                if (mortgaging_player)
                {
                    // Uncomment and implement mortgage logic here:
                    // mortgaging_player->mortgage(building);
                }
            }
            else if (cmd == "unmortgage")
            {
                string piece, building;
                Player *unmortgaging_player = nullptr;
                cout << "Enter the piece of the player that is unmortgaging: ";
                cin >> piece;
                cout << "Enter the Building Name: ";
                cin >> building;
                for (auto *pl : players)
                {
                    if (pl->getPiece() == toupper(piece[0]))
                    {
                        unmortgaging_player = pl;
                        break;
                    }
                }
                if (unmortgaging_player)
                {
                    // Uncomment and implement unmortgage logic here:
                    // unmortgaging_player->unmortgage(building);
                }
            }
            else if (cmd == "improvements")
            {
                PurchasableSquare *ps = dynamic_cast<PurchasableSquare *>(board[pos]);
                if (ps)
                {
                    while (true)
                    {
                        cout << "Select the Type Of Improvement You Would Like:\n"
                             << "1) Add Improvement\n"
                             << "2) Remove Improvement\n"
                             << "Enter Choice: ";
                        int code;
                        cin >> code;
                        if (code == 1)
                        {
                            ps->inc_improvementLevel(p);
                            break;
                        }
                        else if (code == 2)
                        {
                            ps->dec_improvementLevel(p);
                            break;
                        }
                        else
                        {
                            cout << "Invalid Option, Please Choose Again!" << endl;
                        }
                    }
                }
                else
                {
                    cout << "This is not an improvable square" << endl;
                }
            }
            else if (cmd == "bankrupt") {
                PurchasableSquare *ps = dynamic_cast<PurchasableSquare*>(board[pos]);
                if (ps) {
                        if (ps->getOwner() == p) {
                            p->bankrupt();
                            players.erase(players.begin() + currentPlayerIndex);
                            cout << p->getName() << " is now out of the game and the Bank has taken all of their assets" << endl;
                        }
                        else {
                            p->bankrupt(ps->getOwner());
                            players.erase(players.begin() + currentPlayerIndex);
                            cout << p->getName() << " is now out of the game and " << ps->getOwner() << " has take all of their assets" << endl;
                        }
                }
             }
            else if (cmd == "next")
            {
                command_loop = false;
            }
            else if (cmd == "quit")
            {
                command_loop = false;
                gameOver = true;
                cout << "Game Over!" << endl;
                continue;
            }
            else
            {
                cout << "Unknown command." << endl;
            }
            cout << " " << setfill('_') << setw(98) << "_" << endl;
            observer.notify();
        }
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    for (Square *s : board)
        delete s;
    for (Player *p : players)
        delete p;

    return 0;
}