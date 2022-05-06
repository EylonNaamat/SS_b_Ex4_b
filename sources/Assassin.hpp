//
// Created by eylon on 4/26/22.
//

#include "Player.hpp"
#include <string>
#pragma once

namespace coup{
    class Assassin : public Player{
    public:
        const static int assassin_coup_coins = 3;
    public:
        Assassin(coup::Game& game, std::string name): Player(game, name){};
        ~Assassin(){};
        void coup(Player& player);
        std::string role();
    };
}
