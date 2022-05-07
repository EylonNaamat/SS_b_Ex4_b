//
// Created by eylon on 4/26/22.
//
#include <string>
#include "Game.hpp"
#include <stdexcept>
#pragma once
namespace coup{
    class Player{
    public:
        std::string name; // holds the name of the player
        coup::Game* game; // a pointer to the game
        int num_coins; // number of coins the player have
        Player* stole_from; // the player which the curr player stole coins from (only for captains)
        std::string eliminated_player;
        std::string last_operation; // holds the last operation the player made
        const static int max_coins = 10;
        const static int coup_coins = 7;
    public:
        Player(coup::Game& game, std::string name){
            this->name = name;
            this->game = &game;
            if(this->game->num_players >= coup::Game::max_players){
                throw std::invalid_argument("cant have more than 6 players!!!");
            }
            if(this->game->game_has_started){
                throw std::invalid_argument("game already started, cant add players mid game!!!");
            }
            this->game->num_players++;
            this->game->curr_players.push_back(name);
            this->num_coins = 0;
            this->eliminated_player = "";
            this->stole_from = NULL;
            this->last_operation = "";
        }
        void income();
        void foreign_aid();
        virtual void coup(Player& player);
        virtual std::string role();
        int coins() const;
        bool is_in_the_game(Player& player) const;
        void is_num_players_legal() const;
        bool start_game() const;
    };
}
