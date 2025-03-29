#include <iostream>
#include <vector>
#include <string>
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

using namespace std;

static int totalCups = 0;

int main() {
    // Create players.
    vector<Player*> players;
    cout << "Enter the Number of Players (2 - 6): " << endl;
    int num_of_players = 0;
    while (true) {
        if (!(cin >> num_of_players)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a number between 2 and 6: ";
            continue;
        }
        if (num_of_players >= 2 && num_of_players <= 6) {
            break;
        } else {
            cout << "Please enter a number between 2 and 6: ";
        }
    }
    cin.ignore();

    for (int i = 0; i < num_of_players; ++i) {
        string name;
        cout << "Enter Player Name: ";
        getline(cin, name);
        if (name.empty()) {
            name = "Player" + to_string(i + 1);
        }
        
        char piece;
        while (true) {
            cout << "Enter What Piece You'd Like To Be: "
                 << "(Goose(G), GRT BUS(B), Tim Hortons Doughnut(D), "
                 << "Professor(P), Student(S), Money(M), Laptop(L), Pink Tie(T)):" << endl;
            cin >> piece;
            cin.ignore();
            
            bool duplicate = false;
            for (auto *pl : players) {
                if (pl->getPiece() == piece) {
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
    board[5]  = new PurchasableSquare("ECH", 5, 100, true, "Arts2", 0, nullptr, false);
    board[6]  = new GooseNestingSquare(6, 0);
    board[7]  = new PurchasableSquare("B1", 7, 100, true, "Arts1", 0, nullptr, false);
    board[8]  = new PurchasableSquare("B2", 8, 100, true, "Arts1", 0, nullptr, false);
    board[9]  = new PurchasableSquare("PHYS", 9, 120, true, "Arts1", 0, nullptr, false);
    board[10] = new TimsLineSquare(10, 0);
    board[11] = new PurchasableSquare("RCH", 11, 140, true, "Eng", 0, nullptr, false);
    board[12] = new NeedlesHallSquare(12);
    board[13] = new SLCSquare(13);
    board[14] = new SLCSquare(14);
    board[15] = new PurchasableSquare("LHI", 15, 180, true, "Health", 0, nullptr, false);
    board[16] = new PurchasableSquare("BMH", 16, 180, true, "Health", 0, nullptr, false);
    board[17] = new PurchasableSquare("OPT", 17, 200, true, "Health", 0, nullptr, false);
    board[18] = new GooseNestingSquare(18, 0);
    board[19] = new PurchasableSquare("EV1", 19, 220, true, "Env", 0, nullptr, false);
    board[20] = new SLCSquare(20);
    board[21] = new PurchasableSquare("EV2", 21, 220, true, "Env", 0, nullptr, false);
    board[22] = new SLCSquare(22);
    board[23] = new PurchasableSquare("EIT", 23, 300, true, "Sci2", 0, nullptr, false);
    board[24] = new PurchasableSquare("ESC", 24, 300, true, "Sci2", 0, nullptr, false);
    board[25] = new PurchasableSquare("C2", 25, 320, true, "Sci2", 0, nullptr, false);
    board[26] = new SLCSquare(26);
    board[27] = new PurchasableSquare("MC", 27, 350, true, "Math", 0, nullptr, false);
    board[28] = new PurchasableSquare("DC", 28, 400, true, "Math", 0, nullptr, false);
    board[29] = new PurchasableSquare("PAC", 29, 150, true, "NONE", 0, nullptr, false);
    board[30] = new GoToTimsSquare(30);
    board[31] = new CoopFeeSquare(31);
    board[32] = new PurchasableSquare("UWP", 32, 200, true, "NONE", 0, nullptr, false);
    board[33] = new SLCSquare(33);
    board[34] = new PurchasableSquare("REV", 34, 200, true, "NONE", 0, nullptr, false);
    board[35] = new PurchasableSquare("CIF", 35, 150, true, "NONE", 0, nullptr, false);
    board[36] = new PurchasableSquare("V1", 36, 200, true, "NONE", 0, nullptr, false);
    board[37] = new SLCSquare(37);
    board[38] = new PurchasableSquare("B2", 38, 100, true, "Arts1", 0, nullptr, false);
    board[39] = new SLCSquare(39);

    TextObserver observer(players, board);

    bool gameOver = false;
    int currentPlayerIndex = 0;
    while (!gameOver) {
        bool command_loop = true;
        bool roll = true;
        while (command_loop) {
            Player *p = players[currentPlayerIndex];
            cout << "\n" << p->getName() << "'s turn. (roll/next/buy/assets/trade/quit): ";
            string cmd;
            cin >> cmd;
            int pos = p->getPosn();

            if (cmd == "roll" && roll) {
                roll = false;
                p->roll();
                pos = p->getPosn();
                cout << p->getName() << " (" << p->getPiece() << ") landed on square "
                     << pos << ".\n";
                board[pos]->landOn(p);

            } else if (cmd == "buy") {
                PurchasableSquare *ps = dynamic_cast<PurchasableSquare*>(board[pos]);
                if (ps) {
                    ps->buy(p);
                } else {
                    cout << "This square is not purchasable.\n";
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

                // Find the two players
                for (auto *pl : players) {
                    if (pl->getName() == traderName) {
                        p1_trader = pl;
                    } else if (pl->getName() == accepterName) {
                        p2_accepter = pl;
                    }
                }

                if (!p1_trader || !p2_accepter) {
                    cout << "Could not find one of those players. Trade aborted.\n";
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
                    // Money for Building
                    cout << "How much money is " << traderName << " offering? ";
                    int amount;
                    cin >> amount;

                    cout << "Which building does " << accepterName << " own that you want to receive? ";
                    string buildingName;
                    cin >> buildingName;

                    // Ask if accepterName accepts
                    cout << accepterName << ", do you accept this trade? (1 = yes, 2 = no): ";
                    int acceptCode;
                    cin >> acceptCode;
                    if (acceptCode == 1) {
                        // money for building => p1_trader->trade(p2_accepter, amount, buildingName);
                        p1_trader->trade(p2_accepter, amount, buildingName);
                    } else {
                        cout << accepterName << " did not accept the trade.\n";
                    }

                } else if (code == 2) {
                    // Building for Building
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
                        // building for building => p1_trader->trade(p2_accepter, buildingOffered, buildingWanted);
                        p1_trader->trade(p2_accepter, buildingOffered, buildingWanted);
                    } else {
                        cout << accepterName << " did not accept the trade.\n";
                    }

                } else if (code == 3) {
                    // Building for Money
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
                        // building for money => p1_trader->trade(p2_accepter, buildingOffered, amount);
                        p1_trader->trade(p2_accepter, buildingOffered, amount);
                    } else {
                        cout << accepterName << " did not accept the trade.\n";
                    }

                } else {
                    cout << "Unknown trade type.\n";
                }

            } else if (cmd == "next") {
                // End current turn.
                command_loop = false;

            } else if (cmd == "quit") {
                command_loop = false;
                gameOver = true;
                cout << "Game Over!\n";
                continue;

            } else {
                cout << "Unknown command." << endl;
            }

            cout << " " << setfill('_') << setw(98) << "_" << endl;
            observer.notify();
        }
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    // Cleanup
    for (Square *s : board) {
        delete s;
    }
    for (Player *p : players) {
        delete p;
    }

    return 0;
}
