//
// Created by eylon on 4/26/22.
//
#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    /**
     * this function adds 1 coin to the player
     * first we check if the number of players is between 2-6, if not throw exception
     * then, we check if the game has already started, if not we change the flag to true
     * we check if the number of coins is 10 or more, if its 10 or more we throw exception because the player must coup
     * we check if its the players turn, if not trow exception
     * then adds 1 coin to the players coins and change the last operation to "income"
     * and promote the turn index
     */
    void Player::income(){
        is_num_players_legal();
        start_game();
        if(this->game->turn() != this->name){
            throw std::invalid_argument("it is not your turn!!!");
        }
        if(this->num_coins >= coup::Player::max_coins){
            throw std::invalid_argument("must coup!!!");
        }
        this->num_coins += 1;
        this->last_operation = "income";
        this->game->whose_turn();
    }

    /**
     * this function adds 2 coins to the player
     * first we check if the number of players is between 2-6, if not throw exception
     * then, we check if the game has already started, if not we change the flag to true
     * we check if the number of coins is 10 or more, if its 10 or more we throw exception because the player must coup
     * we check if its the players turn, if not trow exception
     * then adds 2 coins to the players coins and change the last operation to "foreign_aid"
     * and promote the turn index
     */
    void Player::foreign_aid(){
        is_num_players_legal();
        start_game();
        if(this->game->turn() != this->name){
            throw std::invalid_argument("it is not your turn!!!");
        }
        if(this->num_coins >= coup::Player::max_coins){
            throw std::invalid_argument("must coup!!!");
        }
        this->num_coins += 2;
        this->last_operation = "foreign_aid";
        this->game->whose_turn();
    }
    /**
     * this function returns the role, its a virtual function so other players return different roles
     * @return
     */
    std::string Player::role(){
        start_game();
        return "Player";
    }

    /**
     * this function eliminates a players from the game
     * first we check if the number of players is between 2-6, if not throw exception
     * then, we check if the game has already started, if not we change the flag to true
     * we check if its the players turn, if not throw exception
     * check if the players are on the same game, else throw exception
     * we check if the player has already been eliminated from the game, if so throw exception
     * we check if the number of coins is 7 or more, if its less we throw exception because the player dont have enough money
     * we go through the list of players and search for the players name
     * we add "_" as the first char
     * we update the last operation to "coup" and updating the number of coins the player have
     * @param player
     */
    void Player::coup(Player& player){
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
        if(this->num_coins < coup::Player::coup_coins){
            throw std::invalid_argument("you dont have enough money!!!");
        }
        bool flag_eliminated = true;
        for(int i = 0; i < this->game->curr_players[(uint)(i)].size(); ++i){
            if(this->game->curr_players[(uint)(i)] == player.name){
                this->game->curr_players[(uint)(i)].insert(0,"_");
                flag_eliminated = false;
                break;
            }
        }
        if(flag_eliminated){
            throw std::invalid_argument("player already eliminated!!!");
        }
        this->game->whose_turn();
        this->last_operation = "coup";
        this->num_coins -= coup::Player::coup_coins;
        this->game->num_players--;
    }

    /**
     * this function returns the number of coins the player have
     * @return
     */
    int Player::coins() const{
        start_game();
        return this->num_coins;
    }

    /**
     * this function checks if the player is in the game
     * we go through the vector of players and if we find his name in the vector we return true, else return false
     * @param player
     * @return
     */
    bool Player::is_in_the_game(Player& player) const{
        bool is_in = false;
        for(int i = 0; i < this->game->curr_players.size(); ++i){
            if(this->game->curr_players[(uint)(i)] == player.name){
                is_in = true;
            }
        }
        return is_in;
    }

    /**
     * this function checks if the number of players is legal, throw exception if not
     */
    void Player::is_num_players_legal() const{
        if(this->game->num_players > coup::Game::max_players){
            throw std::invalid_argument("cant have more than 6 players!!!");
        }
        if(this->game->num_players < coup::Game::min_players){
            throw std::invalid_argument("cant have less than 2 players!!!");
        }
    }

    /**
     * this function determine if the game has already started or not, if the game hasnt started yet
     * it changes the flag to true
     * @return
     */
    bool Player::start_game() const{
        if(!this->game->game_has_started){
            this->game->game_has_started = true;
            return true;
        }
        return false;
    }
}