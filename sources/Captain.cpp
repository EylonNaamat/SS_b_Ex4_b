//
// Created by eylon on 4/26/22.
//
#include "Captain.hpp"
namespace coup{
    void Captain::steal(Player& player){
        is_num_players_legal();
        start_game();
        if(this->game->turn() != this->name){
            throw std::invalid_argument("it is not your turn!!!");
        }
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(!is_in_the_game(player)){
            throw std::invalid_argument("the player not in the game!!!");
        }
        if(this->num_coins >= coup::Captain::max_coins){
            throw std::invalid_argument("must coup!!!");
        }
        if(player.num_coins == 0){
            throw std::invalid_argument("player doesnt have enough coins!!!");
        }
        if(player.num_coins == 1){
            this->num_coins += 1;
            player.num_coins -= 1;
            this->last_operation = "steal1";
        }else{
            this->num_coins += 2;
            player.num_coins -= 2;
            this->last_operation = "steal";
        }
        this->stole_from = &player;
        this->game->whose_turn();
    }

    void Captain::block(Player& player){
        is_num_players_legal();
        start_game();
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(!is_in_the_game(player)){
            throw std::invalid_argument("the player not in the game!!!");
        }
        if(player.last_operation != "steal" && player.last_operation != "steal1"){
            throw std::invalid_argument("cant block this operation!!!");
        }
        if(this->game->turn() == player.name){
            throw std::invalid_argument("cant block him its his turn!!!");
        }
        if(player.last_operation == "steal"){
            player.num_coins -= 2;
            player.stole_from->num_coins += 2;
        }else{
            player.num_coins -= 1;
            player.stole_from->num_coins += 1;
        }
        this->last_operation = "block";
    }

    std::string Captain::role(){
        start_game();
        return "Captain";
    }
}