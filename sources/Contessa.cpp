//
// Created by eylon on 4/26/22.
//
#include "Contessa.hpp"
#include <iostream>
namespace coup{
    void Contessa::block(Player& player){
        is_num_players_legal();
        start_game();
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(!is_in_the_game(player)){
            throw std::invalid_argument("the player not in the game!!!");
        }
        if(player.last_operation != "assassin_coup"){
            throw std::invalid_argument("cant block this operation!!!");
        }
        if(this->game->turn() == player.name){
            throw std::invalid_argument("cant block him its his turn!!!");
        }
        bool flag_worked = false;
//        std::cout << this->game->curr_players.size() << std::endl;
        for(int i = 0; i < this->game->curr_players.size(); ++i){
            std::string tmp = this->game->curr_players[(uint)(i)];
            tmp.erase(0, 1);
            if(tmp == player.eliminated_player){
                this->game->curr_players[(uint)(i)] = player.eliminated_player;
                flag_worked = true;
                this->game->num_players++;
            }
//            std::cout << "1." << player.eliminated_player << std::endl;
//            std::cout << "2." << tmp << std::endl;
//            std::cout << "3." << this->game->curr_players[(uint)(i)] << std::endl;
        }
        if(!flag_worked){
            throw std::invalid_argument("the eliminated player already back in the game!!!");
        }
    }

    std::string Contessa::role(){
        start_game();
        return "Contessa";
    }
}