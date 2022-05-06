//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include <string>
#pragma once

namespace coup{
    class Captain : public Player{
    public:
        Captain(coup::Game& game, std::string name): Player(game, name){};
        ~Captain(){};
        void steal(Player& player);
        void block(Player& player);
        std::string role();
    };
}
