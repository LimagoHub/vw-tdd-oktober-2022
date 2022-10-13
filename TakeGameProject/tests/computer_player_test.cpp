//
// Created by JoachimWagner on 13.10.2022.
//

#include "computer_player_test.h"

TEST_P(computer_player_parameter_test, do_turn__happy_day){
    EXPECT_EQ(result,object_under_test.do_turn(param));
}

INSTANTIATE_TEST_SUITE_P(
        DoTurnHappyDayParameterTests,
        computer_player_parameter_test,
        testing::Values(std::make_pair(20, 3), std::make_pair(21, 1), std::make_pair(22, 1), std::make_pair(23, 2))
);