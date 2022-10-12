//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include "game.h"
#include "players/player.h"
template<class BOARD, class MOVE>
class abstract_game :public game{
    std::vector<player<BOARD,MOVE>  *> players;
    BOARD board;
    MOVE move;

    player<BOARD,MOVE> *current_player;


    void setCurrentPlayer(player<BOARD,MOVE> *currentPlayer) {
        current_player = currentPlayer;
    }
private:

    void execute_rounds() {
        for(auto player: players) {
            setCurrentPlayer(player);
            execute_single_move();
        }
    }

    void execute_single_move() {

        if(is_gameover())  return;
        execute_move();
        terminate_move();

    }

    void execute_move()  {
        do {
            move = getCurrentPlayer()->do_turn(board);

        } while(players_move_is_invalid());
    }

    bool players_move_is_invalid() {
        if(is_move_valid()) return false;
        std::cout << "Ungueltiger Zug" << std::endl;
        return true;
    }

    void terminate_move() {
        update_board();
        write_game_over_message_if_game_is_over();
    }

    void write_game_over_message_if_game_is_over() {
        if(is_gameover()) {
            std::cout << "Player " << getCurrentPlayer()->getName() << " hat verloren." << std::endl;
        }
    }
protected:
    player<BOARD,MOVE> *getCurrentPlayer() const {
        return current_player;
    }




protected:

public:
    const std::vector<player<BOARD, MOVE> *> &getPlayers() const {
        return players;
    }

protected:
    BOARD getBoard() const {
        return board;
    }

    void setBoard(BOARD board) {
        abstract_game::board = board;
    }

    MOVE getMove() const {
        return move;
    }

    void setMove(MOVE move) {
        abstract_game::move = move;
    }


    virtual bool is_move_valid() const = 0;

    virtual void update_board() = 0;

    virtual bool is_gameover() const = 0;

public:

    void addPlayer(player<BOARD,MOVE> *player){
        players.push_back(player);
    }

    void play() override {
        while ( !is_gameover()) {
            execute_rounds();
        }
    }
};




