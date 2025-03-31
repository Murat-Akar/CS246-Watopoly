#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <string>
#include "Player.h"
#include "Square.h"

void saveGameState(const std::vector<Player*>& players, const std::vector<Square*>& board, int currentPlayerIndex, const std::string &filename);

bool loadGameState(std::vector<Player*>& players, std::vector<Square*>& board, int &currentPlayerIndex, const std::string &filename);

#endif
