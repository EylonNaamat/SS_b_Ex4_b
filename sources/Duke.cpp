//
// Created by eylon on 4/26/22.
//

#include "Duke.hpp"
namespace coup{
    /**
     * this function adds 3 coins to the duke
     * first we check if the number of players is between 2-6, if not throw exception
     * then, we check if the game has already started, if not we change the flag to true
     * we check if its the players turn, if not throw exception
     * we check if the number of coins is 10 or more, if its 10 or more we throw exception because the player must coup
     * then, we adds 3 coins to the duke and update the last operation
     */
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

    /**
     * this function blocks the foreign_aid function
     * first we check if the number of players is between 2-6, if not throw exception
     *  we check if the player has already been eliminated from the game, if so throw exception
     *  we check if the last operation is foreign_aid, if not throw exception
     *  we update the number of coins and the last operation
     * @param player
     */
    void Duke::block(Player& player){
        is_num_players_legal();
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
        player.last_operation = "blocked";
    }

    /**
     * this function is a virtual function, it returns the role of duke which is duke
     * @return
     */
    std::string Duke::role(){
        start_game();
        return "Duke";
    }
}