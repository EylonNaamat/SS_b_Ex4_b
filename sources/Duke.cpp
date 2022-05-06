//
// Created by eylon on 4/26/22.
//

#include "Duke.hpp"
#include <stdexcept>

namespace coup{
    void Duke::tax(){
        is_num_players_legal();
        start_game();
        if(this->game->turn() != this->name){
            throw std::invalid_argument("it is not your turn!!!");
        }
        if(this->num_coins >= coup::Duke::max_coins){
            throw std::invalid_argument("must coup!!!");
        }
        this->num_coins += 3;
        this->last_operation = "tax";
        this->game->whose_turn();
    }
    void Duke::block(Player& player){
        is_num_players_legal();
        start_game();
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(!is_in_the_game(player)){
            throw std::invalid_argument("the player not in the game!!!");
        }
        if(player.last_operation != "foreign_aid"){
            throw std::invalid_argument("cant block this operation!!!");
        }
        if(this->game->turn() == player.name){
            throw std::invalid_argument("cant block him its his turn!!!");
        }
        player.num_coins -= 2;
        this->last_operation = "block";
    }

    std::string Duke::role(){
        start_game();
        return "Duke";
    }
}