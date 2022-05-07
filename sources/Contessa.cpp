//
// Created by eylon on 4/26/22.
//
#include "Contessa.hpp"
namespace coup{
    /**
     * this function blocks the assassins coup
     * first we check if the number of players is between 2-6, if not throw exception
     * check if the players are on the same game, else throw exception
     * we check if the players are on the same game, if not throw exception
     * we check if one of the players has already been eliminated from the game, if so throw exception
     * we check if the last operation is assassin_coup, if not throw exception
     * we go through the vector of names, and checks if we find a name that matches the name we got
     * if so we remove the "_" char
     * @param player
     */
    void Contessa::block(Player& player){
        is_num_players_legal();
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
        for(int i = 0; i < this->game->curr_players.size(); ++i){
            std::string tmp = this->game->curr_players[(uint)(i)];
            tmp.erase(0, 1);
            if(tmp == player.eliminated_player){
                this->game->curr_players[(uint)(i)] = player.eliminated_player;
                flag_worked = true;
                this->game->num_players++;
            }
        }
        if(!flag_worked){
            throw std::invalid_argument("the eliminated player already back in the game!!!");
        }
        this->last_operation = "block";
        player.last_operation = "blocked";
    }

    /**
     * this function is a virtual function, it returns the role of contessa which is contessa
     * @return
     */
    std::string Contessa::role(){
        start_game();
        return "Contessa";
    }
}