//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include <iostream>
#include "../game.h"

class take_game_impl :public game{

    int stones;
    int move;

    void execute_rounds() {
        spielerzug();
        computerzug();
    }
    void spielerzug() {

        if(is_gameover())  return;


        while(true) {
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
            std::cin >> move;
            if(move >= 1 && move <= 3)
                break;
            std::cout << "Ungueltiger Zug" << std::endl;
        }
        terminate_move("Human");

    }

    void computerzug() {

        if(is_gameover())
            return;

        const int moves[] = {3,1,1,2};

        move = moves[stones % 4];
        std::cout << "Computer nimmt " << move << " Steine." << std::endl;
        terminate_move( "Computer");

    }

    void terminate_move(std::string player) {
        update_board();
        write_game_over_message_if_game_is_over(player);
    }

    void write_game_over_message_if_game_is_over(const std::string &player) {
        if(is_gameover()) {
            std::cout << "Player " << player << " hat verloren." << std::endl;
        }
    }

    void update_board() { stones -= move; }

    bool is_gameover() {
        return stones < 1;
    }
public:
    take_game_impl():stones(23) {

    }

    void play() override {
        while ( !is_gameover()) {
            execute_rounds();
        }
    }


};




