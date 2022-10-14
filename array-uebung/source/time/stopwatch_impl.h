//
// Created by JoachimWagner on 14.10.2022.
//

#pragma once


#include <chrono>
#include "stopwatch.h"
namespace vw::time {
    class stopwatch_impl : public stopwatch {
    public:
        auto start() -> void override;

        auto stop() -> void override;

        auto elapsedDuration() -> std::chrono::milliseconds override;

    private:
        std::chrono::steady_clock::time_point startTime_;
        std::chrono::steady_clock::time_point endTime_;
    };

}


