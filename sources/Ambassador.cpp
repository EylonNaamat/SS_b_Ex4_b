//
// Created by eylon on 4/26/22.
//
#include "Ambassador.hpp"
namespace coup{
    /**
     * this function transfers 1 coin from one player to another
     * first we check if the number of players is between 2-6, if not throw exception
     * then, we check if the game has already started, if not we change the flag to true
     * we check if its the players turn, if not throw exception
     * check if the players are on the same game, else throw exception
     * we check if the players are on the same game, if not throw exception
     * we check if one of the players has already been eliminated from the game, if so throw exception
     * we check if the number of coins is 10 or more, if its we throw exception because the player must coup
     * if the first player dont have enough coins (less than 1) we throw exception
     * we change the number of coins for both players and change the last operation
     * @param player_a
     * @param player_b
     */
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

    /**
     * this function blocks the steal operation
     * first we check if the number of players is between 2-6, if not throw exception
     * check if the players are on the same game, else throw exception
     * we check if the players are on the same game, if not throw exception
     * we check if one of the players has already been eliminated from the game, if so throw exception
     * if the players last operation isnt steal or steal1 we throw exception, because we cant block other operations
     * then, we check if the player stole 1 coins or 2
     * and update the number of coins according to it
     * @param player
     */
    void Ambassador::block(Player& player){
        is_num_players_legal();
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
        player.last_operation = "blocked";
    }

    /**
     * this function is a virtual function, it returns the role of ambassador which is ambassador
     * @return
     */
    std::string Ambassador::role(){
        start_game();
        return "Ambassador";
    }
}
