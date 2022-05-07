//
// Created by eylon on 4/26/22.
//
#include "Assassin.hpp"
namespace coup{
    /**
     * this function is a virtual function, if the assassin has 7 or more coins he makes regular coup, if he has less
     * he makes coup with 3 coins which can be blocked by contessa
     * first we check if the number of players is between 2-6, if not throw exception
     * then, we check if the game has already started, if not we change the flag to true
     * we check if its the players turn, if not throw exception
     * check if the players are on the same game, else throw exception
     * we check if the player has already been eliminated from the game, if so throw exception
     * we check if the number of coins is less than 3, if its we throw exception because the player cant coup
     * then we eliminate the player from the game by adding "_" as its first char
     * then we check if the assassin has more than 7 coins, if so its a regular coup
     * if not we make an assassin coup which can be blocked by contessa
     * @param player
     */
    void Assassin::coup(Player& player){
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
        if(this->num_coins < coup::Assassin::assassin_coup_coins){
            throw std::invalid_argument("dont have enough coins to coup!!!");
        }
        bool flag_eliminated = true;
        for(int i = 0; i < this->game->curr_players.size(); ++i){
            if(this->game->curr_players[(uint)(i)] == player.name){
                this->eliminated_player = player.name;
                this->game->curr_players[(uint)(i)].insert(0,"_");
                flag_eliminated = false;
                break;
            }
        }
        if(flag_eliminated){
            throw std::invalid_argument("player already eliminated!!!");
        }
        this->game->whose_turn();
        if(this->num_coins >= coup::Assassin::coup_coins){
            this->num_coins -= coup::Assassin::coup_coins;
            this->last_operation = "coup";
        }else{
            this->num_coins -= coup::Assassin::assassin_coup_coins;
            this->last_operation = "assassin_coup";
        }
        this->game->num_players--;
    }

    /**
     * this function is a virtual function, it returns the role of assassin which is assassin
     * @return
     */
    std::string Assassin::role(){
        start_game();
        return "Assassin";
    }
}