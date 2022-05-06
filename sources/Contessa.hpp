//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include <string>
#pragma once

namespace coup{
    class Contessa : public Player{
    public:
        Contessa(coup::Game& game, std::string name): Player(game, name){};
        ~Contessa(){};
        void block(Player& player);
        std::string role();
    };
}
