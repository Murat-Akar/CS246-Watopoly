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
#include <unistd.h>  // getpid
#include "PRNG.h"

using namespace std;

static int totalCups = 0;

PRNG prng1, prng2, prng3;  // global PRNG instances
extern PRNG prng1;         // declaration to use prng1 in another translation unit

int main() {
    // Randomize PRNG seeds.
    uint32_t seed = getpid();
    prng1.seed(seed);
    prng2.seed(seed);
    prng3.seed(seed);

    // Create players.
    vector<Player*> players;
    cout << "Enter the Number of Players (2 - 6): " << endl;
    int num_of_players = 0;
    string line;
    while (true) {
        getline(cin, line);
        stringstream ss(line);
        if (!(ss >> num_of_players) || !(ss >> ws).eof()) {
            cout << "Invalid input. Please enter a number between 2 and 6: ";
            continue;
        }
        if (num_of_players >= 2 && num_of_players <= 6)
            break;
        else
            cout << "Please enter a number between 2 and 6: ";
    }

    for (int i = 0; i < num_of_players; ++i) {
        string name;
        cout << "Enter Player Name: ";
        getline(cin, name);
        if (name.empty()) {
            name = "Player" + to_string(i + 1);
        }
        
        char piece;
        while (true) {
            cout << "Enter What Piece You'd Like To Be:" << endl;
            cout << "(Goose(G), GRT BUS(B), Tim Hortons Doughnut(D), Professor(P), Student(S), Money(M), Laptop(L), Pink Tie(T)):" << endl;
            string pieceStr;
            getline(cin, pieceStr);
            if (pieceStr.length() != 1) {
                cout << "Invalid piece. Please enter one of the allowed letters." << endl;
                continue;
            }
            piece = toupper(pieceStr[0]);
            if (piece != 'G' && piece != 'B' && piece != 'D' && piece != 'P' &&
                piece != 'S' && piece != 'M' && piece != 'L' && piece != 'T') {
                cout << "Invalid piece. Please enter one of the allowed letters." << endl;
                continue;
            }
            bool duplicate = false;
            for (auto *pl : players) {
                if (toupper(pl->getPiece()) == piece) {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate) {
                cout << "Someone has already chosen that piece, pick another :)" << endl;
            } else {
                break;
            }
        }
        players.emplace_back(new Player{name, piece, 1500, 0, 0, false});
    }

    // Create a board of 40 squares.
    vector<Square*> board(40, nullptr);
    board[0]  = new CollectOSAPSquare(0, 200);
    board[1]  = new PurchasableSquare("AL", 1, 40, true, "Arts1", 0, nullptr, false);
    board[2]  = new SLCSquare(2);
    board[3]  = new PurchasableSquare("ML", 3, 60, true, "Arts1", 0, nullptr, false);
    board[4]  = new TuitionSquare(4, 300);
    board[5]  = new PurchasableSquare("MKV", 5, 200, true, "None", 0, nullptr, false);
    board[6]  = new PurchasableSquare("ECH", 6, 100, true, "Arts2", 0, nullptr, false);
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
    board[26]  = new PurchasableSquare("PHYS", 26, 120, true, "Sci1", 0, nullptr, false);
    board[27]  = new PurchasableSquare("B1", 27, 100, true, "Sci1", 0, nullptr, false);
    board[28] = new PurchasableSquare("CIF", 28, 150, true, "NONE", 0, nullptr, false);
    board[29]  = new PurchasableSquare("B2", 29, 100, true, "Sci1", 0, nullptr, false);
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
    while (!gameOver) {
        bool command_loop = true;
        bool canRoll = true;
        while (command_loop) {
            Player *p = players[currentPlayerIndex];
            cout << "\nAnyone can choose to (trade/mortgage/unmortgage) at anytime if resources allow. " << endl;
            cout << p->getName() << "'s turn. (roll/next/buy/assets/improvements/quit): ";
            string cmd;
            cin >> cmd;
            int pos = p->getPosn();
            if (cmd == "roll") {
                if (!canRoll) {
                    cout << "You have already rolled this turn. Please choose another command." << endl;
                } else {
                    //TESTING HARNESS FOR ROLL
                    int d1,d2;
                    cout << "Enter Value Of First Die:";
                    cin >> d1;
                    cout << "\nEnter Value Of Second Die:" << endl;
                    cin >> d2;
                    bool doubles = p->roll_testing(d1,d2);
                    // END OF TESTING HARNESS FOR ROLL
                    
                    // bool doubles = p->roll();
                    pos = p->getPosn();
                    cout << p->getName() << " (" << p->getPiece() << ") landed on square " 
                         << board[pos]->getName() << ".\n";
                    board[pos]->landOn(p);
                    if (!doubles) {
                        canRoll = false;
                    } else {
                        cout << "Doubles rolled! You may roll again." << endl;
                    }
                }
            } else if (cmd == "buy") {
                PurchasableSquare *ps = dynamic_cast<PurchasableSquare*>(board[pos]);
                if (ps) {
                    ps->buy(p);
                } else {
                    cout << "This square is not purchasable." << endl;
                }
            } else if (cmd == "assets") {
                p->assets();
            } else if (cmd == "trade") {
                cout << "Enter your name (the one offering the trade): ";
                string traderName;
                cin >> traderName;
                cout << "Enter the name of the player you want to trade with: ";
                string accepterName;
                cin >> accepterName;
                Player *p1_trader = nullptr;
                Player *p2_accepter = nullptr;
                for (auto *pl : players) {
                    if (pl->getName() == traderName)
                        p1_trader = pl;
                    else if (pl->getName() == accepterName)
                        p2_accepter = pl;
                }
                if (!p1_trader || !p2_accepter) {
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
                if (code == 1) {
                    cout << "How much money is " << traderName << " offering? ";
                    int amount;
                    cin >> amount;
                    cout << "Which building does " << accepterName << " own that you want to receive? ";
                    string buildingName;
                    cin >> buildingName;
                    cout << accepterName << ", do you accept this trade? (1 = yes, 2 = no): ";
                    int acceptCode;
                    cin >> acceptCode;
                    if (acceptCode == 1) {
                        p1_trader->trade(p2_accepter, amount, buildingName);
                    } else {
                        cout << accepterName << " did not accept the trade." << endl;
                    }
                } else if (code == 2) {
                    cout << "Enter the building name that " << traderName << " is offering: ";
                    string buildingOffered;
                    cin >> buildingOffered;
                    cout << "Enter the building name that " << accepterName << " is offering: ";
                    string buildingWanted;
                    cin >> buildingWanted;
                    cout << accepterName << ", do you accept this trade? (1 = yes, 2 = no): ";
                    int acceptCode;
                    cin >> acceptCode;
                    if (acceptCode == 1) {
                        p1_trader->trade(p2_accepter, buildingOffered, buildingWanted);
                    } else {
                        cout << accepterName << " did not accept the trade." << endl;
                    }
                } else if (code == 3) {
                    cout << "Enter the building name that " << traderName << " wants to give: ";
                    string buildingOffered;
                    cin >> buildingOffered;
                    cout << "How much money do you want from " << accepterName << " in return? ";
                    int amount;
                    cin >> amount;
                    cout << accepterName << ", do you accept this trade? (1 = yes, 2 = no): ";
                    int acceptCode;
                    cin >> acceptCode;
                    if (acceptCode == 1) {
                        p1_trader->trade(p2_accepter, buildingOffered, amount);
                    } else {
                        cout << accepterName << " did not accept the trade." << endl;
                    }
                } else {
                    cout << "Unknown trade type." << endl;
                }
            } else if (cmd == "mortgage") {
                string piece, building;
                Player *mortgaging_player = nullptr;
                cout << "Enter the piece of the player mortgaging: ";
                cin >> piece;
                cout << "Enter the Building Name: ";
                cin >> building;
                for (auto *pl : players) {
                    if (pl->getPiece() == toupper(piece[0])) {
                        mortgaging_player = pl;
                        break;
                    }
                }
                if (mortgaging_player) {
                    // Uncomment and implement mortgage logic here:
                    // mortgaging_player->mortgage(building);
                }
            } else if (cmd == "unmortgage") {
                string piece, building;
                Player *unmortgaging_player = nullptr;
                cout << "Enter the piece of the player that is unmortgaging: ";
                cin >> piece;
                cout << "Enter the Building Name: ";
                cin >> building;
                for (auto *pl : players) {
                    if (pl->getPiece() == toupper(piece[0])) {
                        unmortgaging_player = pl;
                        break;
                    }
                }
                if (unmortgaging_player) {
                    // Uncomment and implement unmortgage logic here:
                    // unmortgaging_player->unmortgage(building);
                }
            } else if (cmd == "improvements") {
                PurchasableSquare *ps = dynamic_cast<PurchasableSquare*>(board[pos]);
                if (ps) {
                    while (true) {
                        cout << "Select the Type Of Improvement You Would Like:\n"
                             << "1) Add Improvement\n"
                             << "2) Remove Improvement\n"
                             << "Enter Choice: ";
                        int code;
                        cin >> code;
                        if (code == 1) {
                            ps->inc_improvementLevel(p);
                            break;
                        } else if (code == 2) {
                            ps->dec_improvementLevel(p);
                            break;
                        } else {
                            cout << "Invalid Option, Please Choose Again!" << endl;
                        }
                    }
                } else {
                    cout << "This is not an improvable square" << endl;
                }
            } else if (cmd == "next") {
                command_loop = false;
            } else if (cmd == "quit") {
                command_loop = false;
                gameOver = true;
                cout << "Game Over!" << endl;
                continue;
            } else {
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
