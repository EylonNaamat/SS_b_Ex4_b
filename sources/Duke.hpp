//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include <string>
#pragma once

namespace coup{
    class Duke : public Player{
    public:
        Duke(coup::Game& game, std::string name): Player(game, name){};
        ~Duke(){};
        void tax();
        void block(Player& player);
        std::string role();
    };
}
