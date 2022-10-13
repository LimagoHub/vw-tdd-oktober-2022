//
// Created by JoachimWagner on 13.10.2022.
//
#include "gtest/gtest.h"
#include "../source/games/take_game/players/computer_player.h"

#pragma once

using namespace testing;
class computer_player_test: public Test
{
protected:
    computer_player object_under_test{"Fritz"};
};


class computer_player_parameter_test : public computer_player_test, public WithParamInterface<std::pair<int, int>>
{


protected:
    int param;
    int result;

    void SetUp() override
    {
        std::tie<int, int>(param, result) = GetParam();
    }
};





