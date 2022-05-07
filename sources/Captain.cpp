//
// Created by eylon on 4/26/22.
//
#include "Captain.hpp"
namespace coup{
    /**
     * this function steal 2 coins from other player, if he dont have 2 coins he steals 1 coin, can be blocked by captain
     * or by an ambassador
     * first we check if the number of players is between 2-6, if not throw exception
     * then, we check if the game has already started, if not we change the flag to true
     * we check if its the players turn, if not throw exception
     * check if the players are on the same game, else throw exception
     * we check if the player has already been eliminated from the game, if so throw exception
     * we check if the number of coins is 10 or more, if its 10 or more we throw exception because the player must coup
     * we check if the player has enough coins if not throw exception
     * then, we check how many coins we can steal from the player and update the number of coins and last operation according to it
     * @param player
     */
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

    /**
     * this function blocks the steal operation
     * first we check if the number of players is between 2-6, if not throw exception
     * check if the players are on the same game, else throw exception
     * we check if the players are on the same game, if not throw exception
     * we check if the player has already been eliminated from the game, if so throw exception
     * if the players last operation isnt steal or steal1 we throw exception, because we cant block other operations
     * then, we check if the player stole 1 coins or 2
     * and update the number of coins according to it
     * @param player
     */
    void Captain::block(Player& player){
        is_num_players_legal();
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
        player.last_operation = "blocked";
    }

    /**
     * this function is a virtual function, it returns the role of captain which is captain
     * @return
     */
    std::string Captain::role(){
        start_game();
        return "Captain";
    }
}