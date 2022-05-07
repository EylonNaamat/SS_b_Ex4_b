//
// Created by eylon on 4/26/22.
//
#include <vector>
#include <string>
#pragma once
namespace coup{
    class Game{
    public:
        std::vector<std::string> curr_players;
        int player_turn; // the index of player which is his turn to play
        const static int min_players = 2;
        const static int max_players = 6;
        bool game_has_started; // a flag which tells us whether the game has started or not
        int num_players;
    public:
        Game(){
            this->player_turn = 0;
            this->num_players = 0;
            this->game_has_started = false;
        }
        ~Game(){};
        std::string turn();
        std::vector<std::string> players();
        std::string winner();
        void whose_turn();
    };
}
