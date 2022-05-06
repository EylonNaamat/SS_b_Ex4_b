//
// Created by eylon on 4/26/22.
//
#include "Game.hpp"
#include <stdexcept>

namespace coup{
    std::string Game::turn(){
        return (this->curr_players[(uint)(this->player_turn)]);
    }
    std::vector<std::string> Game::players(){
        std::vector<std::string> curr_players_list;
        for(int i = 0; i < this->curr_players.size(); ++i){
            if(this->curr_players[(uint)(i)][0] != '_'){
                curr_players_list.push_back(this->curr_players[(uint)(i)]);
            }
        }
        return curr_players_list;
    }
    std::string Game::winner(){
        int count = 0;
        int index_winner = 0;
        for(int i = 0; i < this->curr_players.size(); ++i){
            if(this->curr_players[(uint)(i)][0] != '_'){
                count++;
                index_winner = i;
            }
        }
        if(count != 1 || !this->game_has_started) {
            throw std::invalid_argument("game is still on!!!");
        }
        return this->curr_players[(uint)(index_winner)];
    }
    void Game::whose_turn(){
        this->player_turn = (this->player_turn+1)%((int)(this->curr_players.size()));
        while(this->curr_players[(uint)(this->player_turn)][0] == '_'){
            this->player_turn = (this->player_turn+1)%((int)(this->curr_players.size()));
        }
    }
}