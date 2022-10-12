//
// Created by JoachimWagner on 12.10.2022.
//

#pragma once
#include <iostream>
#include "../game.h"

class take_game_impl :public game{

    int stones;
    bool gameover;

    void execute_rounds() {
        spielerzug();
        computerzug();
    }
    void spielerzug() {
        int move;
        while(true) {
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
            std::cin >> move;
            if(move >= 1 && move <= 3)
                break;
            std::cout << "Ungueltiger Zug" << std::endl;
        }
        stones -= move;
    }

    void computerzug() {
        const int moves[] = {3,1,1,2};
        if(stones < 1) {
            std::cout << " Du Loser" << std::endl;
            gameover = true;
            return ;
        }
        if(stones == 1) {
            std::cout << " Du hast nur Glueck gehabt" << std::endl;
            gameover = true;
            return ;
        }
        int move = moves[stones % 4];
        std::cout << "Computer nimmt " << move << " Steine." << std::endl;
        stones -= move;
    }
public:
    take_game_impl():stones(23),gameover(false) {

    }

    void play() override {
        while ( !gameover) {
            execute_rounds();
        }
    }


};




