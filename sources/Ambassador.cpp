//
// Created by eylon on 4/26/22.
//
#include "Ambassador.hpp"
namespace coup{
    void Ambassador::transfer(Player& player_a, Player& player_b){
        is_num_players_legal();
        start_game();
        if(this->game->turn() != this->name){
            throw std::invalid_argument("it is not your turn!!!");
        }
        if(player_a.game != player_b.game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(this->game != player_a.game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(!is_in_the_game(player_a) || !is_in_the_game(player_b)){
            throw std::invalid_argument("at least one of the players not in the game");
        }
        if(this->num_coins >= coup::Ambassador::max_coins){
            throw std::invalid_argument("must coup!!!");
        }
        if(player_a.num_coins < 1){
            throw std::invalid_argument("player a dont have enough money!!!");
        }

        player_a.num_coins -= 1;
        player_b.num_coins += 1;
        this->last_operation = "transfer";
        this->game->whose_turn();
    }

    void Ambassador::block(Player& player){
        is_num_players_legal();
        start_game();
        if(player.game != this->game){
            throw std::invalid_argument("the players arent in the same game!!!");
        }
        if(player.last_operation != "steal" && player.last_operation != "steal1"){
            throw std::invalid_argument("cant block this operation!!!");
        }
        if(!is_in_the_game(player)){
            throw std::invalid_argument("the player not in the game!!!");
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

    std::string Ambassador::role(){
        start_game();
        return "Ambassador";
    }
}
