#include <iostream>
#include "source/games/take_game/take_game_impl.h"
#include "source/clients/game_client.h"
#include "source/games/take_game/players/human_player.h"
#include "source/games/take_game/players/computer_player.h"

int main() {
    take_game_impl game_;
    human_player human{"Mensch"};
    computer_player computer{"computer"};
    game_.addPlayer(&human);
    game_.addPlayer(&computer);
    game_client client(game_);
    client.go();

    return 0;
}
