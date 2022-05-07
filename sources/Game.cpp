//
// Created by eylon on 4/26/22.
//
#include "Game.hpp"
#include <stdexcept>

namespace coup{
    /**
     * this function returns the name of the player which is his turn
     * @return
     */
    std::string Game::turn(){
        return (this->curr_players[(uint)(this->player_turn)]);
    }

    /**
     * this function returns list of names of the players which are currently plays the game
     * this function goes through the players vector and adds to a new vector the names which dont have "_"
     * as a first letter
     * @return
     */
    std::vector<std::string> Game::players(){
        std::vector<std::string> curr_players_list;
        for(int i = 0; i < this->curr_players.size(); ++i){
            if(this->curr_players[(uint)(i)][0] != '_'){
                curr_players_list.push_back(this->curr_players[(uint)(i)]);
            }
        }
        return curr_players_list;
    }

    /**
     * this function returns the name of the player that won the game
     * this function goes through the vector of names and count the number of names which dont start with "_"
     * and keeps the index of the winner
     * if the counter is 1 and the flag that tells us whether the game has started is true, we return the name of the winner
     * else, it means the game is still on and we throw exception
     * @return
     */
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

    /**
     * this function is a helper function
     * this function calculates whose turn is it right now
     * it goes through the vector of names, and if the first char is "_" it keeps promoting the player_turn index until
     * it hits a regular name
     */
    void Game::whose_turn(){
        this->player_turn = (this->player_turn+1)%((int)(this->curr_players.size()));
        while(this->curr_players[(uint)(this->player_turn)][0] == '_'){
            this->player_turn = (this->player_turn+1)%((int)(this->curr_players.size()));
        }
    }
}