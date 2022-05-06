//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include <string>
#pragma once

namespace coup{
    class Ambassador : public Player{
    public:
        Ambassador(coup::Game& game, std::string name) : Player(game, name){};
        ~Ambassador(){};
        void transfer(Player& player_a, Player& player_b);
        void block(Player& player);
        std::string role();
    };
}
